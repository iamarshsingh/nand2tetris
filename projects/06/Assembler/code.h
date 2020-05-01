#ifndef CODE_H
#define CODE_H

#include <fstream>
#include <iostream>
#include <string>
#include <map>
using namespace std;

class Code{
private:
    map<string, string> dest_str, comp_str, jump_str;

public:
    Code();
    /*
    Returns the 3-bits binary code of the dest mnemonic.
    */
    string dest(string s);

    /*
    Returns the 7-bits binary code of the comp mnemonic.
    */
    string comp(string s);

    /*
    Returns the binary code of the jump mnemonic.
    */
    string jump(string s);

    string binary(string s);
};


#endif
