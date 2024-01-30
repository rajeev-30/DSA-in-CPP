#include<iostream>
using namespace std;

void floyd(int a[4][4]){
    int i,j,k;
    // for(k=0; k<4; k++) {
    //     for(i=0; i<4; i++) {
    //         for(j=0; j<4; j++) {
    //             if(i!=j) {
    //                 if(a[i][j]>=a[i][k] + a[k][j] || a[i][j]==0) {
    //                     a[i][j] = a[i][k]+a[k][j];
    //             }
    //         }
    //     }
    // }
// }

    for(i=0; i<4; i++) {
        cout<<endl;
        for(j=0; j<4; j++) {
            cout<<a[i][j]<<" "; 
        }
    }
}

int main()
{
    int a[4][4];
    cout<<"Enter values of adjacency matrix";
    for(int i=0; i<4; i++) {
        cout<<"Enter values of "<<(i+1)<<" row"<<endl;
        for(int j=0;j<4; j++){
            cin>>a[i][j];
        }
    }
    floyd(a);
    return 0;
}