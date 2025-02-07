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

int main() {
    
    ast_node p;
    ast_node l1;
    ast_node l2;
    ast_node r2;
    ast_node r1;
    ast_node c1;

    char *l1_name = "ident_name";

    p.node_type = BINOP;
    p.val.binop.op = TIMES;
    p.val.binop.left = &l1;
    p.val.binop.right = &r1;

    l1.node_type = IDENT;
    l1.val.ident.ident_name = l1_name;

    r1.node_type = BINOP;
    r1.val.binop.op = LOG_AND;
    r1.val.binop.left = &l2;
    r1.val.binop.right = &r2;

    l1.node_type = IDENT;
    l1.val.ident.ident_name = l1_name;

    l2.node_type = UNOP;
    l2.val.unop.op = NEG;
    l2.val.unop.center = &c1;

    c1.node_type = NUMLIT;
    c1.val.numlit.type = LLI;
    c1.val.numlit.val.int_val = 16;

    r2.node_type = NUMLIT;
    r2.val.numlit.type = LLI;
    r2.val.numlit.val.int_val = 18;

    print_ast_node(0, &p);

    return 0;
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