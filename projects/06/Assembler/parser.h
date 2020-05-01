#ifndef PARSER_H
#define PARSER_H

#include <fstream>
#include <iostream>
#include <string>
#include <ctype.h>
#include <map>
using namespace std;

enum CommandType{
    A_COMMAND,
    C_COMMAND,
    L_COMMAND,
    WRONG_COMMAND
};

class Parser{
private:
    int mem_used;
    CommandType cmdType;
    map<string, string> symbolTable;
    string symbol_str, dest_str, comp_str, jump_str;
    std::ifstream& input_stream;


public:
    /*
    Opens the input file/stream and
    gets ready to parse it.
    */
    Parser(ifstream &input_stream);

    /*
    Are there more commands in the input?
    */
    bool hasMoreCommands();

    /*
    Reads the next command from
    the input and makes it the current
    command. Should be called only
    if hasMoreCommands() is true.
    Initially there is no current command.
    */
    void advance();

    /*
    Returns the type of the current command:
    m A_COMMAND for @Xxx where Xxx is either a symbol or a decimal number
    m C_COMMAND for dest=comp;jump
    m L_COMMAND (actually, pseudocommand) for (Xxx) where Xxx is a symbol.
    */
    CommandType commandType();

    /*
    Returns the symbol or decimal Xxx of the current command @Xxx or (Xxx).
    Should be called only when commandType() is A_COMMAND or L_COMMAND.
    */
    string symbol();

    /*
    Returns the dest mnemonic in the current C-command (8 possibilities).
    Should be called only when commandType() is C_COMMAND.
    */
    string dest();

    /*
    Returns the comp mnemonic inthe current C-command (28 possibilities).
    Should be called only when commandType() is C_COMMAND.
    */
    string comp();

    /*
    Returns the jump mnemonic in the current C-command (8 possibilities).
    Should be called only when commandType() is C_COMMAND.
    */
    string jump();
};


#endif
