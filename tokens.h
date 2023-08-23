struct token{
    long long num = 0;
    std::string tok;
    std::string type;
    token(){}
    token(std::string tok, std::string type){
        this->tok = tok;
        this->type = type;
    }
    token(char tok, std::string type){
        this->tok = tok;
        this->type = type;
    }
    token(long long num, std::string tok, std::string type){
        this->num = num;
        this->tok = tok;
        this->type = type;
    }
};