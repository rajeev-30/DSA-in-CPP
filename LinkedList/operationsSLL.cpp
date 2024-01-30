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

void InsertAtFirst(Node* &head, int val){
    Node* n = new Node(val);
    if(head==NULL){
        head = n;
        return;
    }
    n->next = head;
    head = n;
}

void InsertAfterValue(Node* &head, int val, int afterVal){
    Node* n = new Node(val);
    Node* curr = head;
    while(curr->data!=afterVal && curr!=NULL){
        curr = curr->next;
    }
    if(curr==NULL) return;
    n->next = curr->next;
    curr->next = n;  
}

void InsertAtEnd(Node* &head, int data){
    Node* n = new Node(data);
    if(head==NULL){
        head = n;
        return;
    }
    Node* curr = head;
    while(curr->next!=NULL){
        curr = curr->next;
    }
    curr->next = n;
}

void Deletion(Node* &head, int pos){
    if(pos==0){
        head = head->next;
        return;    
    } 
    Node* curr = head;
    int count = 0;

    while(curr!=NULL && count!=pos-1){
        curr = curr->next;
        count++;
    }
    
    if(curr==NULL) return;

    curr->next = curr->next->next;
}

void Search(Node* &head, int key){
    Node* curr = head;
    while(curr!=NULL){
        if(curr->data==key){
            cout<<"Element found"<<endl;
            return;
        }
        curr = curr->next;
    }
    cout<<"Element not found"<<endl;
}

void Display(Node* head){
    Node* curr = head;
    while(curr!=NULL){
        cout<<curr->data<<"->";
        curr = curr->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    Node* head = NULL;
    InsertAtEnd(head, 1);
    InsertAtEnd(head, 2);
    InsertAtEnd(head, 3);
    InsertAtEnd(head, 4);
    InsertAtEnd(head, 5);

    InsertAtFirst(head,6);

    InsertAfterValue(head, 10, 6);
    // Deletion(head, 0);

    Display(head);
    
    // Search(head, 2 );

    return 0;
}