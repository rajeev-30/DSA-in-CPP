#include<iostream>
using namespace std;
#define N 10

bool isEmpty(int top)
{
    return (top == -1);
}

bool isFull(int top)
{
    return (top == N - 1);
}

void push(int s[], int &top,int data){
    if(isFull(top)){
        cout<<"Stack overFlow"<<endl;
        return;
    }
    s[++top] = data;
}
void pop(int s[], int &top){
    if(isEmpty(top)){
        cout<<"Stack underFlow"<<endl;
        return;
    }
    top--;
    
}
void peek(int s[], int top){
    if(isEmpty(top)){
        cout<<"Stack underFlow"<<endl;
        return;
    }
    cout<<s[top]<<endl;
    
}

int main(){
    int s[N];
    int top = -1;
    push(s,top,1);
    push(s,top,2);
    push(s,top,3);
    push(s,top,4);
    push(s,top,5);
    push(s,top,6);

    pop(s,top);
    pop(s,top);
    pop(s,top);
    pop(s,top);
    pop(s,top);
    pop(s,top);
    pop(s,top);
    peek(s,top);
}