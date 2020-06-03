// Problem Link: https://www.codechef.com/LTIME84B/problems/LOSTWKND
#include <bits/stdc++.h>
using namespace std;
#define whatis(x) cerr << #x << " is : " << x <<endl;
typedef long long ll;
typedef unsigned long long ull;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll arr[5];
        ll p;
        for(int i=0; i<5; i++){
            cin >> arr[i];
        }
        cin >> p;
        for(int i=0; i<5; i++){
            arr[i] *= p;
            arr[i] -= 24;
        }
        ll sum = 0;
        for(int i=0; i<5; i++){
            sum += arr[i];
        }        
        if(sum > 0){
            cout << "Yes" <<endl;
        }else{
            cout << "No" << endl;
        }
    }
    return 0;
}