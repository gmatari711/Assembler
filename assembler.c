#include "assembler.h"
#include "stdio.h"
#include "queue.h"
#include "assembly_unit.h"


ADT(assembler){
    FILE *m_source_file;
    FILE *m_pre_assembler_file;
    FILE *m_output_file;
    queue err_list;

};
