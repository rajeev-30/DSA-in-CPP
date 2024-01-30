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

class Queue{
    Node* front;
    Node* rear;

    public:
        Queue(){
            front = NULL;
            rear = NULL;
        }

        void enqueue(int data){
            Node* n = new Node(data);
            if (front == NULL) {
                front = n;
                rear = n;
                return;
            }
            rear->next = n;
            rear = n;
        }
        void dequeue(){
            if(front==NULL){
                cout<<"Queue underFlow"<<endl;
                return;
            }
            front = front->next;
        }
        void peek(){
            if(front==NULL){
                cout<<"Queue Underflow";
                return;
            }
            cout<<front->data<<endl;
        }

};
int main(){
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    q.dequeue();
    q.dequeue();
    q.peek();

    return 0;
}