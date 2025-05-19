#include "quads.h"
#include <stdlib.h>
#include "../SymbolTable/sym_tab.h"
#include "../Parser/ast.h"

quad_ll_node *quad_head = NULL;
quad_ll_node *quad_tail = NULL;

void emit_quad(quad_op op, char *dest, char *src1, char *src2) {
    quad_ll_node *new_node = malloc(sizeof(quad_ll_node));
    new_node->q.op = op;
    new_node->q.dest = dest ? strdup(dest) : NULL;
    new_node->q.src1 = src1 ? strdup(src1) : NULL;
    new_node->q.src2 = src2 ? strdup(src2) : NULL;
    new_node->next = NULL;

    if (!quad_head) {
        quad_head = new_node;
        quad_tail = new_node;
    } else {
        quad_tail->next = new_node;
        quad_tail = new_node;
    }
}

char *current_continue_label = NULL;
char *current_break_label = NULL;

int temp_count = 0;
int label_count = 0;

char *new_temp_reg() {
    char buf[64];
    sprintf(buf, "%%T%015d", temp_count++);
    return strdup(buf);
}

char *new_label() {
    char buf[64];
    sprintf(buf, ".BB%014d", label_count++);
    return strdup(buf);
}

const char *quad_op_to_str(quad_op op) {
    switch (op) {
        case Q_ADD:
            return "ADD";
        case Q_SUB:
            return "SUB";
        case Q_MUL:
            return "MUL";
        case Q_DIV:
            return "DIV";
        case Q_MOD:
            return "MOD";
        case Q_LT:
            return "LT";
        case Q_GT:
            return "GT";
        case Q_LTE:
            return "LTE";
        case Q_GTE:
            return "GTE";
        case Q_EQ:
            return "EQEQ";
        case Q_NE:
            return "NEQ";
        case Q_AND:
            return "AND";
        case Q_OR:
            return "OR";
        case Q_XOR:
            return "XOR";
        case Q_LOAD:
            return "LOAD";
        case Q_STORE:
            return "STORE";
        case Q_LEA:
            return "LEA";
        case Q_CALL:
            return "CALL";
        case Q_RET:
            return "RETURN";
        case Q_CMP:
            return "CMP";
        case Q_BR:
            return "BRANCH";
        case Q_ASSIGN:
            return "ASSIGN";
        case Q_ARGBEGIN:
            return "ARGBEGIN";
        case Q_ARG:
            return "ARG";
        case Q_NOP:
            return "NOP";
        case Q_LABEL:
            return ".";
        case Q_BRZ:
            return "BRZ";
        case Q_BRNZ:
            return "BRNZ";
        default:
            return "UNKNOWN QUAD";
    }
}

void print_quad(quad_ll_node *q) {
    printf(
        "%-10s %s %s %s\n", 
        quad_op_to_str(q->q.op), 
        q->q.dest ? q->q.dest : "", 
        q->q.src1 ? q->q.src1 : "", 
        q->q.src2 ? q->q.src2 : ""
    );
}

void print_all_quads() {
    for (quad_ll_node *curr = quad_head; curr; curr = curr->next) {
        print_quad(curr);
    }
}

char *gen_nop() {
    emit_quad(Q_NOP, NULL, NULL, NULL);
    return NULL;
}

char *gen_quad(ast_node *node) {
    if (!node) {
        return NULL;
    }
    switch (node->node_type) {
        case AST_NUMLIT:
            return gen_quad_AST_NUMLIT(node);
        case AST_CHARLIT:
            return gen_quad_AST_CHARLIT(node);
        case AST_STRLIT:
            return gen_quad_AST_STRLIT(node);
        case AST_IDENT:
            return gen_quad_AST_IDENT(node);
        case AST_UNOP:
            return gen_quad_AST_UNOP(node);
        case AST_BINOP:
            return gen_quad_AST_BINOP(node);
        case AST_TRIOP:
            return gen_quad_AST_TRIOP(node);
        case AST_PRIMITIVE_TYPE:
            return gen_quad_AST_PRIMITIVE_TYPE(node);
        case AST_TYPE_MOD:
            return gen_quad_AST_TYPE_MOD(node);
        case AST_BLOCK:
            return gen_quad_AST_BLOCK(node);
        case AST_FUNCTION_CALL:
            return gen_quad_AST_FUNCTION_CALL(node);
        case AST_COMPOUND_STATEMENT:
            return gen_quad_AST_COMPOUND_STATEMENT(node);
        case AST_IF:
            return gen_quad_AST_IF(node);
        case AST_WHILE:
            return gen_quad_AST_WHILE(node);
        case AST_DO_WHILE:
            return gen_quad_AST_DO_WHILE(node);
        case AST_FOR:
            return gen_quad_AST_FOR(node);
        case AST_GOTO:
            return gen_quad_AST_GOTO(node);
        case AST_CONTINUE:
            return gen_quad_AST_CONTINUE(node);
        case AST_BREAK:
            return gen_quad_AST_BREAK(node);
        case AST_RETURN:
            return gen_quad_AST_RETURN(node);
        case AST_FUNCTION_DEF:
            return gen_quad_AST_FUNCTION_DEF(node);
        default:
            gen_nop();
            return NULL;
    }
}

char *gen_quad_AST_UNOP(ast_node *node) {
    char *arg = gen_quad(node->val.unop.center);
    char *tmp = new_temp_reg();
    switch (node->val.unop.op) {
        case U_NEG: 
            emit_quad(Q_SUB, tmp, "0", arg); 
            break;
        case U_POS: 
            emit_quad(Q_ADD, tmp, "0", arg); 
            break;
        case U_NOT: 
            emit_quad(Q_EQ, tmp, arg, "0"); 
            break;
        case U_BIT_NOT: 
            emit_quad(Q_XOR, tmp, arg, "-1"); 
            break;
        case U_DEREF: 
            emit_quad(Q_LOAD, tmp, arg, NULL); 
            break;
        case U_ADDRESSOF: 
            emit_quad(Q_LEA, tmp, arg, NULL); 
            break;
        case U_PRE_PLUSPLUS:
            emit_quad(Q_ADD, arg, arg, "1");
            emit_quad(Q_ASSIGN, tmp, arg, NULL); 
            break;
        case U_POST_PLUSPLUS:
            emit_quad(Q_ASSIGN, tmp, arg, NULL);
            emit_quad(Q_ADD, arg, arg, "1"); 
            break;
        case U_PRE_MINUSMINUS:
            emit_quad(Q_SUB, arg, arg, "1");
            emit_quad(Q_ASSIGN, tmp, arg, NULL); 
            break;
        case U_POST_MINUSMINUS:
            emit_quad(Q_ASSIGN, tmp, arg, NULL);
            emit_quad(Q_SUB, arg, arg, "1"); 
            break;
        default:
            fprintf(stderr, "Unsupported unary op\n");
            break;
    }
    return tmp;
}

char *gen_quad_AST_NUMLIT(ast_node *node) {
    char *buf = malloc(32);
    sprintf(buf, "%lld", node->val.numlit.val.int_val);
    return buf;
}

char *gen_quad_AST_IDENT(ast_node *node) {
    return strdup(node->val.ident.ident_name);
}

char *gen_quad_AST_BINOP(ast_node *node) {
    if (node->val.binop.op == B_EQ) {
        ast_node *lhs = node->val.binop.left;
        ast_node *rhs = node->val.binop.right;

        if (lhs->node_type == AST_UNOP && lhs->val.unop.op == U_DEREF) {
            char *addr = gen_quad(lhs->val.unop.center);
            char *val = gen_quad(rhs);
            emit_quad(Q_STORE, addr, val, NULL);
            return addr;
        } else {
            char *dst = gen_quad(lhs);
            char *val = gen_quad(rhs);
            emit_quad(Q_ASSIGN, dst, val, NULL);
            return dst;
        }
    } else {
        char *lhs = gen_quad(node->val.binop.left);
        char *rhs = gen_quad(node->val.binop.right);
        char *tmp = new_temp_reg();
        quad_op op;
        switch (node->val.binop.op) {
            case B_PLUS: 
                op = Q_ADD; 
                break;
            case B_MINUS: 
                op = Q_SUB; 
                break;
            case B_TIMES: 
                op = Q_MUL; 
                break;
            case B_DIVIDE: 
                op = Q_DIV; 
                break;
            case B_MOD: 
                op = Q_MOD; 
                break;
            case B_LT: 
                op = Q_LT; 
                break;
            case B_GT: 
                op = Q_GT; 
                break;
            case B_LTEQ: 
                op = Q_LTE; 
                break;
            case B_GTEQ: 
                op = Q_GTE; 
                break;
            case B_EQEQ: 
                op = Q_EQ; 
                break;
            case B_NOTEQ: 
                op = Q_NE; 
                break;
            case B_LOG_AND: 
                op = Q_AND; 
                break;
            case B_LOG_OR: 
                op = Q_OR; 
                break;
            default: 
                op = Q_NOP;
                break;
        }
        emit_quad(op, tmp, lhs, rhs);
        return tmp;
    }
}

char *gen_quad_AST_TRIOP(ast_node *node) {
    char *cond = gen_quad(node->val.triop.left);     // cond
    char *true_val = gen_quad(node->val.triop.center); // a
    char *false_val = gen_quad(node->val.triop.right); // b

    char *t1 = new_temp_reg();
    char *t2 = new_temp_reg();
    char *one_minus_cond = new_temp_reg();
    char *result = new_temp_reg();

    emit_quad(Q_MUL, t1, true_val, cond);  // t1 = a * cond
    emit_quad(Q_SUB, one_minus_cond, "1", cond); // one_minus_cond = 1 - cond
    emit_quad(Q_MUL, t2, false_val, one_minus_cond); // t2 = b * (1 - cond)
    emit_quad(Q_ADD, result, t1, t2); // result = t1 + t2

    return result;
}

char *gen_quad_AST_FUNCTION_CALL(ast_node *node) {
    struct symbol_table_entry_ll_node *fn = node->val.function_call.fn;
    if (!fn) {
        fprintf(stderr, "Null function symbol in AST_FUNCTION_CALL\n");
        return NULL;
    }

    char *result = new_temp_reg();

    emit_quad(Q_ARGBEGIN, NULL, NULL, NULL);   // No args assumed
    emit_quad(Q_CALL, result, fn->name, NULL); // CALL result, fn_name

    return result;
}

char *gen_quad_AST_BLOCK(ast_node *node) {
    ast_node *current = node;
    while (current) {
        gen_quad(current->val.block.statement);
        current = current->val.block.next;
    }
    return NULL;
}

char *gen_quad_AST_RETURN(ast_node *node) {
    if (node->val.return_statement.expression) {
        char *retval = gen_quad(node->val.return_statement.expression);
        emit_quad(Q_RET, retval, NULL, NULL);
    } else {
        emit_quad(Q_RET, NULL, NULL, NULL);
    }
    return NULL;
}

char *gen_quad_AST_GOTO(ast_node *node) {
    if (!node->val.goto_label.label || !node->val.goto_label.label->name) {
        fprintf(stderr, "ERROR: goto target label is undefined\n");
        return NULL;
    }

    emit_quad(Q_BR, node->val.goto_label.label->name, NULL, NULL);
    return NULL;
}

char *gen_quad_AST_CHARLIT(ast_node *node) {
    char *buf = malloc(8);
    sprintf(buf, "%d", (int)node->val.charlit.val);
    return buf;
}

char *gen_quad_AST_COMPOUND_STATEMENT(ast_node *node) {
    char *label = new_label();
    emit_quad(Q_LABEL, label, NULL, NULL);
    return gen_quad_AST_BLOCK(node->val.compound.blocks);
}

char *gen_quad_AST_IF(ast_node *node) {
    char *cond = gen_quad(node->val.if_statement.expression);
    char *label_else = new_label();
    char *label_end = new_label();

    emit_quad(Q_BRZ, label_else, cond, NULL);
    gen_quad(node->val.if_statement.statement);
    emit_quad(Q_BR, label_end, NULL, NULL);
    emit_quad(Q_LABEL, label_else, NULL, NULL);
    if (node->val.if_statement.else_statement) {
        gen_quad(node->val.if_statement.else_statement);
    }
    emit_quad(Q_LABEL, label_end, NULL, NULL);
    return NULL;
}

char *gen_quad_AST_WHILE(ast_node *node) {
    char *label_start = new_label();
    char *label_end = new_label();

    char *prev_continue = current_continue_label;
    char *prev_break = current_break_label;
    current_continue_label = label_start;
    current_break_label = label_end;

    emit_quad(Q_LABEL, label_start, NULL, NULL);
    char *cond = gen_quad(node->val.while_statement.expression);
    emit_quad(Q_BRZ, label_end, cond, NULL);
    gen_quad(node->val.while_statement.statement);
    emit_quad(Q_BR, label_start, NULL, NULL);
    emit_quad(Q_LABEL, label_end, NULL, NULL);

    current_continue_label = prev_continue;
    current_break_label = prev_break;

    return NULL;
}


char *gen_quad_AST_DO_WHILE(ast_node *node) {
    char *label_start = new_label();
    char *label_test = new_label();

    char *prev_continue = current_continue_label;
    char *prev_break = current_break_label;
    current_continue_label = label_test;
    current_break_label = new_label();

    emit_quad(Q_LABEL, label_start, NULL, NULL);
    gen_quad(node->val.do_while_statement.statement);
    emit_quad(Q_LABEL, label_test, NULL, NULL);
    char *cond = gen_quad(node->val.do_while_statement.expression);
    emit_quad(Q_BRNZ, label_start, cond, NULL);

    current_continue_label = prev_continue;
    current_break_label = prev_break;

    return NULL;
}

char *gen_quad_AST_FOR(ast_node *node) {
    gen_quad(node->val.for_statement.expr_1);

    char *label_test = new_label();
    char *label_body = new_label();
    char *label_end = new_label();

    char *prev_continue = current_continue_label;
    char *prev_break = current_break_label;
    current_continue_label = label_test;
    current_break_label = label_end;

    emit_quad(Q_LABEL, label_test, NULL, NULL);
    char *cond = gen_quad(node->val.for_statement.expr_2);
    emit_quad(Q_BRZ, label_end, cond, NULL);

    emit_quad(Q_LABEL, label_body, NULL, NULL);
    gen_quad(node->val.for_statement.statement);
    gen_quad(node->val.for_statement.expr_3);
    emit_quad(Q_BR, label_test, NULL, NULL);
    emit_quad(Q_LABEL, label_end, NULL, NULL);

    current_continue_label = prev_continue;
    current_break_label = prev_break;

    return NULL;
}

char *gen_quad_AST_CONTINUE(ast_node *node) {
    emit_quad(Q_BR, current_continue_label, NULL, NULL);
    return NULL;
}

char *gen_quad_AST_BREAK(ast_node *node) {
    extern char *current_break_label;
    emit_quad(Q_BR, current_break_label, NULL, NULL);
    return NULL;
}

char *gen_quad_AST_FUNCTION_DEF(ast_node *node) {
    struct symbol_table_entry_ll_node *fn = node->val.fn_def.return_type->val.ident.symbol;
    if (!fn || !fn->name) {
        fprintf(stderr, "Missing function symbol in definition\n");
        return NULL;
    }

    emit_quad(Q_LABEL, fn->name, NULL, NULL);
    gen_quad(node->val.fn_def.content);
    return NULL;
}