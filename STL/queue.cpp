#include<iostream>
#include<queue>
using namespace std;


int main()
{
    /* code */
    queue<int> q;
    queue<int> q1;
    q.push(1);
    q.push(3);
    q.push(4);
    q.push(2);
    
    q.pop();
    // q.pop();
    q1=q;

    cout<<q1.front()<<endl;
    cout<<q1.back()<<endl;

    cout << "Empty or Not: " << q.empty() << endl;
    cout<<"size: "<<q.size()<<endl;

    return 0;
}
