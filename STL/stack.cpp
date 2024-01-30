#include<iostream>
#include<stack>
using namespace std;


int main()
{
    /* code */
    stack<int> s;
    stack<int> s1;
    s.push(1);
    s.push(3);
    s.push(4);
    s.push(2);
    
    s.pop();
    // s.pop();
    s1 = s;
    


    cout<<s.top()<<endl;
    cout<<s1.top()<<endl;

    // cout << "Empty or Not: " << s.empty() << endl;
    // cout<<"Size: "<<s.size()<<endl;

    return 0;
}
