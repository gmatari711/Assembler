#ifndef ASSEMBLER_LIST_H
#define ASSEMBLER_LIST_H
#include "adt_auxiliary.h"
#ifndef LIST_TYPE_DEF
#define LIST_TYPE_DEF

DEFINE_ADT(list);


#endif


/**
 *
 * @return
 */
list list_create();
/**
 * Free all allocated memory for a List container object.
 * @param a_list A pointer to a List container object.
 * @param f_delete A destructor function for items containd in *a_list.
 */
void delete_list(list *a_list, destroy f_delete);

void list_push_back(list a_list, item);

void list_push_front(list a_list, item);

item list_search(list a_list, void *a_key, object_key_cmp f_compare);

void list_remove(list a_list, void *a_key, object_key_cmp f_compare, destroy f_del);

bool_t list_empty(list a_list);




#endif
