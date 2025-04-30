#ifndef SYMTAB_H
#define SYMTAB_H

#include "../Parser/ast.h"

enum SYMBOL_ROLE {
    SYM_VAR = 1,
    SYM_FUNC,
    SYMDEF,
    SYM_STRUCT,
    SYM_ENUM,
    SYM_MEMBER,
    SYM_LABEL,
};

enum SYMBOL_SCOPE {
    SYM_LOCAL = 1,
    SYM_GLOBAL,
    SYM_PARAM,
    SYM_BLOCK,
    SYM_PROTOTYPE,
};

enum TABLE_SCOPE {
    TABLE_GLOBAL = 1,
    TABLE_FUNCTION,
    TABLE_BLOCK,
    TABLE_PROTOTYPE,
};

enum STORAGE {
    CLASS_EXTERN = 1,
    CLASS_STATIC,
    CLASSDEF,
    CLASS_AUTO,
    CLASS_REGISTER,
};

enum TYPE_SPECIFIERS {
    TYPE_INT = 1,
    TYPE_CHAR,
    TYPE_VOID,
    TYPE_FLOAT,
    TYPE_DOUBLE,
    TYPE_STRUCT,
};

struct symbol_table_entry_ll_node {
    char *name;
    enum SYMBOL_ROLE role;
    ast_node *type;
    struct symbol_table_entry_ll_node *next;
};

struct symbol_table {
    struct symbol_table_entry_ll_node *first;
};

struct symbol_table_dll_node {
    struct symbol_table_dll_node *next;
    struct symbol_table_dll_node *prev;
    enum TABLE_SCOPE scope;
    struct symbol_table *table;
};

#endif // SYMTAB_H