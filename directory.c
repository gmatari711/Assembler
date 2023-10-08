#include "directory.h"

typedef enum{
    DATA,
    STRING,
    STRUCT,
    EXTERN,
    ENTRY
}DIR_TYPE;

DEFINE_DT(data_node);
DEFINE_DT(struct_node);
DEFINE_DT(string_node);

DT(data_node){
    size_t m_size;
    long int m_data[80];
};

DT(string_node){
  char m_string[81];
};

DT(struct_node){
    long int m_value;
    char m_string[81];
};



DT(dir_t){
    int m_data_type;
    union{
        data_node   u_data;
        string_node u_string;
        struct_node u_struct;
        char        u_entry[31];
        char        u_extern[31];
    } m_dir_type;
};
