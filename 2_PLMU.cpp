// Problem Link: https://www.codechef.com/DEC19B/problems/PLMU

#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        int noOf_0 = -1;
        int noOf_2 = -1;
        for(int i=0; i<n; i++){
            if(arr[i] == 2)
                noOf_2++;
            else if(arr[i] == 0)
                noOf_0++;
        }
        noOf_0 = noOf_0 == -1 ? 0 : noOf_0;
        noOf_2 = noOf_2 == -1 ? 0 : noOf_2;
        long ans = (noOf_0 * (noOf_0+1))/2 + (noOf_2 * (noOf_2+1))/2;
        cout << ans << endl;
     }
    return 0;
}

