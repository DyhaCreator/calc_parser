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
            else if(code[i] == '('){
                token bracket(code[i], "BROP");
                parse.push_back(bracket);
            }
            else if(code[i] == ')'){
                if(LLnum != 0){
                    token t(LLnum, Snum, "NUM");
                    parse.push_back(t);
                    LLnum = 0;
                    Snum = "";
                }
                token bracket(code[i], "BRCL");
                parse.push_back(bracket);
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
    int ColBrackets = 0;
    for(int i = 0; i < tokens.size(); i++){
        if(tokens[i].type == "BROP" || tokens[i].type == "BRCL"){
            ColBrackets ++;
        }
    }
    if(tokens[0].type == "BROP" && tokens[tokens.size() - 1].type == "BRCL" && ColBrackets == 2){
        tokens.erase(tokens.begin());
        tokens.erase(tokens.end());
    }
    for(int i = 0; i < tokens.size(); i++){
        std::cout << tokens[i].tok << " ";
    }
    std::cout << std::endl;
    if(tokens.size() == 1){
        node -> node = token(tokens[0]);
        return node;
    }
    int startPos = 0;
    while(true){
        if(tokens[startPos].type == "BROP"){
            int openedBrackets = 1;
            while(openedBrackets > 0){
                startPos ++;
                if(tokens[startPos].type == "BROP"){
                    openedBrackets ++;
                }
                if(tokens[startPos].type == "BRCL"){
                    openedBrackets --;
                }
            }
            startPos ++;
        }
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

    node -> left = parse_bin_tree(left);
    node -> right = parse_bin_tree(right);
    
    return node;
}