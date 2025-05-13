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

// RESPONSIBILITY OF CALLER TO ASSERT THAT SYMBOL WITH 
// THE NAME PROVIDED IS NOT ALLREADY IN DEEPEST SCOPE 

struct symbol_table_entry_ll_node* insert_symbol_var(char *name, enum SYMBOL_SCOPE scope, enum storage_class storage) {
    struct symbol_table_entry_ll_node *node = create_new_blank_entry();
    node->name = name;
    node->role = SYM_VAR;
    node->scope = scope;
    node->specs.variable.storage = storage;
    node->table_scope = CURRENT_SCOPE;
    /* node->specs.variable.type = NULL; */
    /* node->relative_address = 0;*/
    return node;
}

struct symbol_table_entry_ll_node* insert_symbol_fn(char *name, enum SYMBOL_SCOPE scope) {
    struct symbol_table_entry_ll_node *node = create_new_blank_entry();
    node->name = name;
    node->role = SYM_FUNC;
    node->scope = scope;
    node->table_scope = CURRENT_SCOPE;
    /* node->specs.function.return_type = NULL; */
    // node->specs.function.content = NULL;
    /* node->specs.function.defined = 0; */
    return node;
}

struct symbol_table_entry_ll_node* insert_symbol_lab(char *name, enum SYMBOL_SCOPE scope) {
    struct symbol_table_entry_ll_node *node = create_new_blank_entry();
    node->name = name;
    node->role = SYM_LABEL;
    node->scope = scope;
    node->table_scope = CURRENT_SCOPE;
    /* node->specs.label.is_defined = 0; */
    /* node->specs.label.jump_loc = NULL; */
    return node;
}

void print_indents(int indents) {
    for (int i = 0; i < indents; i++) {
        printf("-- ");
    }
}

void print_symbol_role(struct symbol_table_entry_ll_node *node, int indents) {
    print_indents(indents);
    printf("ROLE: ");
    switch (node->role) {
            case SYM_VAR:
                printf("SYM_VAR\n");
                break;
            case SYM_FUNC:
                printf("SYM_FUNC\n");
                break;
            case SYM_TYPDEF:
                printf("SYM_TYPDEF\n");
                break;
            case SYM_STRUCT:
                printf("SYM_STRUCT\n");
                break;
            case SYM_ENUM:
                printf("SYM_ENUM\n");
                break;
            case SYM_MEMBER:
                printf("SYM_MEMBER\n");
                break;
            case SYM_LABEL:
                printf("SYM_LABEL\n");
                break;
            default:
                printf("UNKNOWN SYMBOL ROLE\n");
                break;
    }
    return;
}

void print_symbol_scope(struct symbol_table_entry_ll_node *node, int indents) {
    print_indents(indents);
    printf("SCOPE: ");
    switch (node->scope) {
        case SYM_LOCAL:
            printf("SYM_LOCAL\n");
            break;
        case SYM_GLOBAL:
            printf("SYM_GLOBAL\n");
            break;
        case SYM_BLOCK:
            printf("SYM_BLOCK\n");
            break;
        default:
            printf("UNKNOWN SYMBOL ROLE\n");
            break;
    }
    return;
}

void print_variable(struct symbol_table_entry_ll_node *node, int indents) {
    print_indents(indents);
    printf("STORAGE CLASS: ");
    switch (node->specs.variable.storage) {
        case SC_EXTERN_EXPLICIT:
            printf("CLASS_EXTERN_EXPLICIT\n");
            break;
        case SC_EXTERN_IMPLICIT:
            printf("CLASS_EXTERN_IMPLICIT\n");
            break;
        case SC_STATIC:
            printf("CLASS_STATIC\n");
            break;
        case SC_AUTO:
            printf("CLASS_AUTO\n");
            break;
        case SC_REGISTER:
            printf("CLASS_REGISTER\n");
            break;
        default:
            printf("UNKNOWN STORAGE CLASS\n");
            break;
    }
    print_indents(indents);
    if (node->specs.variable.is_defined) {
        printf("DEFINED\n");
    } else {
        printf("NOT DEFINED\n");
    }
    if (PRINT_VARIABLE_TYPE) {
        printf("TYPE: \n");
        print_ast_node(indents+1, node->specs.variable.type);
    }
    return;
}

void print_function(struct symbol_table_entry_ll_node *node, int indents) {
    if (PRINT_FUNCTION_RETURN_TYPE) {
        printf("RETURN TYPE: \n");
        print_ast_node(indents+1, node->specs.function.return_type);
    }
    if (PRINT_FUNCTION_CONTENT) {
        printf("CONTENT: \n");
        print_ast_node(indents+1, node->specs.function.content);
    }
    // if (PRINT_FUNCTION_SYMBOL_TABLE) {
    //     printf("SYMBOL_TABLE: \n");
    //     print_symbol_table(node->specs.function.context_table, indents+1);
    // }
    return;
}

void print_label(struct symbol_table_entry_ll_node *node, int indents) {
    if (node->specs.label.is_defined) {
        printf("DEFINED\n");
        if (PRINT_LABEL_JUMP_LOCATION) {
            printf("JUMP LOCATION: \n");
            print_ast_node(indents+1, node->specs.label.jump_loc);
        }
    } else {
        printf("NOT DEFINED\n");
    }
}

void print_symbol(struct symbol_table_entry_ll_node *node, int indents) {
    print_indents(indents);
    printf("NAME: %s\n", node->name);
    print_symbol_role(node, indents);
    print_symbol_scope(node, indents);
    switch (node->role) {
        case SYM_VAR:
            print_variable(node, indents);
            break;
        case SYM_FUNC:
            print_function(node, indents);
            break;
        case SYM_LABEL:
            print_label(node, indents);
            break;
        default:
            break;
    }
    return;
}

void print_symbol_table_scope(struct symbol_table_dll_node *symbol_table, int indents) {
    print_indents(indents);
    printf("TABLE SCOPE: ");
    switch (symbol_table->scope) {
        case TABLE_GLOBAL:
            printf("TABLE_GLOBAL\n");
            break;
        case TABLE_FUNCTION:
            printf("TABLE_FUNCTION\n");
            break;
        case TABLE_BLOCK:
            printf("TABLE_BLOCK\n");
            break;
        default:
            printf("UNKNOWN TABLE SCOPE\n");
            break;
    }
    return;
}

void print_symbol_table(struct symbol_table_dll_node *symbol_table, int indents) {
    print_symbol_table_scope(symbol_table, indents);
    struct symbol_table_entry_ll_node *current = symbol_table->table.first;
    while (current) {
        if (PRINT_ALL_SYMBOL_INFO_FROM_TABLE) {
            print_symbol(current, indents);
        } else {
            print_indents(indents);
            printf("NAME: %s\n", current->name);
        }
        current = current->next;
    }
    return;
}

struct symbol_table_entry_ll_node* find_symbol_in_scope(char *name, struct symbol_table_dll_node *deepest_scope) {
    struct symbol_table_dll_node *current = deepest_scope;
    struct symbol_table_entry_ll_node *node;
    while (current) {
        node = find_symbol_in_table(name, current);
        if (node) {
            return node;
        }
        current = current->prev;
    }
    return NULL;
}

struct symbol_table_entry_ll_node* find_symbol_in_table(char *name, struct symbol_table_dll_node *table) {
    struct symbol_table_entry_ll_node *current = table->table.first;
    while (current) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

enum TABLE_SCOPE get_scope_type() {
    return CURRENT_SCOPE->scope;
}

ast_node* build_full_type_from_declarator(ast_node *declarator, struct type_builder *builder) {
    ast_node *base_type = create_primitive_type_node(get_primitive_type(*builder));
    ast_node *type = declarator;

    ast_node *tail = base_type;

    while (type) {
        if (type->node_type == AST_TYPE_MOD) {
            type->val.type_mod.next = tail;
            tail = type;
            type = type->val.type_mod.next;
        } else if (type->node_type == AST_UNOP && type->val.unop.op == U_FUNCTION_TYPE) {
            type->val.unop.center = tail;
            tail = type;
            break;
        } else {
            break;
        }
    }
    return tail;
}
