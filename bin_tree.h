struct Node{
    token node;
    Node* right;
    Node* left;

    Node(){}
};

void print_tree(Node *node){
    std::cout << node -> node.tok << " ";
    if(node -> left != nullptr){
        print_tree(node -> left);
    }
    if(node -> right != nullptr){
        print_tree(node -> right);
    }
}