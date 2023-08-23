#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "tokens.h"

void parser(){

}

int main(){
    std::string file, str;
    std::ifstream inf("code.in");
    std::cout << "read file ...\n";
    while(std::getline(inf, str)){
        file += str + "\n";
    }
    std::cout << file;
    std::cout << "parsing your code ...\n";
    std::vector<token>n = std::vector<token>();
    return 0;
}