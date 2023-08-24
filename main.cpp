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
                //nums prior = 0
                //+- prior = 1
                //*/ prior = 2
                token d;
                if(code[i] == '+' || code[i] == '-'){
                    d = token(code[i], "ACT", 1);
                }
                else if(code[i] == '*' || code[i] == '/'){
                    d = token(code[i], "ACT", 2);
                }
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
    if(tokens.size() == 1){
        node -> node = token(tokens[0]);
        return node;
    }
    int startPos = 0;
    while(true){
        if(tokens[startPos].type == "ACT" && tokens[startPos].prior == 1){
            break;
        }
        if(startPos == tokens.size()){
            startPos = -1;
            break;
        }
        startPos ++;
    }

    if(startPos == -1){
        startPos = 0;
        while(true){
            if(tokens[startPos].type == "ACT" && tokens[startPos].prior == 2){
                break;
            }
            startPos ++;
        }
    }

    node -> node = token(tokens[startPos]);

    std::vector<token>left = std::vector<token>();
    std::vector<token>right = std::vector<token>();

    for(int i = 0; i < startPos; i++){
        left.push_back(tokens[i]);
    }
    for(int i = startPos + 1; i < tokens.size(); i++){
        right.push_back(tokens[i]);
    }

    node -> right = parse_bin_tree(right);
    node -> left = parse_bin_tree(left);
    
    return node;
}

void print_tree(Node *node){
    std::cout << node -> node.tok << " ";
    if(node -> left != nullptr){
        print_tree(node -> left);
    }
    if(node -> right != nullptr){
        print_tree(node -> right);
    }
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
        std::cout << tokens[i].tok << " " << tokens[i].type << " " << tokens[i].prior << std::endl;
    }
    Node *node = parse_bin_tree(tokens);

    print_tree(node);

    return 0;
}