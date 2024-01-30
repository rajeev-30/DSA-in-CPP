// vector :- when vector gets full, it creates a new vector whose size will be double than the previous one
#include<iostream>
#include<vector>

using namespace std;


int main(int argc, char const *argv[])
{
    /* code */
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    cout<<"Capacity: "<<v.capacity()<<endl;
    cout<<"Size: "<<v.size()<<endl;
    cout<<"Element: "<<v[4]<<endl;

    cout << "First element: " << v.front() << endl;
    cout << "Last element: " << v.back() << endl;

    v.pop_back();

    vector<int> v2(v);//copy all the Elements from v to v2
    for(int i:v2)
        cout<<i<<" ";

    cout <<endl<< "After pop_back, Last element: " << v.back() << endl;
    v.clear();
    return 0;
}
