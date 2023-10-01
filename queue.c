#include "queue.h"
#include "list.h"

struct queue{
    list m_top;
    size_t m_size;
};

queue queue_create(){
    queue result = calloc(1,sizeof(struct queue));
    assert(NULL != result);
    return result;
}

void queue_destroy(queue *a_queue_ptr){
    assert(NULL != a_queue_ptr && NULL != *a_queue_ptr);
    delete_list(&(*a_queue_ptr)->m_top,NULL);
    free(*a_queue_ptr);
    *a_queue_ptr=NULL;
}





