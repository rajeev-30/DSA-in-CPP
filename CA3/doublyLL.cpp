#include <iostream>
#include <stack>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;

    node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }

};

node* build(node* &root, int data){
    if(root==NULL){
        root=new node(data);
        return root;
    }

    if(data>root->data)
        root->right = build(root->right, data);
    if(data<root->data)
        root->left = build(root->left, data);
    return root;
    
}

node* ins(node* root){
    node* curr = root;
    while(root->left!=NULL){
        root = root->left;
    }
    return root;
}

node* del(node* root, int data){
    if(data>root->data)
        root->right = del(root->right, data);
    else if(data<root->data)
        root->left = del(root->left, data);
    else{

        if(root->left==NULL && root->right==NULL)
            return NULL;

        else if(root->left==NULL)
            return root->right;
        else if(root->right==NULL)
            return root->left;
        else{
            node* is = ins(root->right);
            root->data = is->data;
            root->right = del(root->right, root->data);
        }

    }
    return root;
}

void inorder(node * root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}

int main()
{
    node* root=NULL;
    build(root, 2);
    build(root, 3);
    build(root, 5);
    build(root, 1);
    build(root,8);
    build(root, 7);
    build(root, 9);
    build(root, 0);

del(root, 2);
    inorder(root);
}