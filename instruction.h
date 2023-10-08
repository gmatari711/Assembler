#ifndef ASSEMBLER_INSTRUCTION_H
#define ASSEMBLER_INSTRUCTION_H
#include "adt_auxiliary.h"

typedef enum{
    IMMED,
    DIRECT,
    STRUCT,
    REGISTER
}operand_type;

DEFINE_ADT(Isntruction);

Isntruction inst_t_create();

void inst_t_destroy(Isntruction *p_inst);

int inst_t_get_opcode(Isntruction a_inst);

#endif
