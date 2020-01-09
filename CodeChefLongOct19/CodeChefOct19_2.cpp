// Link To The Website: https://codechef.com/OCT19B/problems/SAKTAN

#include<bits/stdc++.h>
using namespace std;
int main(){  
    int t;
    cin >> t;
    while(t--){
        long n,m,q;
        cin >> n >> m >> q;
        long *row = new long[n];
        long *col = new long[m];
        // Initilizing Row And Col array
        for(int i=0; i<n; i++){
            row[i] = 0;
        }
        for(int i=0; i<m; i++){
            col[i] = 0;
        }
        // Queries Loop
        while(q--){
            int x,y;
            cin >> x >> y;
            x--;
            y--;
            row[x]++;
            col[y]++;
        }
        // Main Logic
        long count = 0;
        long noOfOdd = 0;
        long noOfEven = 0;
        for(int i=0; i<m; i++){
            if(col[i] % 2 == 0)
                noOfEven++;
        }
        noOfOdd = m - noOfEven;
        for(int i=0; i<n; i++){
            if(row[i] % 2 == 0)
                count += noOfOdd;
            else
                count += noOfEven;
        }
        cout<<count<<endl;
        delete[] row;
        delete[] col;
    }  
    return 0;
}