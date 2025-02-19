#ifndef AST_H
#define AST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ast_node_struct ast_node;
struct ast_node_unop unop;
struct ast_node_binop binop;
struct ast_node_triop triop;
struct ast_node_numlit numlit;
struct ast_node_ident ident;
struct ast_node_charlit charlit;
struct ast_node_strlit strlit;

enum unop_type { // op1 id1
    NOT, // !
    BIT_NOT, // ~
    POS, // +
    NEG, // -
    PRE_PLUSPLUS, // ++x
    PRE_MINUSMINUS, // --x
    POST_PLUSPLUS, // x++
    POST_MINUSMINUS, // x--
};

enum binop_type { // id1 op1 id2
    PLUS, // +
    MINUS, // -
    TIMES, // *
    DIVIDE, // /
    BIT_AND, // &
    BIT_OR, // |
    BIT_XOR, // ^
    MOD, // %
    LT, // <
    GT, // >
    LTEQ, // <=
    GTEQ, // >=
    EQEQ, // ==
    NOTEQ, // !=
    LOG_AND, // &&
    LOG_OR, // ||
    SHL, // <<
    SHR, // >>
    EQ, // =
    TIMESEQ, // *=
    DIVEQ, // /=
    MODEQ, // %=
    PLUSEQ, // +=
    MINUSEQ, // -=
    SHLEQ, // <<=
    SHREQ, // >>=
    BIT_ANDEQ, // &=
    BIT_OREQ, // |=
    BIT_XOREQ, // ^=
};

enum triop_type { // id1 op1 id2 op2 id3
    TERNARY, // ? :
};

enum numlit_type {
    LLI, // long long int
    LLF, // long double
};

enum ast_node_type {
    NUMLIT,
    CHARLIT,
    STRLIT,
    IDENT,
    UNOP,
    BINOP,
    TRIOP,
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
};

struct ast_node_charlit {
    char val;
};

struct ast_node_strlit {
    char *val;
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
        /* ... */
    } val;
} ast_node;

char *unop_to_char(enum unop_type type);
char *binop_to_str(enum binop_type type);
char *triop_to_char(enum triop_type type);
void print_ast_node(int depth, ast_node *node);
void print_ast_tree(ast_node *root);

#endif // AST_H