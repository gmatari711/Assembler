#ifndef ASSEMBLER_DIRECTIVE_H
#define ASSEMBLER_DIRECTIVE_H
#include "adt_auxiliary.h"
#include "error_type.h"

DEFINE_ADT(dir_t);

typedef enum{
    DATA,
    STRING,
    STRUCT,
    EXTERN,
    ENTRY
}dir_type;

err_t dir_get_directive(dir_t a_dir, char *string);



#endif
