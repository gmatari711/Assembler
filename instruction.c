#include "instruction.h"
DEFINE_DT(operand_t);

DT(operand_t){
    operand_type m_type;
    union{
        char    u_label[31];
        short   u_value;
    } value;
};

ADT(inst_t){
  int m_opcode;
  operand_t m_op1;
  operand_t m_op2;
};

inst_t inst_t_create(){
    inst_t result = NULL;
    ALLOCATE(result,inst_t);
    return result;
}

void inst_t_destroy(inst_t *p_inst){
    assert(NULL != p_inst && NULL != *p_inst);
    free(*p_inst);
    *p_inst = NULL;
}


