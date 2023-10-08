#include "assembly_unit.h"
#include "directive.h"
#include "instruction.h"

typedef enum{
    INSTRUCTION,
    DIRECTORY
}unit_type;

ADT(assembly_unit){
    unit_type m_unit_type;
    union{
        inst_t  u_inst;
        dir_t   u_dir;
    } m_unit;
};
