#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void push(Node* &top, int data){
    Node* n = new Node(data);
    if(top==NULL){
        top = n; 
        return;
    }
    n->next = top;
    top = n;
}

void pop(Node* &top){
    if(top==NULL){
        cout<<"Stack underFlow"<<endl;
        return;
    }
    top = top->next;
}

void display(Node* top){
    if(top==NULL){
        cout<<"Stack underFlow"<<endl;
        return;
    }
    cout<<top->data<<endl;
}
int main()
{
    Node* top = NULL;
    push(top,1);
    push(top,2);
    push(top,3);
    push(top,4);
    push(top,5);

    pop(top);
    display(top);
    
    return 0;
}
