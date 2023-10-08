#include "assembly_unit.h"
#include "directive.h"
#include "instruction.h"

typedef enum{
    INSTRUCTION,
    DIRECTORY
}unit_t;

ADT(assembly_unit){
    unit_t m_unit;
    union{
        inst_t  u_inst;
        dir_t   u_dir;
    };
};
