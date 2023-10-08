#include "error_type.h"
#include <string.h>

ADT(err_t){
    char m_message[81];
    int err_index;
};


err_t err_t_create(char *a_str, int index){
    err_t result = NULL;
    assert(NULL != a_str);
    ALLOCATE(result,err_t);

    strcpy(result->m_message, a_str);
    result->err_index = index;

    return result;
}


void err_t_delete(err_t *ptr_err){
    assert(NULL != ptr_err && NULL != *ptr_err);
    free(*ptr_err);
    *ptr_err = NULL;
}


char *err_t_get_message(err_t a_err){
    assert(NULL != a_err);
    return a_err->m_message;
}


int err_t_get_index(err_t a_err){
    return a_err->err_index;
}
