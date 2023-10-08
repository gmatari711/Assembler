#ifndef ASSEMBLER_INSTRUCTION_H
#define ASSEMBLER_INSTRUCTION_H
#include "adt_auxiliary.h"

typedef enum{
    IMMED,
    DIRECT,
    STRUCT,
    REGISTER
}operand_type;

DEFINE_ADT(inst_t);

inst_t inst_t_create();

void inst_t_destroy(inst_t *p_inst);

int inst_t_get_opcode(inst_t a_inst);

#endif
