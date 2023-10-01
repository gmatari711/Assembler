#ifndef ASSEMBLER_ADT_AUXILIARY_H
#define ASSEMBLER_ADT_AUXILIARY_H
#include <stdlib.h>
#include <assert.h>
#define ALLOCATE(TARGET,TYPE) TARGET = (TYPE)calloc(sizeof(struct TYPE),1); \
                   assert(TARGET != NULL)
#define ALLOCATE_ARR(TARGET,TYPE,N) (TYPE)calloc(sizeof(struct TYPE),N); \
                   assert(TARGET != NULL)
#define ADT(x) struct x
#define DEFINE_ADT(x) typedef ADT(x) *x
#define DT(x) struct x
#define DEFINE_DT(x) typedef DT(x) x

#define nullobj NULL
typedef         void (*destroy)(void **);
typedef         int(*objectCMP)(const void * ,const void *);
typedef         int(*object_key_cmp)(const void * ,const void *);

typedef void *item;
typedef char byte_t;
typedef enum _bool{True = 1, False = 0 }bool_t;

#endif
