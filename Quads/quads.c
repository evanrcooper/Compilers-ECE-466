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
    sprintf(buf, "%%T%d", temp_count++);
    return strdup(buf);
}

char *new_label() {
    char buf[64];
    sprintf(buf, ".BB%d", label_count++);
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
            return "LABEL:";
        case Q_BRZ:
            return "BRZ";
        case Q_BRNZ:
            return "BRNZ";
        case Q_SHL:
            return "SHL";
        case Q_SHR:
            return "SHR";
        default:
            return "UNKNOWN QUAD";
    }
}

void print_quad(quad_ll_node *q) {
    printf(
        "%s %s %s %s\n", 
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
        case U_SIZEOF_EXPRESSION:
            char *buf = malloc(32);  // Allocate enough space for an int
            if (!buf) return NULL;
            sprintf(buf, "%llu", get_size_of_expr(node->val.unop.center));
            return buf;
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
    if (
        node->val.binop.op == B_EQ
        || node->val.binop.op == B_TIMESEQ
        || node->val.binop.op == B_DIVEQ
        || node->val.binop.op == B_MODEQ
        || node->val.binop.op == B_PLUSEQ
        || node->val.binop.op == B_MINUSEQ
        || node->val.binop.op == B_SHLEQ
        || node->val.binop.op == B_SHREQ
        || node->val.binop.op == B_BIT_ANDEQ
        || node->val.binop.op == B_BIT_OREQ
        || node->val.binop.op == B_BIT_XOREQ
    ) {
        ast_node *lhs = node->val.binop.left;
        ast_node *rhs = node->val.binop.right;

        if (lhs->node_type == AST_UNOP && lhs->val.unop.op == U_DEREF) {
            char *addr = gen_quad(lhs->val.unop.center);
            char *val = gen_quad(rhs);
            emit_quad(Q_STORE, addr, val, NULL);
            return addr;
        } 
        char *dst = gen_quad(lhs);
        char *val = gen_quad(rhs);
        switch (node->val.binop.op) {
            case B_TIMESEQ:
                emit_quad(Q_MUL, dst, dst, val);
                break;
            case B_DIVEQ:
                emit_quad(Q_DIV, dst, dst, val);
                break;
            case B_MODEQ:
                emit_quad(Q_MOD, dst, dst, val);
                break;
            case B_PLUSEQ:
                emit_quad(Q_ADD, dst, dst, val);
                break;
            case B_MINUSEQ:
                emit_quad(Q_SUB, dst, dst, val);
                break;
            case B_SHLEQ:
                emit_quad(Q_SHL, dst, dst, val);
                break;
            case B_SHREQ:
                emit_quad(Q_SHR, dst, dst, val);
                break;
            case B_BIT_ANDEQ:
                emit_quad(Q_AND, dst, dst, val);
                break;
            case B_BIT_OREQ:
                emit_quad(Q_OR, dst, dst, val);
                break;
            case B_BIT_XOREQ:
                emit_quad(Q_XOR, dst, dst, val);
                break;
            case B_EQ:
                emit_quad(Q_ASSIGN, dst, val, NULL);
                break;
            default:
                gen_nop();
                break;
        }
        return dst;
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
            case B_SHL: 
                op = Q_SHL; 
                break;
            case B_SHR: 
                op = Q_SHR; 
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

char *gen_quad_AST_STRLIT(ast_node *node) {
    static int strlit_count = 0;
    char label[32];
    sprintf(label, ".LC%d", strlit_count++);
    return strdup(label);
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
    emit_quad(Q_BR, current_break_label, NULL, NULL);
    return NULL;
}

char *gen_quad_AST_FUNCTION_DEF(ast_node *node) {
    char* name = node->val.fn_def.name;
    if (!name) {
        fprintf(stderr, "Missing function symbol in definition\n");
        return NULL;
    }
    char *label = malloc(strlen(name) + 5); // ".fn_" = 4 chars + 1 for '\0'
    if (!label) {
        perror("malloc failed");
        exit(1);
    }
    sprintf(label, ".fn_%s", name);
    emit_quad(Q_LABEL, name, NULL, NULL);
    gen_quad(node->val.fn_def.content);
    return NULL;
}

ast_node *strip_deref_type(ast_node *type) {
    if (!type) return NULL;

    // Case 1: pointer or array modifier
    if (type->node_type == AST_TYPE_MOD) {
        return type->val.type_mod.next;  // strip one layer
    }

    // Case 2: primitive + modifiers (e.g., int[10][20] or int*[5])
    if (type->node_type == AST_PRIMITIVE_TYPE) {
        ast_node *mod = type->val.primitive_type.next;
        if (!mod) return NULL;  // just a primitive (int), can't deref
        return mod->val.type_mod.next;  // strip one modifier
    }

    return NULL;  // unknown or invalid input
}
long long unsigned int get_size_of_expr(ast_node *node) {
    if (!node) {
        return 0;
    };

    switch (node->node_type) {
        case AST_TYPE_MOD:
        case AST_PRIMITIVE_TYPE:
            return get_size_of_type(node);
        case AST_IDENT:
            return get_size_of_ident(node);

        case AST_UNOP:
            if (node->val.unop.op == U_DEREF) {
                ast_node *center = node->val.unop.center;
                if (center->node_type == AST_IDENT && center->val.ident.symbol) {
                    ast_node *base_type = center->val.ident.symbol->specs.variable.type;
                    ast_node *stripped = strip_deref_type(base_type);
                    return get_size_of_type(stripped);
                }
                return get_size_of_expr(center);
            }

        case AST_NUMLIT:
            return sizeof(int);

        case AST_CHARLIT:
            return sizeof(char);

        case AST_BINOP:
        case AST_TRIOP: {
            long long unsigned int l = get_size_of_expr(node->node_type == AST_BINOP ? node->val.binop.left : node->val.triop.center);
            long long unsigned int r = get_size_of_expr(node->node_type == AST_BINOP ? node->val.binop.right : node->val.triop.right);
            return (l < 4 && r < 4) ? 4 : (l > r ? l : r);
        }

        default:
            return 0;
    }
}

long long unsigned int get_size_of_ident(ast_node *node) {
    if (!node || node->node_type != AST_IDENT || !node->val.ident.symbol) {
        fprintf(stderr, "Invalid identifier for sizeof\n");
        return 0;
    }

    return get_size_of_type(node->val.ident.symbol->specs.variable.type);
}

long long unsigned int get_size_of_type(ast_node *type) {
    if (!type) return 0;

    // Case: primitive type (base case of recursion)
    if (type->node_type == AST_PRIMITIVE_TYPE) {
        long long unsigned int base_size;
        switch (type->val.primitive_type.type) {
            case TYPE_SIGNED_CHAR:
            case TYPE_UNSIGNED_CHAR:
                base_size = 1; break;
            case TYPE_SIGNED_SHORT:
            case TYPE_UNSIGNED_SHORT:
                base_size = 2; break;
            case TYPE_SIGNED_INT:
            case TYPE_UNSIGNED_INT:
                base_size = 4; break;
            case TYPE_SIGNED_LONG:
            case TYPE_UNSIGNED_LONG:
                base_size = 8; break;
            case TYPE_SIGNED_LONG_LONG:
            case TYPE_UNSIGNED_LONG_LONG:
                base_size = 8; break;
            case TYPE_VOID:
                base_size = 1; break;
            default:
                fprintf(stderr, "Unknown primitive type\n");
                return 0;
        }

        // recurse into any modifiers (like arrays)
        ast_node *next = type->val.primitive_type.next;
        if (!next) return base_size;
        long long unsigned int child_size = get_size_of_type(next);

        // For a primitive with modifier(s), we always evaluate bottom-up
        return (child_size == 0) ? base_size : child_size;
    }

    // Case: modifier node
    if (type->node_type == AST_TYPE_MOD) {
        long long unsigned int child_size = get_size_of_type(type->val.type_mod.next);

        switch (type->val.type_mod.modifier) {
            case CONSTANT_SIZED_ARRAY:
                return child_size * type->val.type_mod.array_size;
            case UNSIZED_ARRAY:
                fprintf(stderr, "sizeof unsized array is undefined\n");
                return 0;
            case POINTER:
                return 8; // size of any pointer
            default:
                return child_size;
        }
    }

    // Unknown or malformed node
    fprintf(stderr, "Unknown type node in get_size_of_type\n");
    return 0;
}