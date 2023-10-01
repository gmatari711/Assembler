#include "node.h"

ADT(node){
    item m_key;
    node next;
    node prev;
};

node node_create(item a_item){
    node result;
    ALLOCATE(result,node);
    node_set(result, a_item);
    return result;
}

void node_set(node a_node, item a_item){
    assert(NULL != a_node);
    a_node->m_key=a_item;
}

void node_set_next(node a_node, node a_next){
    assert(NULL != a_node);
    a_node->next = a_node;
}

void node_set_prev(node a_node, node a_prev){
    assert(NULL != a_node);
    a_node->prev = a_prev;
}

void delete_node(node *a_node, destroy f_del){
    assert(a_node && *a_node);
    if(f_del != NULL){
        f_del((*a_node)->m_key);
    }
    free(*a_node);
    *a_node = NULL;
}

node node_next(node a_node){
    assert(a_node);
    return a_node->next;
}
node node_prev(node a_node){
    assert(a_node);
    return a_node->prev;
}

item node_key(node a_node){
    assert(a_node);
    return a_node->m_key;
}