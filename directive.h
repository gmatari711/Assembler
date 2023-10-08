#ifndef ASSEMBLER_DIRECTIVE_H
#define ASSEMBLER_DIRECTIVE_H
#include "adt_auxiliary.h"
#include "error_type.h"

DEFINE_ADT(Directive);

typedef enum{
    DATA,
    STRING,
    STRUCT,
    EXTERN,
    ENTRY
}DirectiveType;

err_t dir_get_directive(Directive a_dir, char *string);

Directive dir_create();

void dir_destroy(Directive *p_dir);


#endif
