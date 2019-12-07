// Problem Link : https://www.codechef.com/DEC19B/problems/SUBSPLAY

#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

int minDist(string s){
    int n = s.length();
    unordered_map<char, int> mp;
    int min_dist = INT_MAX;
    for (int i=0; i<n; i++){
        if (mp.find(s[i]) != mp.end())
            min_dist = min(min_dist, i - mp[s[i]]);
        mp[s[i]] = i;
    }
    min_dist = (min_dist == INT_MAX) ? n : min_dist;
    return min_dist;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int k = n - minDist(s);
        cout<<k<<endl;
    }
    return 0;
}