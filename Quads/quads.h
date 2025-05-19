#ifndef QUADS_H
#define QUADS_H

#include "../Parser/ast.h"

typedef enum {
    Q_ADD = 1, Q_SUB, Q_MUL, Q_DIV, Q_MOD,
    Q_LT, Q_GT, Q_LTE, Q_GTE, Q_EQ, Q_NE,
    Q_AND, Q_OR, Q_XOR,
    Q_LOAD, Q_STORE,
    Q_LEA, Q_CALL, Q_RET,
    Q_CMP, Q_BR, Q_BRZ, Q_BRNZ,
    Q_ASSIGN,
    Q_ARGBEGIN, Q_ARG,
    Q_LABEL,
    Q_NOP, // for debugging
} quad_op;

typedef struct {
    quad_op op;
    char *dest;
    char *src1;
    char *src2;
} quad;

typedef struct quad_ll {
    quad q;
    struct quad_ll *next;
} quad_ll_node;

void new_quad(quad_op op, char *dest, char *src1, char *src2);
char *new_temp_reg();
char *new_label();
const char *quad_op_to_str(quad_op op);
void print_quad(quad_ll_node *q);
void print_all_quads();
char *emit_quad(ast_node *node);
char *gen_nop();
char *gen_quad_AST_UNOP(ast_node *node);
char *gen_quad_AST_BINOP(ast_node *node);
char *gen_quad_AST_NUMLIT(ast_node *node);
char *gen_quad_AST_TRIOP(ast_node *node);
char *gen_quad_AST_IDENT(ast_node *node);
char *gen_quad_AST_FUNCTION_CALL(ast_node *node);
char *gen_quad_AST_BLOCK(ast_node *node);
char *gen_quad_AST_RETURN(ast_node *node);
char *gen_quad_AST_GOTO(ast_node *node);
char *gen_quad_AST_CHARLIT(ast_node *node);
char *gen_quad_AST_STRLIT(ast_node *node);
char *gen_quad_AST_COMPOUND_STATEMENT(ast_node *node);
char *gen_quad_AST_IF(ast_node *node);
char *gen_quad_AST_WHILE(ast_node *node);
char *gen_quad_AST_DO_WHILE(ast_node *node);
char *gen_quad_AST_FOR(ast_node *node);
char *gen_quad_AST_CONTINUE(ast_node *node);
char *gen_quad_AST_BREAK(ast_node *node);
char *gen_quad_AST_FUNCTION_DEF(ast_node *node);

#endif