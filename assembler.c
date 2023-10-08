#include "assembler.h"
#include "stdio.h"
#include "error_type.h"
#include "queue.h"

ADT(assembler){
    FILE *m_source_file;
    FILE *m_pre_assembler_file;
    FILE *m_output_file;
    queue err_list;

};
