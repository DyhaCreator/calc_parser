#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "tokens.h"
#include "bin_tree.h"
#include "parsing.h"

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