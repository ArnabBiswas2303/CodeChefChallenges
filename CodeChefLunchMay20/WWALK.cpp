// Problem Link: https://www.codechef.com/LTIME84B/problems/WWALK
#include <bits/stdc++.h>
using namespace std;
#define whatis(x) cerr << #x << " is : " << x <<endl;
typedef long long ll;
typedef unsigned long long ull;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        for(int i=0; i<n; i++){
            cin >> b[i];
        }
        ll lastA = 0;
        ll lastB = 0;
        ll ans = 0;
        for(int i=0; i<n; i++){
            if((lastA == lastB) && (a[i] == b[i])){
                ans+= a[i];
            }
            lastA += a[i];
            lastB += b[i];
        }        
        cout << ans << endl; 
    }
    return 0;
}