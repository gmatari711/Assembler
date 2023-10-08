#ifndef ASSEMBLER_ASSEMBLY_UNIT_H
#define ASSEMBLER_ASSEMBLY_UNIT_H

#include "adt_auxiliary.h"
#include "error_type.h"

DEFINE_ADT(assembly_unit);
/**
 * An abstract unit to extract next line instruction or directive
 * @param a_asu
 * @param line
 * @return
 */
err_t assembly_unit_process_line(assembly_unit a_asu, char *line);


#endif
