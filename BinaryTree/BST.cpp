#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};


void BuildBST(Node* &root, int data){
    
    if(root==NULL){
        root = new Node(data);
        return;
    }

    if(data>root->data){
        BuildBST(root->right, data);
    }else{
        BuildBST(root->left, data);
    } 
}

void takeInput(Node* &root){
    cout<<"Enter data: ";
    int data;
    cin>>data;
    while (data!=-1)
    {
        BuildBST(root, data);
        cin>>data;
    }

}

void InOrder(Node *root)
{
    if (root == NULL)
        return;

    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

void Insertion(Node* &root, int data)
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

bool Search(Node* root, int data)
{
    if (root == NULL){
        return false;
    }
    
    if(data==root->data){
        return true;
    }
    else if(data>root->data)
        return Search(root->right, data);
    else 
        return Search(root->left, data);
}

Node* InordrSucc(Node* root){
    while(root->left!=NULL){
        root = root->left;
    }
    return root;
}

Node* dell(Node* &root, int data){
    if(data<root->data){
        root->left = dell(root->left, data);
    }
    else if(data>root->data){
        root->right = dell(root->right, data);
    }
    else{
        if(root->left==NULL && root->right==NULL)
            return NULL;

        else if(root->left==NULL)
            return root->right;
        else if(root->right==NULL)
            return root->left;
        
        else{
            Node* Is = InordrSucc(root->right);
            root->data = Is->data;
            root->right = dell(Is,Is->data);
        }
    }
    return root;
}



void isFound(Node* root, int data) {
    if(Search(root, data)){
        cout<<"Found"<<endl;
        return;
    }
    cout<<"Not Found"<<endl;
}

Node* inorderSeccesor(Node* &root){
    while(root->left!=NULL){
        root = root->left;
    }
    return root;
}


Node* deletion(Node *&root, int data){
    if(root->data>data){
        root->left = deletion(root->left, data);
    }
    else if(root->data<data){
        root->right = deletion(root->right, data);
    }
    else{
        //1st case (leaf Node)
        if(root->left==NULL && root->right==NULL)
            return NULL;

        //2nd Case (Node havin' One Child)
        if(root->right==NULL)
            return root->left;
        else if(root->left==NULL)
            return root->right;
        
        //3rd Case (Node havin' two Child)
        Node* is = inorderSeccesor(root->right);
        root->data = is->data;
        root->right = deletion(root->right, is->data);
    }
    return root;
    
}



int main(){
    Node* root =  NULL;

    takeInput(root);
    // Insertion(root, 0);

    // isFound(root, 162);
    // root = dell(root, 4);

    InOrder(root);
    return 0;
}