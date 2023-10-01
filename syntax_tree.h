#ifndef ASSEMBLER_SYNTAX_TREE_H
#define ASSEMBLER_SYNTAX_TREE_H

#include "adt_auxiliary.h"
#include "parser.h"
#include "error_type.h"

DEFINE_ADT(syntax_tree);
DEFINE_ADT(st_node);

/**
 *
 * @param a_parser
 * @param a_ast_ptr
 * @return
 */
err_t st_create(parser a_parser, syntax_tree *a_ast_ptr);
/**
 *
 * @param a_ptr_ast
 */
void st_destroy(syntax_tree *a_ptr_ast);


#endif //ASSEMBLER_SYNTAX_TREE_H
