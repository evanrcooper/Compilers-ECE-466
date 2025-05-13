%{
    #include "parser.tab.h"
    int yylex(void);
    extern FILE *yyin;
    struct symbol_table_dll_node *CURRENT_SCOPE;
    struct type_builder CURRENT_TYPE_BUILDER = {0};
    int CURRENT_STORAGE_CLASS = 0;
%}

%code requires {
    #include "ast.h"
    #include "../SymbolTable/sym_tab.h"
    #include <stdio.h>
    #include <stdlib.h>
    int yyerror(const char *s);
}

%define parse.trace

%union {
    char *str_val;
    long long int_val;
    long double real_val;
    char char_val;
    D_STRING d_str_val;
    ast_node* node;
}

%token IDENT NUMLIT CHARLIT STRLIT FLOATLIT
%token PLUSPLUS MINUSMINUS
%token INDSEL
%token SHL SHR
%token GEQ LEQ EQEQ NEQ
%token LOGAND LOGOR
%token TIMESEQ PLUSEQ XOREQ MINUSEQ DIVEQ MODEQ SHLEQ SHREQ ANDEQ OREQ

%token ELLIPSIS
%token CASE
%token CONST
%token DEFAULT
%token DOUBLE
%token ENUM
%token FLOAT
%token INLINE
%token RESTRICT
%token STRUCT
%token SWITCH
%token TYPEDEF
%token UNION
%token VOLATILE
%token _BOOL
%token _COMPLEX
%token _IMAGINARY

%token AUTO
%token BREAK
%token CHAR
%token CONTINUE
%token DO
%token ELSE
%token EXTERN
%token FOR
%token GOTO
%token IF
%token INT
%token LONG
%token REGISTER
%token RETURN
%token SHORT
%token SIGNED
%token SIZEOF
%token STATIC
%token UNSIGNED
%token VOID
%token WHILE

%type <node> primary-expression 
%type <node> postfix-expression 
%type <node> unary-expression
%type <node> cast-expression
%type <node> multiplicative-expression
%type <node> additive-expression
%type <node> shift-expression
%type <node> relational-expression
%type <node> equality-expression
%type <node> bitand-expression
%type <node> bitxor-expression
%type <node> bitor-expression
%type <node> logand-expression
%type <node> logor-expression
%type <node> conditional-expression
%type <node> assignment-expression
%type <node> expression
%type <node> constant-expression
%type <node> ident-expr
%type <node> numlit-expr
%type <node> pointer
%type <node> direct-declarator
%type <node> declarator-list
%type <node> type-specifier
%type <node> storage-class-specifier
%type <node> declarator
%type <node> declaration-specifiers
%type <node> declaration
%type <node> type-specifier-list
%type <node> expression-opt
%type <node> direct-abstract-declarator
%type <node> abstract-declarator
%type <node> iteration-statement
%type <node> jump-statement
%type <node> block-item
%type <node> block-item-list
%type <node> compound-statement
%type <node> expression-statement
%type <node> function-definition
%type <node> external-declaration
%type <node> labeled-statement
%type <node> statement
%type <node> type-name
%type <node> selection-statement
%type <node> compound-body
%type <node> compound-start
%type <node> program

%%

/* C-99 Standard: http://faculty.cooper.edu/hak/ece466/n1124.pdf */
/* See Page 415 */

/* 6.5 EXPRESSIONS */

program:
    /* empty */
    /* | program function-definition */
    | program external-declaration {print_ast_tree($2);}

ident-expr:
    IDENT {
        ast_node *ident_node = calloc(1, sizeof(ast_node));
        ident_node->node_type = AST_IDENT;
        ident_node->val.ident.ident_name = strdup(yylval.str_val);
        ident_node->val.ident.symbol = find_symbol_in_scope(ident_node->val.ident.ident_name, CURRENT_SCOPE);

        if (!ident_node->val.ident.symbol) {
            printf("Warning: unresolved identifier '%s'\n", ident_node->val.ident.ident_name);
        }

        $$ = ident_node;
    }

numlit-expr:
    NUMLIT {
        ast_node *numlit_node = calloc(1, sizeof(ast_node));
        numlit_node->node_type = AST_NUMLIT;
        numlit_node->val.numlit.val.int_val = yylval.int_val;
        numlit_node->val.numlit.type = N_LLI;
        $$ = numlit_node;
    }

primary-expression:
    ident-expr {$$ = $1;}
    | numlit-expr {
        $$ = $1;
    }
    | FLOATLIT {
        ast_node *flit_node = calloc(1, sizeof(ast_node));
        flit_node->node_type = AST_NUMLIT;
        flit_node->val.numlit.val.real_val = yylval.real_val;
        flit_node->val.numlit.type = N_LLF;
        $$ = flit_node;
    }
    | CHARLIT {
        ast_node *charlit_node = calloc(1, sizeof(ast_node));
        charlit_node->node_type = AST_CHARLIT;
        charlit_node->val.charlit.val = yylval.char_val;
        $$ = charlit_node;
    }
    | STRLIT {
        ast_node *strlit_node = calloc(1, sizeof(ast_node));
        strlit_node->node_type = AST_STRLIT;
        strlit_node->val.strlit.val = yylval.d_str_val.str_val;
        strlit_node->val.strlit.len = yylval.d_str_val.str_len;
        $$ = strlit_node;
    }
    | '(' expression ')' {$$ = $2;}

postfix-expression:
    primary-expression {$$ = $1;}
    | postfix-expression '[' expression ']' {$$ = create_unop_node(U_DEREF, create_binop_node(B_PLUS, $1, $3));}
    | postfix-expression '(' ')' {
        if ($1->node_type != AST_IDENT) {
            yyerror("Impossible Function Call");
        }
        struct symbol_table_entry_ll_node *entry = find_symbol_in_scope($1->val.ident.ident_name, CURRENT_SCOPE);
        free($1);
        if (!entry) {
            yyerror("Unresolved Function Call");
        }
        ast_node *node = calloc(1, sizeof(ast_node));
        node->node_type = AST_FUNCTION_CALL;
        node->val.function_call.fn = entry;
        $$ = node;
    }
    | postfix-expression INDSEL ident-expr {$$ = create_binop_node(B_INDSEL, $1, $3);}
    | postfix-expression PLUSPLUS {$$ = create_unop_node(U_POST_PLUSPLUS, $1);}
    | postfix-expression MINUSMINUS {$$ = create_unop_node(U_POST_MINUSMINUS, $1);}


unary-expression:
    postfix-expression {$$ = $1;}
    | PLUSPLUS unary-expression {$$ = create_unop_node(U_PRE_PLUSPLUS, $2);}
    | MINUSMINUS unary-expression {$$ = create_unop_node(U_PRE_MINUSMINUS, $2);}
    | '&' cast-expression {$$ = create_unop_node(U_ADDRESSOF, $2);}
    | '*' cast-expression {$$ = create_unop_node(U_DEREF, $2);}
    | '+' cast-expression {$$ = create_unop_node(U_POS, $2);}
    | '-' cast-expression {$$ = create_unop_node(U_NEG, $2);}
    | '~' cast-expression {$$ = create_unop_node(U_BIT_NOT, $2);}
    | '!' cast-expression {$$ = create_unop_node(U_NOT, $2);}
    | SIZEOF unary-expression {$$ = create_unop_node(U_SIZEOF_EXPRESSION, $2);}
    /* | SIZEOF '(' type-name ')' {$$ = create_unop_node(U_SIZEOF_TYPENAME, $3);} */

cast-expression:
    unary-expression {$$ = $1;}
    /* | '(' type-name ')' cast-expression {$$ = create_binop_node(B_TYPECAST, $2, $4);} */

multiplicative-expression:
    cast-expression {$$ = $1;}
    | multiplicative-expression '*' cast-expression {$$ = create_binop_node(B_TIMES, $1, $3);}
    | multiplicative-expression '/' cast-expression {$$ = create_binop_node(B_DIVIDE, $1, $3);}
    | multiplicative-expression '%' cast-expression {$$ = create_binop_node(B_MOD, $1, $3);}

additive-expression:
    multiplicative-expression {$$ = $1;}
    | additive-expression '+' multiplicative-expression {$$ = create_binop_node(B_PLUS, $1, $3);}
    | additive-expression '-' multiplicative-expression {$$ = create_binop_node(B_MINUS, $1, $3);}

shift-expression:
    additive-expression {$$ = $1;}
    | shift-expression SHL additive-expression {$$ = create_binop_node(B_SHL, $1, $3);}
    | shift-expression SHR additive-expression {$$ = create_binop_node(B_SHR, $1, $3);}

relational-expression:
    shift-expression {$$ = $1;}
    | relational-expression '<' shift-expression {$$ = create_binop_node(B_LT, $1, $3);}
    | relational-expression '>' shift-expression {$$ = create_binop_node(B_GT, $1, $3);}
    | relational-expression LEQ shift-expression {$$ = create_binop_node(B_LTEQ, $1, $3);}
    | relational-expression GEQ shift-expression {$$ = create_binop_node(B_GTEQ, $1, $3);}

equality-expression:
    relational-expression {$$ = $1;}
    | equality-expression EQEQ relational-expression {$$ = create_binop_node(B_EQEQ, $1, $3);}
    | equality-expression NEQ relational-expression {$$ = create_binop_node(B_NOTEQ, $1, $3);}

bitand-expression: /* AND-expression */
    equality-expression {$$ = $1;}
    | bitand-expression '&' equality-expression {$$ = create_binop_node(B_BIT_AND, $1, $3);}

bitxor-expression: /* exclusive-OR-expression */
    bitand-expression {$$ = $1;}
    | bitxor-expression '^' bitand-expression {$$ = create_binop_node(B_BIT_XOR, $1, $3);}

bitor-expression: /* inclusive-OR-expression */
    bitxor-expression {$$ = $1;}
    | bitor-expression '|' bitxor-expression {$$ = create_binop_node(B_BIT_OR, $1, $3);}

logand-expression: /* logical-AND-expression */
    bitor-expression {$$ = $1;}
    | logand-expression LOGAND bitor-expression {$$ = create_binop_node(B_LOG_AND, $1, $3);}

logor-expression: /* logical-OR-expression */
    logand-expression {$$ = $1;}
    | logor-expression LOGOR logand-expression {$$ = create_binop_node(B_LOG_OR, $1, $3);}

conditional-expression:
    logor-expression {$$ = $1;}
    | logor-expression '?' expression ':' conditional-expression {$$ = create_triop_node(T_TERNARY, $1, $3, $5);}

assignment-expression:
    conditional-expression {$$ = $1;}
    | unary-expression '=' assignment-expression {$$ = create_binop_node(B_EQ, $1, $3);}
    | unary-expression TIMESEQ assignment-expression {$$ = create_binop_node(B_TIMESEQ, $1, $3);}
    | unary-expression DIVEQ assignment-expression {$$ = create_binop_node(B_DIVEQ, $1, $3);}
    | unary-expression MODEQ assignment-expression {$$ = create_binop_node(B_MODEQ, $1, $3);}
    | unary-expression PLUSEQ assignment-expression {$$ = create_binop_node(B_PLUSEQ, $1, $3);}
    | unary-expression MINUSEQ assignment-expression {$$ = create_binop_node(B_MINUSEQ, $1, $3);}
    | unary-expression SHLEQ assignment-expression {$$ = create_binop_node(B_SHLEQ, $1, $3);}
    | unary-expression SHREQ assignment-expression {$$ = create_binop_node(B_SHREQ, $1, $3);}
    | unary-expression ANDEQ assignment-expression {$$ = create_binop_node(B_BIT_ANDEQ, $1, $3);}
    | unary-expression OREQ assignment-expression {$$ = create_binop_node(B_BIT_OREQ, $1, $3);}
    | unary-expression XOREQ assignment-expression {$$ = create_binop_node(B_BIT_XOREQ, $1, $3);}

expression:
    assignment-expression {$$ = $1;}
    | expression ',' assignment-expression {$$ = create_binop_node(B_COMMA, $1, $3);}

/* 6.6 CONSTANT EXPRESSIONS */
constant-expression:
    conditional-expression {$$ = $1;}

/* 6.7 DECLARATORS */

declaration:
    declaration-specifiers declarator-list ';' {
        if (!$2) {
            yyerror("no declarator provided");
        }

        ast_node *current_declarator_comma_node = $2;

        // Process all comma-separated declarators except the final one
        while (current_declarator_comma_node->val.binop.left) {
            ast_node *current_declarator = current_declarator_comma_node->val.binop.right;

            while (current_declarator->node_type != AST_IDENT) {
                switch (current_declarator->node_type) {
                    case AST_UNOP:
                        current_declarator = current_declarator->val.unop.center;
                        break;
                    case AST_TYPE_MOD:
                        current_declarator = current_declarator->val.type_mod.next;
                        break;
                    default:
                        yyerror("unknown AST node in declarator traversal");
                }
            }

            int CURRENT_SYMBOL_SCOPE = 0;
            switch (CURRENT_SCOPE->scope) {
                case TABLE_GLOBAL:
                    CURRENT_SYMBOL_SCOPE = SYM_GLOBAL;
                    if (CURRENT_STORAGE_CLASS == SC_AUTO || CURRENT_STORAGE_CLASS == SC_REGISTER) {
                        yyerror("storage class not allowed in global scope");
                    } else if (!CURRENT_STORAGE_CLASS) {
                        CURRENT_STORAGE_CLASS = SC_EXTERN_IMPLICIT;
                    }
                    break;
                case TABLE_FUNCTION:
                case TABLE_BLOCK:
                    CURRENT_SYMBOL_SCOPE = CURRENT_STORAGE_CLASS ? SC_AUTO : CURRENT_STORAGE_CLASS;
                    break;
                default:
                    yyerror("unrecognized table scope");
            }

            struct symbol_table_entry_ll_node *node = insert_symbol_var(current_declarator->val.ident.ident_name, CURRENT_SYMBOL_SCOPE, CURRENT_STORAGE_CLASS);
            node->specs.variable.is_defined = 1;
            node->specs.variable.type = build_full_type_from_declarator(current_declarator, &CURRENT_TYPE_BUILDER);

            current_declarator_comma_node = current_declarator_comma_node->val.binop.left;
        }

        // Handle the final (leftmost) declarator (left == NULL)
        ast_node *first_declarator = current_declarator_comma_node->val.binop.right;
        while (first_declarator->node_type != AST_IDENT) {
            switch (first_declarator->node_type) {
                case AST_UNOP:
                    first_declarator = first_declarator->val.unop.center;
                    break;
                case AST_TYPE_MOD:
                    first_declarator = first_declarator->val.type_mod.next;
                    break;
                default:
                    yyerror("unknown AST node in final declarator traversal");
            }
        }

        int CURRENT_SYMBOL_SCOPE = 0;
        switch (CURRENT_SCOPE->scope) {
            case TABLE_GLOBAL:
                CURRENT_SYMBOL_SCOPE = SYM_GLOBAL;
                if (CURRENT_STORAGE_CLASS == SC_AUTO || CURRENT_STORAGE_CLASS == SC_REGISTER) {
                    yyerror("storage class not allowed in global scope");
                } else if (!CURRENT_STORAGE_CLASS) {
                    CURRENT_STORAGE_CLASS = SC_EXTERN_IMPLICIT;
                }
                break;
            case TABLE_FUNCTION:
            case TABLE_BLOCK:
                CURRENT_SYMBOL_SCOPE = CURRENT_STORAGE_CLASS ? SC_AUTO : CURRENT_STORAGE_CLASS;
                break;
            default:
                yyerror("unrecognized table scope");
        }

        struct symbol_table_entry_ll_node *first_node = insert_symbol_var(first_declarator->val.ident.ident_name, CURRENT_SYMBOL_SCOPE, CURRENT_STORAGE_CLASS);
        first_node->specs.variable.is_defined = 1;
        first_node->specs.variable.type = build_full_type_from_declarator(first_declarator, &CURRENT_TYPE_BUILDER);

        reset_current_type_builder();
        CURRENT_STORAGE_CLASS = 0;
    }


declaration-specifiers:
    storage-class-specifier declaration-specifiers {$$ = NULL;}
    | storage-class-specifier {$$ = NULL;}
    | type-specifier-list declaration-specifiers {$$ = NULL;}
    | type-specifier-list {$$ = NULL;}

declarator-list:
    declarator {$$ = create_binop_node(B_COMMA, NULL, $1);}
    | declarator-list ',' declarator {$$ = create_binop_node(B_COMMA, $1, $3);}

storage-class-specifier:
    EXTERN {
        if (CURRENT_STORAGE_CLASS) {
            yyerror("conflicting storage classes");
        }
        CURRENT_STORAGE_CLASS = SC_EXTERN_EXPLICIT;
        $$ = NULL;
    }
    | STATIC {
        if (CURRENT_STORAGE_CLASS) {
            yyerror("conflicting storage classes");
        }
        CURRENT_STORAGE_CLASS = SC_REGISTER;
        $$ = NULL;
    }
    | AUTO {
        if (CURRENT_STORAGE_CLASS) {
            yyerror("conflicting storage classes");
        }
        CURRENT_STORAGE_CLASS = SC_AUTO;
        $$ = NULL;
    }
    | REGISTER {
        if (CURRENT_STORAGE_CLASS) {
            yyerror("conflicting storage classes");
        }
        CURRENT_STORAGE_CLASS = SC_REGISTER;
        $$ = NULL;
    }

type-specifier:
    CHAR {
        if (CURRENT_TYPE_BUILDER.is_void) {
            yyerror("conflict between 'char' and 'void' specifiers");
        } else if (CURRENT_TYPE_BUILDER.is_char) {
            yyerror("too many 'char' specifiers");
        } else if (CURRENT_TYPE_BUILDER.is_int) {
            yyerror("conflict between 'char' and 'int' specifiers");
        }
        CURRENT_TYPE_BUILDER.is_char = 1;
        $$ = NULL;
    }
    | INT {
        if (CURRENT_TYPE_BUILDER.is_void) {
            yyerror("conflict between 'int' and 'void' specifiers");
        } else if (CURRENT_TYPE_BUILDER.is_int) {
            yyerror("too many 'int' specifiers");
        } else if (CURRENT_TYPE_BUILDER.is_char) {
            yyerror("conflict between 'int' and 'char' specifiers");
        }
        CURRENT_TYPE_BUILDER.is_int = 1;
        $$ = NULL;
    }
    | SHORT {
        if (CURRENT_TYPE_BUILDER.is_void) {
            yyerror("conflict between 'short' and 'void' specifiers");
        } else if (CURRENT_TYPE_BUILDER.is_long_long) {
            yyerror("conflict between 'short' and 'long long' specifiers");
        } else if (CURRENT_TYPE_BUILDER.is_short) {
            yyerror("too many 'short' specifiers");
        } else if (CURRENT_TYPE_BUILDER.is_char) {
            yyerror("conflict between 'short' and 'char' specifiers");
        } else {
            CURRENT_TYPE_BUILDER.is_short = 1;
        }
        $$ = NULL;
    }
    | LONG {
        if (CURRENT_TYPE_BUILDER.is_void) {
            yyerror("conflict between 'long' and 'void' specifiers");
        } else if (CURRENT_TYPE_BUILDER.is_long_long) {
            yyerror("too many 'long' specifiers");
        } else if (CURRENT_TYPE_BUILDER.is_short) {
            yyerror("conflict between 'long' and 'short' specifiers");
        } else if (CURRENT_TYPE_BUILDER.is_long) {
            CURRENT_TYPE_BUILDER.is_long_long = 1;
            CURRENT_TYPE_BUILDER.is_long = 0;
        } else if (CURRENT_TYPE_BUILDER.is_char) {
            yyerror("conflict between 'long' and 'char' specifiers");
        } else {
            CURRENT_TYPE_BUILDER.is_long = 1;
        }
        $$ = NULL;
    }
    | SIGNED {
        if (CURRENT_TYPE_BUILDER.is_void) {
            yyerror("conflict between 'signed' and 'void' specifiers");
        } else if (CURRENT_TYPE_BUILDER.is_unsigned) {
            yyerror("conflict between 'signed' and 'unsigned' specifiers");
        } else if (CURRENT_TYPE_BUILDER.is_signed) {
            yyerror("too many 'signed' specifiers");
        } else {
            CURRENT_TYPE_BUILDER.is_signed = 1;
        }
        $$ = NULL;
    }
    | UNSIGNED {
        if (CURRENT_TYPE_BUILDER.is_void) {
            yyerror("conflict between 'unsigned' and 'void' specifiers");
        } else if (CURRENT_TYPE_BUILDER.is_signed) {
            yyerror("conflict between 'unsigned' and 'signed' specifiers");
        } else if (CURRENT_TYPE_BUILDER.is_unsigned) {
            yyerror("too many 'unsigned' specifiers");
        } else {
            CURRENT_TYPE_BUILDER.is_unsigned = 1;
        }
        $$ = NULL;
    }
    | VOID {
        if (CURRENT_TYPE_BUILDER.is_signed) {
            yyerror("conflict between 'void' and 'signed' specifiers");
        } else if (CURRENT_TYPE_BUILDER.is_unsigned) {
            yyerror("conflict between 'void' and 'unsigned' specifiers");
        } else if (CURRENT_TYPE_BUILDER.is_short) {
            yyerror("conflict between 'void' and 'short' specifiers");
        } else if (CURRENT_TYPE_BUILDER.is_long) {
            yyerror("conflict between 'void' and 'long' specifiers");
        } else if (CURRENT_TYPE_BUILDER.is_long_long) {
            yyerror("conflict between 'void' and 'long long' specifiers");
        } else if (CURRENT_TYPE_BUILDER.is_char) {
            yyerror("conflict between 'void' and 'char' specifiers");
        } else if (CURRENT_TYPE_BUILDER.is_int) {
            yyerror("conflict between 'void' and 'int' specifiers");
        }
        CURRENT_TYPE_BUILDER.is_void = 1;
        $$ = NULL;
    }

declarator:
    pointer direct-declarator {
        ast_node *tail = $1;
        while (tail->val.type_mod.next) {
            tail = tail->val.type_mod.next;
        }
        tail->val.type_mod.next = $2;
        $$ = $1;
    }
    | direct-declarator {$$ = $1;}

direct-declarator:
    ident-expr {$$ = $1;}
    | '(' declarator ')' {$$ = $2;}
    | direct-declarator '[' numlit-expr ']' {
        int array_size = $3->val.numlit.val.int_val;
        free($3);
        ast_node *node = create_type_modifier_node(CONSTANT_SIZED_ARRAY, array_size);
        node->val.type_mod.next = $1;
        $$ = node;
    }
    | direct-declarator '[' ']' {
        ast_node *node = create_type_modifier_node(UNSIZED_ARRAY, 0);
        node->val.type_mod.next = $1;
        $$ = node;
    }
    | direct-declarator '(' ')' {$$ = create_unop_node(U_FUNCTION_TYPE, $1);}

pointer:
    '*' {$$ = create_type_modifier_node(POINTER, 0);}
    | '*' pointer {
        ast_node *node = create_type_modifier_node(POINTER, 0);
        node->val.type_mod.next = $2;
        $$ = node;
    }

type-specifier-list:
    type-specifier {$$ = NULL;}
    | type-specifier type-specifier-list {$$ = NULL;}

type-name:
    type-specifier-list abstract-declarator {$$ = $2;}
    | type-specifier-list {$$ = NULL;}

abstract-declarator:
    pointer {$$ = $1;}
    | pointer direct-abstract-declarator {
        ast_node *tail = $1;
        while (tail->val.type_mod.next) {
            tail = tail->val.type_mod.next;
        }
        tail->val.type_mod.next = $2;
        $$ = $1;
    }
    | direct-abstract-declarator {$$ = $1;}

direct-abstract-declarator:
    '(' abstract-declarator ')' {$$ = $2;}
    | direct-abstract-declarator '[' ']' {
        ast_node *node = create_type_modifier_node(UNSIZED_ARRAY, 0);
        node->val.type_mod.next = $1;
        $$ = node;
    }
    | '[' ']' {$$ = create_type_modifier_node(UNSIZED_ARRAY, 0)}
    | direct-abstract-declarator '(' ')' {create_unop_node(U_FUNCTION_TYPE, $1);}
    | '(' ')' {$$ = create_unop_node(U_FUNCTION_TYPE, create_primitive_type_node(TYPE_VOID));}

/* 6.8 STATEMENTS AND BLOCKS */

statement:
    labeled-statement {$$ = $1;}
    | compound-statement {$$ = $1;}
    | expression-statement {$$ = $1;}
    | selection-statement {$$ = $1;}
    | iteration-statement {$$ = $1;}
    | jump-statement {$$ = $1;}

labeled-statement:
    ident-expr ':' statement {
        char *name = $1->val.ident.ident_name;
        free($1);
        int scope;
        switch (CURRENT_SCOPE->scope) {
            case TABLE_GLOBAL:
                scope = SYM_GLOBAL;
            case TABLE_FUNCTION:
                scope = SYM_LOCAL;
            case TABLE_BLOCK:
                scope = SYM_BLOCK;
            default:
                yyerror("Unknown Scope");
        }
        struct symbol_table_entry_ll_node *entry = insert_symbol_lab(name, scope);
        entry->specs.label.is_defined = 1;
        entry->specs.label.jump_loc = $3;
        $$ = $3;
    }

compound-statement:
    compound-start compound-body '}' {
        ast_node *node = calloc(1, sizeof(ast_node));
        node->node_type = AST_COMPOUND_STATEMENT;
        node->val.compound.blocks = $2;
        node->val.compound.scope = CURRENT_SCOPE;
        exit_scope();
        $$ = node;
    }
    | '{' '}' {$$ = NULL;}

compound-start:
    '{' {
        CURRENT_SCOPE = new_scope(TABLE_BLOCK);
    }

compound-body:
    block-item-list {$$ = $1;}

block-item-list:
    block-item {$$ = $1;}
    | block-item-list block-item {
        if (!$1) {
            $$ = $2;
        } else {
            ast_node *current_block = $1;
            while (current_block && current_block->node_type == AST_BLOCK && current_block->val.block.next) {
                current_block = current_block->val.block.next;
            }
            if (current_block && current_block->node_type == AST_BLOCK) {
                current_block->val.block.next = $2;
            } else {
                yyerror("block-item-list structure corrupted: non-AST_BLOCK node in .next chain");
            }
            $$ = $1;
        }
    }

block-item:
    declaration {$$ = create_block_node(NULL);}
    | statement {$$ = create_block_node($1);}

expression-statement:
    ';' {$$ = NULL;}
    | expression ';' {$$ = $1;}

selection-statement:
    IF '(' expression ')' statement {
        ast_node *node = calloc(1, sizeof(ast_node));
        node->node_type = AST_IF;
        node->val.if_statement.expression = $3;
        node->val.if_statement.statement = $5;
        node->val.if_statement.else_statement = NULL;
        $$ = node;
    }
    | IF '(' expression ')' statement ELSE statement {
        ast_node *node = calloc(1, sizeof(ast_node));
        node->node_type = AST_IF;
        node->val.if_statement.expression = $3;
        node->val.if_statement.statement = $5;
        node->val.if_statement.else_statement = $7;
        $$ = node;
    }

expression-opt:
    /* empty */ {$$ = NULL;}
    | expression {$$ = $1;}

iteration-statement:
    WHILE '(' expression ')' statement {
        ast_node *node = calloc(1, sizeof(ast_node));
        node->node_type = AST_WHILE;
        node->val.while_statement.expression = $3;
        node->val.do_while_statement.statement = $5;
        $$ = node;
    }
    | DO statement WHILE '(' expression ')' ';' {
        ast_node *node = calloc(1, sizeof(ast_node));
        node->node_type = AST_DO_WHILE;
        node->val.do_while_statement.expression = $5;
        node->val.do_while_statement.statement = $2;
        $$ = node;
    }
    | FOR '(' expression-opt ';' expression-opt ';' expression-opt ')' statement {
        ast_node *node = calloc(1, sizeof(ast_node));
        node->node_type = AST_FOR;
        node->val.for_statement.expr_1 = $3;
        node->val.for_statement.expr_2 = $5;
        node->val.for_statement.expr_3 = $7;
        node->val.for_statement.statement = $9;
        $$ = node;
    }

jump-statement:
    GOTO ident-expr ';' {
        char *name = $2->val.ident.ident_name;
        free($2);
        ast_node *node = calloc(1, sizeof(ast_node));
        node->node_type = AST_GOTO;
        struct symbol_table_entry_ll_node *symbol = find_symbol_in_table(name, CURRENT_SCOPE);
        if (!symbol) {
            yyerror("Undefined Label");
        }
        node->val.goto_label.label = symbol;
        $$ = node;
    }
    | CONTINUE ';' {
        ast_node *node = calloc(1, sizeof(ast_node));
        node->node_type = AST_CONTINUE;
        $$ = node;
    }
    | BREAK ';' {
        ast_node *node = calloc(1, sizeof(ast_node));
        node->node_type = AST_BREAK;
        $$ = node;
    }
    | RETURN expression-opt ';' {
        ast_node *node = calloc(1, sizeof(ast_node));
        node->node_type = AST_RETURN;
        node->val.return_statement.expression = $2;
        $$ = node;
    }

/* 6.9 EXTERNAL DEFINITIONS */

external-declaration:
    declaration {
        print_symbol_table(CURRENT_SCOPE, 0);
        $$ = NULL;
    }
    | statement {$$ = $1;}
    | function-definition {
        print_symbol_table(CURRENT_SCOPE, 0);
        $$ = $1;
    }

function-definition:
    declaration-specifiers declarator compound-statement {
        ast_node *ident_node = $2;
        while (ident_node->node_type != AST_IDENT) {
            if (ident_node->node_type == AST_UNOP && ident_node->val.unop.op == U_FUNCTION_TYPE) {
                ident_node = ident_node->val.unop.center;
            } else if (ident_node->node_type == AST_TYPE_MOD) {
                ident_node = ident_node->val.type_mod.next;
            } else {
                yyerror("could not find identifier in function declarator");
            }
        }
        if (!ident_node) {
            yyerror("function definition missing identifier");
        }

        ast_node *type = build_full_type_from_declarator($2, &CURRENT_TYPE_BUILDER);

        ast_node *node = calloc(1, sizeof(ast_node));
        node->node_type = AST_FUNCTION_DEF;
        node->val.fn_def.return_type = type;
        node->val.fn_def.name = ident_node->val.ident.ident_name;
        node->val.fn_def.content = $3;

        insert_symbol_fn(ident_node->val.ident.ident_name, SYM_GLOBAL);  // symbol table entry

        $$ = node;

        reset_current_type_builder();
        CURRENT_STORAGE_CLASS = 0;
    }

%%

int main(int argc, char **argv) {
    init_global_table();
    yydebug = 0;

    if (argc >= 2) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            perror("fopen");
            return 1;
        }
    } else {
        yyin = stdin;
    }
    yyparse();
    return 0;
}

int yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
    return 0;
}