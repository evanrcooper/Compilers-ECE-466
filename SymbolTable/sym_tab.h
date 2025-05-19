#ifndef SYMTAB_H
#define SYMTAB_H

#include "../Parser/ast.h"

#define PRINT_VARIABLE_TYPE 0

#define PRINT_FUNCTION_RETURN_TYPE 0
#define PRINT_FUNCTION_CONTENT 0
#define PRINT_FUNCTION_SYMBOL_TABLE 0

#define PRINT_LABEL_JUMP_LOCATION 0

#define PRINT_ALL_SYMBOL_INFO_FROM_TABLE 0

enum SYMBOL_ROLE {
    SYM_VAR = 1,
    SYM_FUNC,
    SYM_TYPDEF,
    SYM_STRUCT,
    SYM_ENUM,
    SYM_MEMBER,
    SYM_LABEL,
};

enum SYMBOL_SCOPE {
    SYM_LOCAL = 1,
    SYM_GLOBAL,
    SYM_BLOCK,
};

enum TABLE_SCOPE {
    TABLE_GLOBAL = 1,
    TABLE_FUNCTION,
    TABLE_BLOCK,
};

struct symbol_table_entry_ll_node {
    enum SYMBOL_ROLE role;
    char *name;
    struct symbol_table_entry_ll_node *next;
    enum SYMBOL_SCOPE scope;
    struct symbol_table_dll_node *table_scope;
    /* int line_declared;
     char *filename; */
    union {
        struct {
            char is_defined;
            enum storage_class storage;
            ast_node *type;
            int relative_address;
        } variable;
        struct {
            ast_node *return_type;
            ast_node *content;
            struct symbol_table_dll_node *context_table;
        } function;
        struct {
            char is_defined;
            ast_node *jump_loc;
        } label;
    } specs;
};

struct symbol_table {
    struct symbol_table_entry_ll_node *first;
};

struct symbol_table_dll_node {
    struct symbol_table_dll_node *prev;
    enum TABLE_SCOPE scope;
    struct symbol_table table;
};

void init_global_table();
struct symbol_table_entry_ll_node *create_new_blank_entry();
struct symbol_table_dll_node *new_scope(enum TABLE_SCOPE scope);
int exit_scope();
struct symbol_table_entry_ll_node* insert_symbol_var(char *name, enum SYMBOL_SCOPE scope, enum storage_class storage);
struct symbol_table_entry_ll_node* insert_symbol_fn(char *name, enum SYMBOL_SCOPE scope);
struct symbol_table_entry_ll_node* insert_symbol_lab(char *name, enum SYMBOL_SCOPE scope);
void print_indents(int indents);
void print_symbol_role(struct symbol_table_entry_ll_node *node, int indents);
void print_symbol_scope(struct symbol_table_entry_ll_node *node, int indents);
void print_variable(struct symbol_table_entry_ll_node *node, int indents);
void print_function(struct symbol_table_entry_ll_node *node, int indents);
void print_label(struct symbol_table_entry_ll_node *node, int indents);
void print_symbol(struct symbol_table_entry_ll_node *node, int indents);
void print_symbol_table_scope(struct symbol_table_dll_node *table, int indents);
void print_symbol_table(struct symbol_table_dll_node *table, int indents);
struct symbol_table_entry_ll_node* find_symbol_in_table(char *name, struct symbol_table_dll_node *table);
struct symbol_table_entry_ll_node* find_symbol_in_scope(char *name, struct symbol_table_dll_node *deepest_scope);
ast_node* build_full_type_from_declarator(ast_node *declarator, struct type_builder *builder);

#endif // SYMTAB_H