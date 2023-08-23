#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "tokens.h"
#include "bin_tree.h"

std::vector<token> parse_to_arr(std::string code){
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
                parse.push_back(d);
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

Node* parse_bin_tree(std::vector<token> tokens){
    Node *node = new Node();
    
    return node;
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
    std::vector<token>tokens = parse_to_arr(file[0]);
    for(int i = 0; i < tokens.size(); i++){
        std::cout << tokens[i].tok << " " << tokens[i].type << std::endl;
    }
    Node *node = parse_bin_tree(tokens);

    return 0;
}