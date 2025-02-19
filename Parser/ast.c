#include "ast.h"

void print_ast_tree(ast_node *root) {
    print_ast_node(0, root);
}

char *unop_to_char(enum unop_type type) {
    char *ret_str;
    char *msg;
    switch (type) {
        case NOT:
            msg = "!";
            break;
        case BIT_NOT:
            msg = "~";
            break;
        case POS:
            msg = "+";
            break;
        case NEG:
            msg = "-";
            break;
        case PRE_PLUSPLUS:
            msg = "++i";
            break;
        case PRE_MINUSMINUS:
            msg = "--i";
            break;
        case POST_PLUSPLUS:
            msg = "i++";
            break;
        case POST_MINUSMINUS:
            msg = "i--";
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
        case PLUS:
            msg = "+";
            break;
        case MINUS:
            msg = "-";
            break;
        case TIMES:
            msg = "*";
            break;
        case DIVIDE:
            msg = "/";
            break;
        case BIT_AND:
            msg = "&";
            break;
        case BIT_OR:
            msg = "|";
            break;
        case BIT_XOR:
            msg = "^";
            break;
        case MOD:
            msg = "%";
            break;
        case LT:
            msg = "<";
            break;
        case GT:
            msg = ">";
            break;
        case LTEQ:
            msg = "<=";
            break;
        case GTEQ:
            msg = ">=";
            break;
        case EQEQ:
            msg = "==";
            break;
        case NOTEQ:
            msg = "!=";
            break;
        case LOG_AND:
            msg = "&&";
            break;
        case LOG_OR:
            msg = "||";
            break;
        case SHL:
            msg = "<<";
            break;
        case SHR:
            msg = ">>";
            break;
        case EQ:
            msg = "=";
            break;
        case TIMESEQ:
            msg = "*=";
            break;
        case DIVEQ:
            msg = "/=";
            break;
        case MODEQ:
            msg = "%=";
            break;
        case PLUSEQ:
            msg = "+=";
            break;
        case MINUSEQ:
            msg = "-=";
            break;
        case SHLEQ:
            msg = "<<=";
            break;
        case SHREQ:
            msg = ">>=";
            break;
        case BIT_ANDEQ:
            msg = "&=";
            break;
        case BIT_OREQ:
            msg = "|=";
            break;
        case BIT_XOREQ:
            msg = "^=";
            break;
        default:
            msg = "N/A";
            break;
    }
    ret_str = malloc(strlen(msg) + 1);
    strcpy(ret_str, msg);
    return ret_str;
}

char *triop_to_char(enum triop_type type) {
    char *ret_str;
    char *msg;
    switch (type) {
        case TERNARY:
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

void print_ast_node(int depth, ast_node *node) {
    char *op;
    for (int i = 0; i < depth; i++) {
        printf("-- ");
    }
    switch (node->node_type) {
        case NUMLIT:
            switch (node->val.numlit.type) {
                case LLF:
                    printf("FLOAT: %Lf\n", node->val.numlit.val.real_val);
                    break;
                case LLI:
                    printf("INT: %lld\n", node->val.numlit.val.int_val);
                    break;
            }
            break;
        case CHARLIT:
            printf("CHAR: %c\n", node->val.charlit.val);
            break;
        case STRLIT:
            printf("STRING: %s\n", node->val.strlit.val);
            break;
        case IDENT:
            printf("IDENT: %s\n", node->val.ident.ident_name);
            break;
        case UNOP:
            op = unop_to_char(node->val.unop.op);
            printf("UNOP: %s\n", op);
            free(op);
            print_ast_node(depth + 1, node->val.unop.center);
            break;
        case BINOP:
            op = binop_to_str(node->val.binop.op);
            printf("BINOP: %s\n", op);
            free(op);
            print_ast_node(depth + 1, node->val.binop.left);
            print_ast_node(depth + 1, node->val.binop.right);
            break;
        case TRIOP:
            op = unop_to_char(node->val.triop.op);
            printf("TRIOP: %s\n", op);
            free(op);
            print_ast_node(depth + 1, node->val.triop.left);
            print_ast_node(depth + 1, node->val.triop.center);
            print_ast_node(depth + 1, node->val.triop.right);
            break;
        default:
            printf("\rERROR\n");
            break;
    }
}

ast_dll dll_create() {
    return (ast_dll) {0};
}

ast_dll* dll_append(ast_dll *dll, ast_dll_node *node) {
    dll->count++;
    dll->tail->next = node;
    dll->tail = dll->tail->next;
}