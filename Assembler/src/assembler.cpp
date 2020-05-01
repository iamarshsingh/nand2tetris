#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include "parser.h"
#include "code.h"


int main(int argc, char* argv[]){

    // If user didn't provided the File name
    if(argc == 1){
        // Print an error and exit
        cerr << "Error: Missing Argument(File Name)" << endl;
        cerr << "Usage: ./assembler fileName.asm" << endl;
        return 1;
    }

    string input_file(argv[1]);
    string output_file = input_file.substr(0, input_file.find('.')) + ".hack";

    ifstream inf{ input_file };
    ofstream outf{ output_file };

    // If we couldn't open the output file stream for reading
    if (!inf)
    {
        // Print an error and exit
        cerr << "Uh oh, "<< input_file <<" could not be opened for reading!" << endl;
        return 1;
    }

    // If we couldn't open the output file stream for writing
    if (!outf)
    {
        // Print an error and exit
        cerr << "Uh oh "<< output_file <<" could not be opened for writing!" << endl;
        return 1;
    }


    Parser parser(inf);
    Code code;

    while (parser.hasMoreCommands()){
        parser.advance();
        if(parser.commandType() == WRONG_COMMAND){
            break;
        }
        else if(parser.commandType() == A_COMMAND || parser.commandType() == L_COMMAND){
            cout<<"A/L : ";
            cout<<parser.symbol()<<endl;
            outf<<"0"<<code.binary(parser.symbol())<<"\n";
        }
        else if(parser.commandType() == C_COMMAND){
            cout<<"C   : ";
            cout<<parser.dest()<<" "<<parser.comp()<<" "<<parser.jump()<<endl;
            outf<<"111"<<code.comp(parser.comp())<<code.dest(parser.dest())<<code.jump(parser.jump())<<"\n";
        }
    }

    // // We'll write two lines into this file
    // outf << "This is line 1" << '\n';
    // outf << "This is line 2" << '\n';
    //
    //
    // // While there's still stuff left to read

}
