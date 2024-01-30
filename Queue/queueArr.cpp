#include<iostream>
using namespace std;

void push(int q[], int &front, int &rear, int n, int data){
    if(rear==n-1){
        cout<<"Queue overFlow"<<endl;
        return;
    }

    q[++rear]=data;

    if(front==-1 || front>rear)
        front = rear;  
    
}
void pop(int q[], int &front, int &rear){
    if(front==-1 || front>rear){
        cout<<"Queue underFlow"<<endl;
        return;
    }
    front++;
}

void display(int q[], int front, int rear){
    if(front==-1 || front>rear){
        cout<<"Queue underFlow"<<endl;
        return;
    }
    cout<<q[front]<<endl;
}



int main()
{
    int n = 10;
    int s[n];
    int front = -1 , rear = -1;
    push(s,front,rear,n,1);
    push(s,front,rear,n,2);
    push(s,front,rear,n,3);
    push(s,front,rear,n,4);
    push(s,front,rear,n,5);

    pop(s,front,rear);
    pop(s,front,rear);
    
    display(s,front,rear);
    return 0;
}
