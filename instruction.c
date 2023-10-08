#include "instruction.h"
DEFINE_DT(operand_t);

DT(operand_t){
    operand_type m_type;
    union{
        char    u_label[31];
        short   u_value;
    } value;
};

ADT(Isntruction){
  int m_opcode;
  operand_t m_op1;
  operand_t m_op2;
};

Isntruction inst_t_create(){
    Isntruction result = NULL;
    ALLOCATE(result,Isntruction);
    return result;
}

void inst_t_destroy(Isntruction *p_inst){
    assert(NULL != p_inst && NULL != *p_inst);
    free(*p_inst);
    *p_inst = NULL;
}


