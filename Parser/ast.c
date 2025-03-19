#include "ast.h"

char *unop_to_char(enum unop_type type) {
    char *ret_str;
    char *msg;
    switch (type) {
        case U_ADDRESSOF:
            msg = "!";
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
        case B_ASSIGN_LIST:
            msg = ", (ASSIGN LIST)";
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
            printf("CHAR: %c\n", node->val.charlit.val);
            break;
        case AST_STRLIT:
            printf("STRING: %s\n", node->val.strlit.val);
            break;
        case AST_IDENT:
            printf("IDENT: %s\n", node->val.ident.ident_name);
            break;
        case AST_UNOP:
            op = unop_to_char(node->val.unop.op);
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