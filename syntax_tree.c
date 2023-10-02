#include "syntax_tree.h"
#include "syntax.h"
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 81
#define COMMA_STR ","
#define PARAN_STR "\""
#define PARAN '\"'
#define is_coma(c) (strcmp(c,COMMA_STR)==0?True:False)

typedef enum {
    LABEL,
    INSTRUCTION,
    DIRECTIVE,
    DEST_OPERAND,
    SRC_OPERAND,
}node_type;

typedef enum{
    BAD_DIR = -1,
    DATA,
    STRUCT,
    STRING,
    IMMED,
    ENTRY,
    EXTERN
}dir_type;




/* Syntax Tree different node types definitions. */
DEFINE_DT(inst_node);
DEFINE_DT(operand_node);
DEFINE_DT(data_node);
DEFINE_DT(string_node);
DEFINE_DT(struct_node);
DEFINE_DT(ext_node);
DEFINE_DT(ent_node);
DEFINE_DT(dir_node);


DT(ext_node){
  char label[31];
};

DT(ent_node){
    char label[31];
};

DT(data_node){
    int m_data[MAX_SIZE];
    size_t m_size;
};

DT(struct_node){
    int m_value;
    char m_string[MAX_SIZE];
};

DT(string_node){
    char m_string[MAX_SIZE];
};

DT(operand_node){
    unsigned int m_operand_type;
    union {
        unsigned int op_value;
        char label[MAX_SIZE];
    } operand_val;
};

DT(inst_node){
    unsigned int m_opcode;
    operand_node m_first_op;
    operand_node m_second_op;
};

DT(dir_node){
    dir_type m_dir_type;
    union {
        ent_node        u_ent;
        ext_node        u_ext;
        data_node       u_data;
        string_node     u_string;
        struct_node     u_struct;
    };
};


ADT(st_node){
    node_type m_identifier;
    union {
        dir_node    u_dir;
        inst_node   u_inst;
    }m_node;
};

ADT(syntax_tree){
    st_node  root;
};
/*  ***************************************  */

/**
 *
 * @param a_type
 * @param a_token
 * @return
 */
static st_node st_node_create(node_type a_type);
/**
 *
 * @param m_type
 * @param m_node
 * @param a_token
 * @return
 */
static err_t build_dir_node(dir_type a_type, st_node a_root, parser a_parser);
/**
 *
 * @param a_token
 * @return
 */
static dir_type get_dir_type(char *a_token);
/**
 *
 * @param a_parser
 * @param a_node_ptr
 * @return
 */
static err_t get_root(parser a_parser, st_node *a_root);
/**
 *
 * @param a_parser
 * @param a_node_ptr
 * @return
 */
static err_t build_directive_st(parser a_parser, st_node a_root);
/**
 *
 * @param a_parser
 * @param a_node_ptr
 * @return
 */
static err_t build_instruct_st(parser a_parser, st_node a_root);
/**
 *
 * @param m_node
 * @param a_parser
 * @return
 */
static err_t get_data(st_node a_root, parser a_parser);
/**
 *
 * @param a_parser
 * @param res
 * @return
 */
static err_t extract_string(parser a_parser, char *res);

static void st_insert_string(st_node a_root, char *string);

void syntax_tree_create(syntax_tree *a_st_ptr){
    ALLOCATE(*a_st_ptr,syntax_tree);
}

err_t st_parse(syntax_tree a_st, char *a_str){
    assert(NULL != a_str && NULL != a_st);
    err_t result = 0;
    parser  p = parser_create(" \t\n");
    parser_parse_text(p,a_str);
    result = get_root(p,&a_st->root);

    return result;
}

static err_t get_root(parser a_parser, st_node *a_root){
    err_t result = 0;
    assert(NULL != a_parser && NULL != a_root);
    if(parser_has_next(a_parser)){
        if(is_directive(parser_peak(a_parser)))
            result = build_directive_st(a_parser,*a_root);
        else
            result = build_instruct_st(a_parser,*a_root);
    }
    return result;
}

static err_t build_directive_st(parser a_parser, st_node a_root){
    char *token = NULL;
    err_t result = BAD_DIR_ERR;
    a_root->m_identifier = DATA;
    if(legal_directive(token = parser_pop(a_parser))){
        result = build_dir_node(get_dir_type(token),a_root, a_parser);
    }
    return result;
}

static err_t build_instruct_st(parser a_parser, st_node a_root){
}

static dir_type get_dir_type(char *a_token){
    if(strcmp(a_token,".data") == 0)
        return DATA;
    if(strcmp(a_token,".string") == 0)
        return STRING;
    if(strcmp(a_token,".struct") == 0)
        return STRUCT;
    if(strcmp(a_token,".extern") == 0)
        return EXTERN;
    if(strcmp(a_token,".entry") == 0)
        return ENTRY;
    return BAD_DIR;
}

static err_t build_dir_node(dir_type a_type, st_node a_root, parser a_parser){

}


static void st_insert_data(st_node a_root, long int a_data){
    a_root->m_node.u_dir.u_data.m_data[a_root->m_node.u_dir.u_data.m_size++];
}


static bool_t extract_data(parser a_parser, long int *pout){
    char *ptr = NULL;
    long int val = 0;

    val = strtol(parser_peak(a_parser),&ptr,10);
    if(*ptr != 0)
        return False;
    *pout = val;
    return True;
}


static err_t get_data(st_node a_root, parser a_parser){
    bool_t args_flag = False;
    long int val = 0;

    while(parser_has_next(a_parser)){
        if(args_flag && is_coma(parser_pop(a_parser)) == False)
            return MISSING_COMMA_ERR;
        if(extract_data(a_parser,&val) == False){
            if(is_coma(parser_peak(a_parser)))
                return args_flag?MULT_COMMAS_ERR:ILLEGAL_COMMA_ERR;
            return BAD_INT_ERR;
        }
        else if(!args_flag)
            args_flag = True;
        else
            st_insert_data(a_root,val);
        parser_pop(a_parser);
    }
    return (args_flag == True)? NO_ERR:MISSING_ARGS_ERR;
}
static void st_insert_struct(st_node a_root, char *a_str, long int a_val){

}


static err_t get_struct(st_node a_root, parser a_parser){
    long int val;
    char str[81] = {0};
    err_t result = NO_ERR;

    if(extract_data(a_parser,&val)== False)
        return (is_coma(parser_pop(a_parser)))?ILLEGAL_COMMA_ERR:BAD_INT_ERR;
    if(parser_has_next(a_parser) == False)
        return MISSING_ARGS_ERR;
    if(is_coma(parser_pop(a_parser)) == False)
        return MISSING_STRING_ERR;
    result = extract_string(a_parser,str);
    if(result != NO_ERR && parser_has_next(a_parser))
        return EXTRANEOUS_TEXT_ERR;
    if(result == NO_ERR){
        st_insert_struct(a_root,str,val);
    }
    return result;
}

static void st_insert_string(st_node a_root, char *string){
    strcpy(a_root->m_node.u_dir.u_string.m_string,string);
}

static err_t get_string(st_node a_root, parser a_parser){
    bool_t open_paran = False, close_paran = False;
    err_t result = NO_ERR;
    char str[81] ={0};
    if(!parser_has_next(a_parser))
        return MISSING_STRING_ERR;
    result = extract_string(a_parser,str);
    if(result != NO_ERR && parser_has_next(a_parser))
        return EXTRANEOUS_TEXT_ERR;
    if(result == NO_ERR)
        st_insert_string(a_root,str);
    return result;
}

static err_t extract_string(parser a_parser, char *res){
    char *token = NULL;
    assert(*res == 0 && NULL != a_parser);
    token = parser_pop(a_parser);
    /* Missing opening parentheses*/
    if(*token++ != PARAN)
        return MISSING_PARAN_ERR;
    while(token[strlen(token)-1] != PARAN){
        if(parser_has_next(a_parser) == False)
            return MISSING_PARAN_ERR;
        strcat(strcat(res,token), " ");
        token = parser_pop(a_parser);
    }
    token[strlen(token)-1] = 0;
    strcat(res,token);
    return NO_ERR;
}

st_node st_node_create(node_type a_type) {

}







