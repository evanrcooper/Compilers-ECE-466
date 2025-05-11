#include "ast.h"

char *unop_to_str(enum unop_type type) {
    char *ret_str;
    char *msg;
    switch (type) {
        case U_ADDRESSOF:
            msg = "&";
            break;
        case U_DEREF:
            msg = "*";
            break;
        case U_NOT:
            msg = "!";
            break;
        case U_BIT_NOT:
            msg = "~";
            break;
        case U_POS:
            msg = "+";
            break;
        case U_NEG:
            msg = "-";
            break;
        case U_PRE_PLUSPLUS:
            msg = "++i";
            break;
        case U_PRE_MINUSMINUS:
            msg = "--i";
            break;
        case U_POST_PLUSPLUS:
            msg = "i++";
            break;
        case U_POST_MINUSMINUS:
            msg = "i--";
            break;
        case U_SIZEOF_TYPENAME:
            msg = "SIZEOF(TYPE-NAME)";
            break;
        case U_SIZEOF_EXPRESSION:
            msg = "SIZEOF EXPRESSION";
            break;
        case U_FUNCTION_TYPE:
            msg = "FUNCTION THAT RETURNS TYPE";
            break;
        case U_FUNCTION_CALL:
            msg = "CALL FUNCTION";
            break;
        default:
            msg = "N/A";
            break;
    }
    ret_str = malloc(strlen(msg) + 1);
    strcpy(ret_str, msg);
    return ret_str;
}

char *primitive_type_to_str(enum primitive_type type) {
    char *ret_str;
    char *msg;
    switch (type) {
        case TYPE_UNSIGNED_LONG_LONG:
            msg = "UNSIGNED LONG LONG";
            break;
        case TYPE_SIGNED_LONG_LONG:
            msg = "SIGNED LONG LONG";
            break;
        case TYPE_UNSIGNED_LONG:
            msg = "UNSIGNED LONG";
            break;
        case TYPE_SIGNED_LONG:
            msg = "SIGNED LONG";
            break;
        case TYPE_UNSIGNED_INT:
            msg = "UNSIGNED INT";
            break;
        case TYPE_SIGNED_INT:
            msg = "SIGNED INT";
            break;
        case TYPE_UNSIGNED_SHORT:
            msg = "UNSIGNED SHORT";
            break;
        case TYPE_SIGNED_SHORT:
            msg = "SIGNED SHORT";
            break;
        case TYPE_UNSIGNED_CHAR:
            msg = "UNSIGNED CHAR";
            break;
        case TYPE_SIGNED_CHAR:
            msg = "SIGNED CHAR";
            break;
        case TYPE_VOID:
            msg = "VOID";
            break;
        default:
            msg = "N/A";
            break;
    }
    ret_str = malloc(strlen(msg) + 1);
    strcpy(ret_str, msg);
    return ret_str;
}

char *binop_to_str(enum binop_type type) {
    char *ret_str;
    char *msg;
    switch (type) {
        case B_PLUS:
            msg = "+";
            break;
        case B_MINUS:
            msg = "-";
            break;
        case B_TIMES:
            msg = "*";
            break;
        case B_DIVIDE:
            msg = "/";
            break;
        case B_BIT_AND:
            msg = "&";
            break;
        case B_BIT_OR:
            msg = "|";
            break;
        case B_BIT_XOR:
            msg = "^";
            break;
        case B_MOD:
            msg = "%";
            break;
        case B_LT:
            msg = "<";
            break;
        case B_GT:
            msg = ">";
            break;
        case B_LTEQ:
            msg = "<=";
            break;
        case B_GTEQ:
            msg = ">=";
            break;
        case B_EQEQ:
            msg = "==";
            break;
        case B_NOTEQ:
            msg = "!=";
            break;
        case B_LOG_AND:
            msg = "&&";
            break;
        case B_LOG_OR:
            msg = "||";
            break;
        case B_SHL:
            msg = "<<";
            break;
        case B_SHR:
            msg = ">>";
            break;
        case B_EQ:
            msg = "=";
            break;
        case B_TIMESEQ:
            msg = "*=";
            break;
        case B_DIVEQ:
            msg = "/=";
            break;
        case B_MODEQ:
            msg = "%=";
            break;
        case B_PLUSEQ:
            msg = "+=";
            break;
        case B_MINUSEQ:
            msg = "-=";
            break;
        case B_SHLEQ:
            msg = "<<=";
            break;
        case B_SHREQ:
            msg = ">>=";
            break;
        case B_BIT_ANDEQ:
            msg = "&=";
            break;
        case B_BIT_OREQ:
            msg = "|=";
            break;
        case B_BIT_XOREQ:
            msg = "^=";
            break;
        case B_STRUCT_OFFSET:
            msg = ".";
            break;
        case B_INDSEL:
            msg = "->";
            break;
        case B_COMMA:
            msg = ", (ASSIGN LIST)";
            break;
        case B_TYPECAST:
            msg = "TYPE CAST";
            break;
        default:
            msg = "N/A";
            break;
    }
    ret_str = malloc(strlen(msg) + 1);
    strcpy(ret_str, msg);
    return ret_str;
}

char *triop_to_str(enum triop_type type) {
    char *ret_str;
    char *msg;
    switch (type) {
        case T_TERNARY:
            msg = "?";
            break;
        default:
            msg = "N/A";
            break;
    }
    ret_str = malloc(strlen(msg) + 1);
    strcpy(ret_str, msg);
    return ret_str;
}

void free_ast_tree(ast_node *root) {
    switch (root->node_type) {
        case AST_NUMLIT:
        case AST_CHARLIT:
        case AST_STRLIT:
        case AST_IDENT:
            free(root);
            break;
        case AST_UNOP:
            free_ast_tree(root->val.unop.center);
            break;
        case AST_BINOP:
            free_ast_tree(root->val.binop.left);
            free_ast_tree(root->val.binop.right);
            break;
        case AST_TRIOP:
            free_ast_tree(root->val.triop.left);
            free_ast_tree(root->val.triop.center);
            free_ast_tree(root->val.triop.right);
            break;
        default:
            break;
    }
    free(root);
    return;
}

void print_ast_tree(ast_node *root) {
    print_ast_node(0, root);
}

void print_ast_node(int depth, ast_node *node) {
    if (!node) {
        return;
    }
    char *op;
    for (int i = 0; i < depth; i++) {
        printf("-- ");
    }
    switch (node->node_type) {
        case AST_NUMLIT:
            switch (node->val.numlit.type) {
                case N_LLF:
                    printf("FLOAT: %Lf\n", node->val.numlit.val.real_val);
                    break;
                case N_LLI:
                    printf("INT: %lld\n", node->val.numlit.val.int_val);
                    break;
            }
            break;
        case AST_CHARLIT:
            printf("CHAR: ");
            print_char(node->val.charlit.val);
            break;
        case AST_STRLIT:
            printf("STRING: ");
            print_string(node->val.strlit.val, node->val.strlit.len);
            break;
        case AST_IDENT:
            printf("IDENT: %s\n", node->val.ident.ident_name);
            break;
        case AST_UNOP:
            op = unop_to_str(node->val.unop.op);
            printf("UNOP: %s\n", op);
            free(op);
            print_ast_node(depth + 1, node->val.unop.center);
            break;
        case AST_BINOP:
            op = binop_to_str(node->val.binop.op);
            printf("BINOP: %s\n", op);
            free(op);
            print_ast_node(depth + 1, node->val.binop.left);
            print_ast_node(depth + 1, node->val.binop.right);
            break;
        case AST_TRIOP:
            op = triop_to_str(node->val.triop.op);
            printf("TRIOP: %s\n", op);
            free(op);
            print_ast_node(depth + 1, node->val.triop.left);
            print_ast_node(depth + 1, node->val.triop.center);
            print_ast_node(depth + 1, node->val.triop.right);
            break;
        case AST_PRIMITIVE_TYPE:
            op = primitive_type_to_str(node->val.primitive_type.type);
            printf("TYPE: %s\n", op);
            free(op);
            print_ast_node(depth + 1, node->val.primitive_type.next);
        case AST_TYPE_MOD:
            switch (node->val.type_mod.modifier) {
                case POINTER:
                    printf("POINTER TO\n");
                    break;
                case UNSIZED_ARRAY:
                    printf("ARRAY OF UNSPECIFIED SIZE OF TYPE\n");
                    break;
                case CONSTANT_SIZED_ARRAY:
                    printf("ARRAY OF SIZE [%d] OF TYPE\n", node->val.type_mod.array_size);
                    break;
                default:
                    break;
            }
            print_ast_node(depth + 1, node->val.type_mod.next);
        default:
            printf("\rERROR (%d)\n", node->node_type);
            break;
    }
}

ast_node* create_unop_node(enum unop_type op, ast_node *center) {
    ast_node *unop_node = calloc(1, sizeof(ast_node));
    unop_node->node_type = AST_UNOP;
    unop_node->val.unop.op = op;
    unop_node->val.unop.center = center;
    return unop_node;
}

ast_node* create_binop_node(enum binop_type op, ast_node *left, ast_node *right) {
    ast_node *binop_node = calloc(1, sizeof(ast_node));
    binop_node->node_type = AST_BINOP;
    binop_node->val.binop.op = op;
    binop_node->val.binop.left = left;
    binop_node->val.binop.right = right;
    return binop_node;
}

ast_node* create_triop_node(enum binop_type op, ast_node *left, ast_node *center, ast_node *right) {
    ast_node *triop_node = calloc(1, sizeof(ast_node));
    triop_node->node_type = AST_TRIOP;
    triop_node->val.triop.op = op;
    triop_node->val.triop.left = left;
    triop_node->val.triop.center = center;
    triop_node->val.triop.right = right;
    return triop_node;
}

ast_node* create_primitive_type_node(enum primitive_type type) {
    ast_node *primitive_type_node = calloc(1, sizeof(ast_node));
    primitive_type_node->node_type = AST_PRIMITIVE_TYPE;
    primitive_type_node->val.primitive_type.type = type;
    /* primitive_type_node->val.primitive_type.next = NULL; */
    return primitive_type_node;
}

// array_size optional for non CONSTANT_SIZED_ARRAY modifier
ast_node* create_type_modifier_node(enum type_modifier modifier, int array_size) {
    ast_node *type_mod_node = calloc(1, sizeof(ast_node));
    type_mod_node->node_type = AST_TYPE_MOD;
    type_mod_node->val.type_mod.modifier = modifier;
    type_mod_node->val.type_mod.array_size = array_size;
    /* type_mod_node->val.type_mod.next = NULL; */
    return type_mod_node;
}

int is_printable(char c) {
    return (c <= '~') && (c >= ' ');
}

void print_string(char *str, int len) {
    printf("\"");
    for (int i = 0; i < len; i++) {
        if (is_printable(str[i])) {
            printf("%c", str[i]);
        } else {
            printf("\\x%02x", str[i]);
        }
    }
    printf("\"\n");
}

void print_char(char c) {
    printf("\'");
    if (is_printable(c)) {
        printf("%c", c);
    } else {
        printf("\\x%02x", c);
    }
    printf("\'\n");
}

void reset_current_type_builder() {
    CURRENT_TYPE_BUILDER.is_unsigned = 0;
    CURRENT_TYPE_BUILDER.is_signed = 0;
    CURRENT_TYPE_BUILDER.is_short = 0;
    CURRENT_TYPE_BUILDER.is_long = 0;
    CURRENT_TYPE_BUILDER.is_long_long = 0;
    CURRENT_TYPE_BUILDER.is_char = 0;
    CURRENT_TYPE_BUILDER.is_int = 0;
    CURRENT_TYPE_BUILDER.is_void = 0;
    return;
}


enum primitive_type get_primitive_type(struct type_builder built_type) {
    if (built_type.is_void) {
        return TYPE_VOID;
    } else if (built_type.is_char) {
        return built_type.is_unsigned ? TYPE_UNSIGNED_CHAR : TYPE_SIGNED_CHAR;
    } else if (built_type.is_long_long) {
        return built_type.is_unsigned ? TYPE_UNSIGNED_LONG_LONG : TYPE_SIGNED_LONG_LONG;
    } else if (built_type.is_long) {
        return built_type.is_unsigned ? TYPE_UNSIGNED_LONG : TYPE_SIGNED_LONG;
    } else if (built_type.is_short) {
        return built_type.is_unsigned ? TYPE_UNSIGNED_SHORT : TYPE_SIGNED_SHORT;
    } 
    // otherwise is type long, int, or unspecified type
    return built_type.is_unsigned ? TYPE_UNSIGNED_INT : TYPE_SIGNED_INT;
}