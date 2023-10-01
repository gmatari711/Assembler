#include "list.h"
#include "node.h"



ADT(list)
{
    node m_head;
    node m_tail;
};

list list_create(){
    list result;
    ALLOCATE(result,list);
    return result;
}

void delete_list(list *a_list, destroy f_delete){
    node current = NULL;
    while(NULL != (current = (*a_list)->m_head)){
        (*a_list)->m_head = node_next((*a_list)->m_head);
        delete_node(&current,f_delete);
    }
}

void list_push_back(list a_list, item a_item){
    node new_node;
    new_node = node_create(a_item);
    assert(a_list);
    if(list_empty(a_list) == True){
        a_list->m_head = a_list->m_tail = new_node;
    }
    else{
        node_set_next(a_list->m_tail,new_node);
        node_set_prev(new_node,a_list->m_tail);
        a_list->m_tail = new_node;
    }
}

void list_push_front(list a_list, item a_item){
    node new_node;
    new_node = node_create(a_item);
    assert(a_list);
    if(list_empty(a_list) == True){
        a_list->m_head = a_list->m_tail = new_node;
    }
    else{
        node_set_next(new_node, a_list->m_head);
        node_set_prev(a_list->m_head,new_node);
        a_list->m_head = new_node;
    }
}


item list_search(list a_list, void *a_key, object_key_cmp f_compare)
{

}

void list_remove(list a_list, void *a_key, object_key_cmp f_compare, destroy f_del)
{

}

bool_t list_empty(list a_list)
{
    return (a_list->m_head == NULL)?True:False;
}