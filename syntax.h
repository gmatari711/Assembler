#ifndef ASSEMBLER_SYNTAX_H
#define ASSEMBLER_SYNTAX_H

#include "adt_auxiliary.h"

#define DIRECTIVE_PREFIX '.'


DEFINE_ADT(instruct);
DEFINE_ADT(direct);

#define is_directive(TOKEN) *(TOKEN) == DIRECTIVE_PREFIX

/**
 *
 * @param a_token
 * @return
 */
bool_t is_label(char *a_token);
/**
 *
 * @param a_token
 * @return
 */
bool_t is_register(char *a_token);
/**
 *
 * @param a_token
 * @return
 */
bool_t is_data(char *a_token);
/**
 *
 * @param a_token
 * @return
 */
bool_t is_string(char *a_token);
/**
 *
 * @param a_token
 * @return
 */
bool_t is_struct(char *a_token);
/**
 *
 * @param a_token
 * @return
 */
bool_t legal_inst(char *a_token);
/**
 *
 * @param a_token
 * @return
 */
bool_t legal_directive(char *a_token);
/**
 *
 * @param a_token
 * @return
 */
bool_t legal_operand(char *a_token);
/**
 *
 * @param a_token
 * @return
 */
unsigned int get_operand_type(char *a_token);
/**
 *
 * @param a_token
 * @return
 */
unsigned int get_opcode(char *a_token);
/**
 *
 * @param a_token
 * @return
 */
unsigned int get_directive(char *a_token);

#endif