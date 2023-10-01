#include "syntax.h"

#define MAX_INST_STR 5

ADT(instruct){
    char m_name[MAX_INST_STR];
    size_t m_opcode;
};
