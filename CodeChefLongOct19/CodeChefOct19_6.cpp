// Link To The Website: https://www.codechef.com/OCT19B/problems/MSNG

#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

int val(char c){
    if (c >= '0' && c <= '9')
        return (int)c - '0';
    else
        return (int)c - 'A' + 10;
}
long long toDec(string str, int base){
    int len = str.length();
    long long power = 1;
    long long num = 0;
    int i;
    for (i = len - 1; i >= 0; i--){
        if(num > pow(10,12) || power > pow(10,12))
            return -1;
        num += val(str[i]) * power;
        power = power * base;
    }
    if(num > pow(10,12))
        return -1;
    return num;
}

int minBase(string str){
    int max = INT_MIN;
    for(int i=0; i<str.length(); i++){
        if(val(str[i]) > max)
            max = val(str[i]);
    }
    return (max+1);
}

long long findX(vector< pair<int, string> >& arr){
    long long dp[arr.size()][37];
    // Initialize DP to -1
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<37; j++){
            dp[i][j] = -1;
        }
    }
    for(int i=0; i<arr.size(); i++){
        for(int j=minBase(arr[i].second); j<37; j++){
            dp[i][j] = toDec(arr[i].second,(arr[i].first == -1) ? j : arr[i].first);
        }
    }
    long long x;
    for(int i=0; i<37; i++){
        if(dp[0][i] == -1)
            continue;
        x = dp[0][i];
        int count = 0;
        for(int j=1; j<arr.size(); j++){
            for(int k=0; k<37; k++){
                if(x == dp[j][k]){
                    count++;
                    break;
                }                    
            }
        }
        if(count == arr.size()-1)
            return x;
    }
    return -1;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector< pair<int, string> > arr;
        int a;
        string b;
        for(int i=0; i<n; i++){
            cin >> a >> b;
            arr.pb(mp(a,b));
        }
        cout<<findX(arr)<<endl;
    }
    return 0;
}

