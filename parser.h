#ifndef ASSEMBLER_PARSER_H
#define ASSEMBLER_PARSER_H
#include "adt_auxiliary.h"

DEFINE_ADT(parser);
/**
 * Creates a new parser object.
 *
 * @param a_sep_list The separator list used by the parser.
 * @return The newly created parser object.
 */
parser parser_create(const char *a_delim_list);
/**
 *
 * @param a_parser
 */
void parser_destroy(parser *a_parser);
/**
 * Parses the input text using the specified parser.
 *
 * @param a_parser The parser object used for parsing.
 * @param a_input The input text to be parsed.
 */
void parser_parse_text(parser a_parser, char *a_input);

/**
 * Retrieves the next token from the parser.
 *
 * @param a_parser The parser object.
 * @return The next token from the parser.
 */
char *parser_pop(parser a_parser);
/**
 * Checks if there are more tokens available in the parser.
 *
 * @param a_parser The parser object.
 * @return True if there are more tokens, False otherwise.
 */
bool_t parser_has_next(parser a_parser);

char *parser_peak(parser a_parser);



#endif