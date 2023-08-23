#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "tokens.h"

std::vector<token> parser(std::string code){
    std::vector<token>parse = std::vector<token>();
    std::string ACC_SYM = "0123456789+-/*()\n";
    std::string NUM = "0123456789";
    std::string ACT = "+-/*";
    std::string Snum = "";
    long long LLnum = 0;
    for(int i = 0; i < code.size(); i++){
        if(ACC_SYM.find(code[i]) != std::string::npos){
            if(NUM.find(code[i]) != std::string::npos){
                Snum += code[i];
                LLnum = LLnum * 10 + code[i] - '0';
            }
            else if(ACT.find(code[i]) != std::string::npos){
                if(LLnum != 0){
                    token t(LLnum, Snum, "NUM");
                    parse.push_back(t);
                    LLnum = 0;
                    Snum = "";
                }
                token d(code[i], "ACT");
            }
            else if(code[i] == '\n' && LLnum != 0){
                token t(LLnum, Snum, "NUM");
                parse.push_back(t);
                LLnum = 0;
                Snum = "";
            }
        }
    }
    return parse;
}

int main(){
    std::vector<std::string>file = std::vector<std::string>();
    std::string str;
    std::ifstream inf("code.in");
    std::cout << "read file ...\n";
    while(std::getline(inf, str)){
        file.push_back(str + '\n');
    }
    std::cout << file[0];
    std::cout << "parsing your code ...\n";
    std::vector<token>n = parser(file[0]);

    return 0;
}