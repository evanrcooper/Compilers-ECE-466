#ifndef AST_H
#define AST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ast_node_struct ast_node;
struct ast_node_unop;
struct ast_node_binop;
struct ast_node_triop;
struct ast_node_numlit;
struct ast_node_ident;
struct ast_node_charlit;
struct ast_node_strlit;

enum unop_type { // op1 id1
    U_NOT = 1, // !
    U_BIT_NOT, // ~
    U_POS, // +
    U_NEG, // -
    U_PRE_PLUSPLUS, // ++x
    U_PRE_MINUSMINUS, // --x
    U_POST_PLUSPLUS, // x++
    U_POST_MINUSMINUS, // x--
    U_ADDRESSOF, // &
    U_DEREF, // *
};

enum binop_type { // id1 op1 id2
    B_PLUS = 1, // +
    B_MINUS, // -
    B_TIMES, // *
    B_DIVIDE, // /
    B_BIT_AND, // &
    B_BIT_OR, // |
    B_BIT_XOR, // ^
    B_MOD, // %
    B_LT, // <
    B_GT, // >
    B_LTEQ, // <=
    B_GTEQ, // >=
    B_EQEQ, // ==
    B_NOTEQ, // !=
    B_LOG_AND, // &&
    B_LOG_OR, // ||
    B_SHL, // <<
    B_SHR, // >>
    B_EQ, // =
    B_TIMESEQ, // *=
    B_DIVEQ, // /=
    B_MODEQ, // %=
    B_PLUSEQ, // +=
    B_MINUSEQ, // -=
    B_SHLEQ, // <<=
    B_SHREQ, // >>=
    B_BIT_ANDEQ, // &=
    B_BIT_OREQ, // |=
    B_BIT_XOREQ, // ^=
    B_COMMA, // expr, expr
    B_STRUCT_OFFSET, // a.b
    B_INDSEL, // a->b
};

enum triop_type { // id1 op1 id2 op2 id3
    T_TERNARY = 1, // ? :
};

enum numlit_type {
    N_LLI = 1, // long long int
    N_LLF, // long double
};

enum ast_node_type {
    AST_NUMLIT = 1,
    AST_CHARLIT,
    AST_STRLIT,
    AST_IDENT,
    AST_UNOP,
    AST_BINOP,
    AST_TRIOP,
    AST_PRIMITIVE_TYPE,
    AST_TYPE_MOD,
};

enum primitive_type {
    TYPE_UNSIGNED_LONG_LONG = 1, // 64 bit usigned value
    TYPE_SIGNED_LONG_LONG, // 64 bit signed value
    TYPE_UNSIGNED_INT, // 32 bit usigned value
    TYPE_SIGNED_INT, // 32 bit signed value
    TYPE_UNSIGNED_SHORT, // 16 bit usigned value
    TYPE_SIGNED_SHORT, // 16 bit signed value
    TYPE_UNSIGNED_CHAR, // 8 bit unsigned value
    TYPE_SIGNED_CHAR, // 8 bit signed value
};

enum type_modifier {
    POINTER = 1, // *
    CONSTANT_SIZED_ARRAY, // [1]
    UNSIZED_ARRAY, // []
};

struct ast_node_unop {
    enum unop_type op;
    ast_node *center;
};

struct ast_node_binop {
    enum binop_type op;
    ast_node *left;
    ast_node *right;
};

struct ast_node_triop {
    enum triop_type op;
    ast_node *left;
    ast_node *center;
    ast_node *right;
};

struct ast_node_numlit {
    enum numlit_type type;
    union numlit_val {
        long long int_val;
        long double real_val;
    } val;
};

struct ast_node_ident {
    char *ident_name;
    struct symbol_table_entry_ll_node *symbol; // symbol table entry
};

struct ast_node_charlit {
    char val;
};

struct ast_node_strlit {
    char *val;
    unsigned long long len;
};

struct ast_node_primitive_type {
    ast_node *next;
    enum primitive_type type;
};

struct ast_node_type_modifier {
    ast_node *next;
    enum type_modifier modifier;
    int array_size; // ONLY USED FOR CONSTANT_SIZED_ARRAY
};

typedef struct ast_node_struct {
    enum ast_node_type node_type;
    union ast_node_val {
        struct ast_node_unop unop;
        struct ast_node_binop binop;
        struct ast_node_triop triop;
        struct ast_node_numlit numlit;
        struct ast_node_ident ident;
        struct ast_node_charlit charlit;
        struct ast_node_strlit strlit;
        struct ast_node_primitive_type primitive_type;
        struct ast_node_type_modifier type_mod;
        /* ... */
    } val;
} ast_node;

char *unop_to_char(enum unop_type type);
char *binop_to_str(enum binop_type type);
char *triop_to_char(enum triop_type type);

void print_ast_node(int depth, ast_node *node);
void print_ast_tree(ast_node *root);

void free_ast_tree(ast_node *root);

ast_node* create_unop_node(enum unop_type op, ast_node *center);
ast_node* create_binop_node(enum binop_type op, ast_node *left, ast_node *right);
ast_node* create_triop_node(enum binop_type op, ast_node *left, ast_node *center, ast_node *right);

typedef struct DYNAMIC_STRING {
    char *str_val;
    unsigned long long str_len;
} D_STRING;

int is_printable(char c);

void print_string(char *str, int len);

void print_char(char c);

#endif // AST_H