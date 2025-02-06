enum unop_type { // op1 id1
    NOT, // !
    BIT_NOT, // ~
    PLUS, // +
    MINUS, // -
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
    XOREQ, // ^=
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
    union val {
        long long int_val;
        long double real_val;
    };
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

typedef struct ast_node {
    enum ast_node_type node_type;
    union ast_node_val {
        struct ast_node_binop unop;
        struct ast_node_binop binop;
        struct ast_node_binop triop;
        struct ast_node_numlit numlit;
        struct ast_node_ident ident;
        struct ast_node_charlit charlit;
        struct ast_node_charlit strlit;
        /* ... */
    };
} ast_node;

int main() {
    char a = '\A';
    return 0;
}