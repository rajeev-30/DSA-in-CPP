#include <iostream>
#include <list>
using namespace std;
int main()
{
    list<int> l;
    l.push_front(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    cout<<"Size: "<<l.size()<<endl;

    for(int i:l)
        cout<<i<<" ";

    cout<<endl;

    l.erase(l.begin());
    l.pop_back();
    l.pop_front();
    
    cout<<"Size: "<<l.size()<<endl;
    return 0;
}
