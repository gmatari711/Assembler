#ifndef ASSEMBLER_NODE_H
#define ASSEMBLER_NODE_H
#include "adt_auxiliary.h"

DEFINE_ADT(node);
/**
 *
 * @param a_item
 * @return
 */
node node_create(item a_item);
/**
 *
 * @param a_node
 * @param f_del
 */
void delete_node(node *a_node, destroy f_del);
/**
 *
 * @param a_node
 * @return
 */
node node_next(node a_node);
/**
 *
 * @param a_node
 * @return
 */
node node_prev(node a_node);
/**
 *
 * @param a_node
 * @return
 */
item node_key(node a_node);
/**
 *
 * @param a_node
 * @param a_item
 */
void node_set(node a_node, item a_item);
/**
 *
 * @param a_node
 * @param a_prev
 */
void node_set_prev(node a_node, node a_prev);
/**
 *
 * @param a_node
 * @param a_next
 */
void node_set_next(node a_node, node a_next);
#endif
