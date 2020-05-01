#include "parser.h"

Parser::Parser(ifstream &input_stream) : input_stream(input_stream){
    this->mem_used = 16;
    this->symbol_str = "";
    this->dest_str = "";
    this->comp_str = "";
    this->jump_str = "";

    this->symbolTable["SP"] = "0";
    this->symbolTable["LCL"] = "1";
    this->symbolTable["ARG"] = "2";
    this->symbolTable["THIS"] = "3";
    this->symbolTable["THAT"] = "4";
    this->symbolTable["SCREEN"] = "16384";
    this->symbolTable["KBD"] = "24576";
    for(int i=0;i<=15;i++){
        this->symbolTable["R"+to_string(i)] = to_string(i);
    }

    int done = 0;
    while (this->input_stream)
    {
        // TODO Multiline comment
        string strInput;
        getline(this->input_stream, strInput);
        //cout<<strInput<<" ";
        strInput = strInput.substr(0, strInput.find("//"));
        //cout<<strInput<<" ";
        string finalStr = "";
        for(int i=0; i<strInput.length(); i++){
            if( ((int)strInput[i])>=33 && ((int)strInput[i])<=126 )
                finalStr += strInput[i];
        }

        if(finalStr==""){
            continue;
        }

        if(finalStr[0] == '('){
            string temp = finalStr.substr(1, finalStr.length()-2);
            this->symbolTable[temp] = to_string(done);
        }
        else{
            done++;
        }
    }

    for(pair<string,string> p: this->symbolTable){
        cout<<p.first<<" "<<p.second<<"\n";
    }

    this->input_stream.clear();
    this->input_stream.seekg(0, this->input_stream.beg);
}

bool Parser::hasMoreCommands(){
    if(this->input_stream)
        return true;
    else
        return false;
}

void Parser::advance(){
    while (this->input_stream)
    {
        // TODO Multiline comment
        string strInput;
        getline(this->input_stream, strInput);
        //cout<<strInput<<" ";
        strInput = strInput.substr(0, strInput.find("//"));
        //cout<<strInput<<" ";
        string finalStr = "";
        for(int i=0; i<strInput.length(); i++){
            if( ((int)strInput[i])>=33 && ((int)strInput[i])<=126 )
                finalStr += strInput[i];
        }

        if(finalStr==""){
            continue;
        }

        //cout<<((int)finalStr[0])<<" Len:"<<finalStr.length()<<"\n";

        if(finalStr[0] == '@'){
            this->cmdType = A_COMMAND;
            string temp = finalStr.substr(1);
            if(isalpha(temp[0])){
                if(this->symbolTable.find(temp) == this->symbolTable.end()){
                    this->symbolTable[temp] = to_string(this->mem_used);
                    this->mem_used++;
                }
                this->symbol_str = this->symbolTable[temp];
            }
            else
                this->symbol_str = temp;
        }
        else if(finalStr[0] == '('){
            continue;
            this->cmdType = L_COMMAND;
            this->symbol_str = finalStr.substr(1, finalStr.length()-2);
        }
        else{
            this->cmdType = C_COMMAND;
            if(finalStr.find("=") != string::npos && finalStr.find(";") != string::npos){
                this->dest_str = finalStr.substr(0, finalStr.find("="));
                this->jump_str = finalStr.substr(finalStr.find(";")+1);
                this->comp_str = finalStr.substr(finalStr.find("=")+1, finalStr.find(";"));
            }
            else if(finalStr.find("=") != string::npos){
                this->dest_str = finalStr.substr(0, finalStr.find("="));
                this->jump_str = "null";
                this->comp_str = finalStr.substr(finalStr.find("=")+1);
            }
            else if(finalStr.find(";") != string::npos){
                this->dest_str = "null";
                this->jump_str = finalStr.substr(finalStr.find(";")+1);
                this->comp_str = finalStr.substr(0, finalStr.find(";"));
            }
            else{
                this->dest_str = "null";
                this->jump_str = "null";
                this->comp_str = finalStr;
            }
        }
        //cout<<"Done";
        return ;
    }
    this->cmdType = WRONG_COMMAND;
}

CommandType Parser::commandType(){
    return this->cmdType;
}

string Parser::symbol(){
    return this->symbol_str;
}

string Parser::dest(){
    return this->dest_str;
}

string Parser::comp(){
    return this->comp_str;
}

string Parser::jump(){
    return this->jump_str;
}
