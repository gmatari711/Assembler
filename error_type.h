#ifndef ASSEMBLER_ERROR_TYPE_H
#define ASSEMBLER_ERROR_TYPE_H
#include "adt_auxiliary.h"

DEFINE_ADT(err_t);
/**
 *
 * @param a_str
 * @param index
 * @return
 */
err_t err_t_create(char *a_str, int index);
/**
 *
 * @param ptr_err
 */
void err_t_delete(err_t *ptr_err);
/**
 *
 * @param a_err
 * @return
 */
char *err_t_get_message(err_t a_err);
/**
 *
 * @param a_err
 * @return
 */
int err_t_get_index(err_t a_err);

#endif
