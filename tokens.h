struct token{
    long long num = 0;
    std::string tok;
    std::string type;
    int prior = 0;
    //types = NUM, ACT, BROP, BRCL;
    token(){}
    token(std::string tok, std::string type){
        this->tok = tok;
        this->type = type;
    }
    token(char tok, std::string type){
        this->tok = tok;
        this->type = type;
    }
    token(char tok, std::string type, int prior){
        this->tok = tok;
        this->type = type;
        this->prior = prior;
    }
    token(long long num, std::string tok, std::string type){
        this->num = num;
        this->tok = tok;
        this->type = type;
    }
    token(token *a){
        this->tok = a -> tok;
        this->type = a -> type;
        this->num = a -> num;
        this->prior = a -> prior;
    }
};