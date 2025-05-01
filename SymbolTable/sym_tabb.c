#include "sym_tab.h"
#include "../Parser/ast.h"

extern struct symbol_table_dll_node *CURRENT_SCOPE;

void init_global_table() {
    CURRENT_SCOPE = calloc(1, sizeof(struct symbol_table_dll_node));
    CURRENT_SCOPE->scope = TABLE_GLOBAL;
    /* CURRENT_SCOPE->prev = NULL; */
    CURRENT_SCOPE->table = (struct symbol_table) {0};
    CURRENT_SCOPE->table.first = NULL;
}

struct symbol_table_entry_ll_node *create_new_blank_entry() {
    struct symbol_table_entry_ll_node *current_node = CURRENT_SCOPE->table.first;
    if (current_node) {
        while (current_node->next) {
            current_node = current_node->next;
        }
        current_node->next = calloc(1, sizeof(struct symbol_table_entry_ll_node));
        return current_node->next;
    } else {
        CURRENT_SCOPE->table.first = calloc(1, sizeof(struct symbol_table_entry_ll_node));
        return CURRENT_SCOPE->table.first;
    }
}

struct symbol_table_dll_node *new_scope(enum TABLE_SCOPE scope) {
    struct symbol_table_dll_node *new_scope = calloc(1, sizeof(struct symbol_table_dll_node));
    new_scope->prev = CURRENT_SCOPE;
    new_scope->scope = scope;
    new_scope->table = (struct symbol_table) {0};
    CURRENT_SCOPE = new_scope;
    return new_scope;
}

int exit_scope() {
    if (!CURRENT_SCOPE->prev) {
        return 1;
    }
    CURRENT_SCOPE = CURRENT_SCOPE->prev;
    return 0;
}

void insert_symbol_var(char *name, enum SYMBOL_SCOPE scope, enum STORAGE_CLASS storage) {
    struct symbol_table_entry_ll_node *node = create_new_blank_entry();
    node->name = name;
    node->role = SYM_VAR;
    node->specs.variable.scope = scope;
    node->specs.variable.storage = storage;
    /* node->specs.variable.type = NULL; */
}

void insert_symbol_fn(char *name, enum SYMBOL_SCOPE scope) {
    struct symbol_table_entry_ll_node *node = create_new_blank_entry();
    node->name = name;
    node->role = SYM_FUNC;
    node->specs.function.scope = scope;
    /* node->specs.function.return_type = NULL; */
    /* node->specs.function.content = NULL; */
    /* node->specs.function.defined = 0; */
    node->specs.function.context_table = new_scope(TABLE_FUNCTION);
}

void insert_symbol_lab(char *name, enum SYMBOL_SCOPE scope) {
    struct symbol_table_entry_ll_node *node = create_new_blank_entry();
    node->name = name;
    node->role = SYM_LABEL;
    node->specs.variable.scope = scope;
    /* node->specs.label.is_defined = 0; */
    /* node->specs.label.jump_loc = NULL; */
}