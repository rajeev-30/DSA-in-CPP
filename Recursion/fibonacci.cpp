#include <iostream>
using namespace std;

int rec(int n)
{
    if (n == 0 || n==1)
        return n;

    return rec(n - 1) + rec(n - 2);
}

int main()
{
    cout<<rec(7)<<endl;
}