#include "parser.h"
#include <stdlib.h>
#include <string.h>

#define WS " \n\t"
#define ASCII_SYMBOLS 127

/**
 *
 * @param a_source
 * @return
 */
static char* str_duplicate(const char *a_source);
/**
 * Converts the input string by inserting spaces around the separator characters defined in the parser's separator list.
 *
 * @param a_parser The parser object.
 * @param a_source The input string to be converted.
 */
static void str_space_separators(parser a_parser,const char *a_source);
/**
 * Sets the separator list for the parser.
 *
 * @param a_parser The parser object.
 * @param a_sep_list The separator list to be set.
 */
static void set_separator_list(parser a_parser, const char *a_sep_list);
/**
 * Tokenizes the source string using whitespace as the delimiter and stores the tokens in the parser's token list.
 *
 * @param a_parser The parser object.
 */
static void get_tokens(parser a_parser);
/**
 * Clears the parser object and frees any allocated memory.
 *
 * @param a_parser The parser object to be cleared.
 */
static void clear_parser(parser a_parser);
/**
 * Checks if the parser object is empty, i.e., if both the source string and token list are not NULL.
 *
 * @param a_parser The parser object to be checked.
 * @return True if the parser object is empty, False otherwise.
 */
static bool_t is_empty(parser a_parser);


ADT(parser){
    /* Token vector. */
    char **m_tokens;
    size_t m_index;
    size_t m_size;
    /* boolean list of ascii separators - commas, operands etc.*/
    bool_t m_sep_list[ASCII_SYMBOLS];
    char m_num_separators;
    char *m_source;

};

parser parser_create(const char *a_sep_list){
    parser result;
    ALLOCATE(result, parser);
    assert(NULL != a_sep_list);
    set_separator_list(result,a_sep_list);
    return result;
}

static char* str_duplicate(const char *a_source){
    char *result = NULL;
    size_t source_size;

    assert(NULL != a_source);
    source_size = strlen(a_source);
    result = malloc(sizeof(source_size));
    strcpy(result, a_source);
    return result;
}

void parser_parse_text(parser a_parser, char *a_input){
    size_t size_of_input, index = 0;
    assert(NULL != a_parser && NULL != a_input);
    size_of_input = strlen(a_input);
    a_parser->m_tokens = malloc(sizeof(char *)*size_of_input);
    str_space_separators(a_parser,a_input);
    get_tokens(a_parser);
}


char *parser_pop(parser a_parser){
    char *result = a_parser->m_tokens[a_parser->m_index];
    if(a_parser->m_index <= a_parser->m_size)
        a_parser->m_index+=1;
    return result;
}
bool_t parser_has_next(parser a_parser){
    return a_parser->m_index < a_parser->m_size;
}

void str_space_separators(parser a_parser,const char *a_source){
    size_t i = 0 , delim_size = 0, src_size = 0;
    assert(NULL != a_parser && NULL != a_source);
    a_parser->m_source = calloc(1 + strlen(a_source)* 3, sizeof(char));
    assert(NULL != a_parser->m_source);
    while(0 != *a_source){
        if(True == a_parser->m_sep_list[*a_source]){
            a_parser->m_source[src_size++] = ' ';
            a_parser->m_source[src_size++] = *a_source++;
            a_parser->m_source[src_size++] = ' ';
        }
        else
            a_parser->m_source[src_size++] = *a_source++;
    }
    a_parser->m_source[src_size] = 0;
}

void get_tokens(parser a_parser){
    a_parser->m_tokens[a_parser->m_size] = strtok(a_parser->m_source,WS);
    while(a_parser->m_tokens[a_parser->m_size++]){
        a_parser->m_tokens[a_parser->m_size] = strtok(NULL,WS);
    }
    --a_parser->m_size;
}

static void set_separator_list(parser a_parser, const char *a_sep_list){
    assert(NULL != a_parser && NULL != a_sep_list);
    while (0 != *a_sep_list){
        a_parser->m_sep_list[*a_sep_list++] = True;
        a_parser->m_num_separators++;
    }
}

static void clear_parser(parser a_parser){
    assert(NULL != a_parser);
    if(True != is_empty(a_parser)){
        free(a_parser->m_tokens);
        free(a_parser->m_source);
    }
}

static bool_t is_empty(parser a_parser){
    if(a_parser->m_source && a_parser->m_tokens){
        return True;
    }
    return False;
}

char *parser_peak(parser a_parser){
    assert(NULL != a_parser);
    return a_parser->m_tokens[a_parser->m_index];
}