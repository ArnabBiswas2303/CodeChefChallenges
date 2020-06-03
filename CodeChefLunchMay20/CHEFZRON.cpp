// Problem Link: https://www.codechef.com/LTIME84B/problems/CHEFZRON
#include <bits/stdc++.h>
using namespace std;
#define whatis(x) cerr << #x << " is : " << x <<endl;
typedef long long ll;
typedef unsigned long long ull;


vector<ll> shiftVector(vector<ll>& in, int size){
    ll n = in.size();
    vector<ll> arr;
    for(int i=1; i<n; i++){
        arr.push_back(in[i] - (in[0] + 1));
    }
    arr.push_back(size-1);    
    return arr;
}

ll findTheAns(vector<ll>& arr){
    ll n = arr.size();    
    ll * dp = new ll[10000000];
    dp[0] = 0;
    dp[1] = 1e9;
    dp[2] = arr[1] - arr[0];
    dp[3] = arr[2] - arr[0];
    for(ll i=4; i<=n; i++){        
        dp[i] = min(dp[i-2]+(arr[i-1]-arr[i-2]), dp[i-3]+(arr[i-1]-arr[i-3]));        
    }        
    return dp[n];
}

vector<ll> in;

int main(){
    ll t; 
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        in.clear();
        ll input;
        for(ll i=0; i<n; i++){
            cin >> input;
            if(input)
                in.push_back(i);
        }
        if(in.size() == 0){
            cout << 0 << endl;
            continue;
        }else if(in.size() == 1){
            cout << -1 << endl;
            continue;
        }       
        vector<ll> arr1, arr2;        
        ll x,y,z;
        x = findTheAns(in);
        arr1 = shiftVector(in, n);                                    
        y = findTheAns(arr1);        
        arr2= shiftVector(arr1, n);                                   
        z = findTheAns(arr2);
        ll ans = min(x,min(y,z));
        cout << ans << endl;
    }
    return 0;
}