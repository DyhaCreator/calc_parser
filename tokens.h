struct token{
    std::string tok;
    std::string type;
    token(){}
    token(std::string tok, std::string type){
        this->tok = tok;
        this->type = type;
    }
};