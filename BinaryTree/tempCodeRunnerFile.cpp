{
    if (root == NULL){
        root = new Node(data);
        return;
    }
    if(data>root->data)
        Insertion(root->right, data);
    else 
        Insertion(root->left, data);
}