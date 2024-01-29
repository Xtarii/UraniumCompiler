CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
# set the project name
PROJECT(UraniumCompiler)
# add the executable
ADD_EXECUTABLE(UraniumCompiler main.c src/lexer.c src/token.c src/AST.c src/parser.c)
