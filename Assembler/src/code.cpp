#include "code.h"

Code::Code(){
    this->comp_str.clear();
    this->dest_str.clear();
    this->jump_str.clear();

    this->comp_str["0"] = "0101010";
    this->comp_str["1"] = "0111111";
    this->comp_str["-1"] = "0111010";
    this->comp_str["D"] = "0001100";
    this->comp_str["A"] = "0110000";
    this->comp_str["M"] = "1110000";
    this->comp_str["!D"] = "0001101";
    this->comp_str["!A"] = "0110001";
    this->comp_str["!M"] = "1110001";
    this->comp_str["!M"] = "1110001";
    this->comp_str["-D"] = "0001111";
    this->comp_str["-A"] = "0110011";
    this->comp_str["-A"] = "1110011";
    this->comp_str["D+1"] = "0011111";
    this->comp_str["A+1"] = "0110111";
    this->comp_str["M+1"] = "1110111";
    this->comp_str["D-1"] = "0001110";
    this->comp_str["A-1"] = "0110010";
    this->comp_str["M-1"] = "1110010";
    this->comp_str["D+A"] = "0000010";
    this->comp_str["D+M"] = "1000010";
    this->comp_str["D-A"] = "0010011";
    this->comp_str["D-M"] = "1010011";
    this->comp_str["A-D"] = "0000111";
    this->comp_str["M-D"] = "1000111";
    this->comp_str["D&A"] = "0000000";
    this->comp_str["D&M"] = "1000000";
    this->comp_str["D|A"] = "0010101";
    this->comp_str["D|M"] = "1010101";


    this->dest_str["null"] = "000";
    this->dest_str["M"] = "001";
    this->dest_str["D"] = "010";
    this->dest_str["MD"] = "011";
    this->dest_str["A"] = "100";
    this->dest_str["AM"] = "101";
    this->dest_str["AD"] = "110";
    this->dest_str["AMD"] = "111";


    this->jump_str["null"] = "000";
    this->jump_str["JGT"] = "001";
    this->jump_str["JEQ"] = "010";
    this->jump_str["JGE"] = "011";
    this->jump_str["JLT"] = "100";
    this->jump_str["JNE"] = "101";
    this->jump_str["JLE"] = "110";
    this->jump_str["JMP"] = "111";

}

string Code::comp(string s){
    if(this->comp_str.find(s) != this->comp_str.end()){
        return this->comp_str[s];
    }
    cerr<<"Cannot find this comp "<<s<<"\n";
}

string Code::dest(string s){
    if(this->dest_str.find(s) != this->dest_str.end()){
        return this->dest_str[s];
    }
    cerr<<"Cannot find this dest "<<s<<"\n";
}

string Code::jump(string s){
    if(this->jump_str.find(s) != this->jump_str.end()){
        return this->jump_str[s];
    }
    cerr<<"Cannot find this jump "<<s<<"\n";
}

string Code::binary(string s){
    int n = stoi(s);
    cout<<n;
    string b = "";
    while(n>0){
        if(n%2==0){
            b = "0"+b;
        }
        else{
            b = "1"+b;
        }
        n=n/2;
    }
    while(b.length()<15){
        b = "0"+b;
    }
    cout<<" b: "<<b<<"\n";
    return b;
}
