cmake_minimum_required(VERSION 3.25)
project(Assembler C)

set(CMAKE_C_STANDARD 90)

add_executable(Assembler main.c queue.h list.h adt_auxiliary.h list.c node.c node.h parser.c parser.h syntax_tree.c syntax_tree.h error_type.c error_type.h syntax.c syntax.h queue.c bu.c)
