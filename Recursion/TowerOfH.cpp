#include <iostream>

using namespace std;

void countMoves(int n, char source, char auxiliary, char destination, int &c)
{
    if (n == 1)
    {
        cout << "Move disk 1 from " << source << " to " << destination << endl;
        c++;
        return;
    }
    c++;
    countMoves(n - 1, source, destination, auxiliary,c);
    cout << "Move Disk " << n << " from " << source << " to " << destination << endl;
    countMoves(n - 1, auxiliary, source, destination,c);

   
}

int main()
{
    int n = 0;
    // cin >> n;
   countMoves(5, 'A', 'B', 'C',n);
   cout<<"count "<<n;
    return 0;
}