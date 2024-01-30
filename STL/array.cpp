#include <iostream>
#include <array>
using namespace std;
int main()
{
    /* code */
    array<int, 4> a = {1, 2, 3, 4};//4 is the size of the array
    int size = a.size();

    for (int i = 0; i < size; i++)
        cout << a[i] << " ";

    cout << a.at(2) << endl;
    cout << "Empty of Not: " << a.empty() << endl;
    cout << "First element: " << a.front() << endl;
    cout << "Last element: " << a.back() << endl;
        return 0;
}
