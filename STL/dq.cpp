#include<iostream>
#include<deque>
using namespace std;


int main(int argc, char const *argv[])
{
    /* code */
    deque<int> d;
    d.push_back(1);
    d.push_back(3);
    d.push_back(4);
    d.push_front(2);
    
    // d.pop_back();
    // d.pop_front();

    for(int i:d)
        cout<<i<<" ";

    cout<<endl<<d[1]<<endl;
    cout<<d.at(0)<<endl;


    cout << "First element: " << d.front() << endl;
    cout << "Last element: " << d.back() << endl;

    cout << "Empty of Not: " << d.empty() << endl;

    cout<<"Size: "<<d.size()<<endl;

    d.erase(d.begin(), d.end());
    cout<<"Size: "<<d.size()<<endl;
    return 0;
}
