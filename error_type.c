#include "error_type.h"

typedef enum{
    SYNTAX_ERR,
    SEMANTIC_ERR
}ERROR_TYPE;

ADT(err_t){
    ERROR_TYPE m_type;
    char m_label[256];
};
