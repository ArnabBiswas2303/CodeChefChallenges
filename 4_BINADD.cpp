// Problem Link : https://www.codechef.com/DEC19B/problems/BINADD

#include<bits/stdc++.h>
using namespace std;

string andString(string& a, string& b){
    int n = a.length();
    string s(n,'0');
    for(int i=0; i<n; i++){
        if(a[i] == '1' && b[i] == '1')
            s[i]='1';
    }
    return s;
}

string xorString(string& a, string& b){
    int n = a.length();
    string s(n,'0');
    for(int i=0; i<n; i++){
        if(a[i] != b[i])
            s[i]='1';
    }
    return s;
}

void startIndex(string& andS,stack<int>& pos){
    int n = andS.length();        
    for(int i=0; i<n; i++){
        if(andS[i] == '1')
            pos.push(i);
    }    
}

int count(string& xorS,stack<int> pos){    
    int max = 1;
    while(!pos.empty()){
        int i = pos.top();
        pos.pop();
        int c = 1;
        while(--i > -1){
            if(xorS[i] == '1')
                ++c;
            else
                break;
        }
        if(c > max)
            max = c;
    }
    return max;
}

void checkLength(string& a, string& b){
    if(a.length() != b.length()){        
        if(a.length() < b.length()){
            int n = b.length() - a.length();
            for(int i=0; i<n; i++){
                a.insert(a.begin(),'0');
            }
        }else{
            int n = a.length() - b.length();
            for(int i=0; i<n; i++){
                b.insert(b.begin(),'0');
            }
        }
    }
}

bool isBZero(string& b){
    int n = b.length();
    for(int i=n-1; i>=0; i--){
        if(b[i] == '1')
            return false;
    }
    return true;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string a,b;
        cin >> a >> b;
        int ans;
        bool isZero = isBZero(b);
        checkLength(a,b);
        string andS,xorS;
        andS = andString(a,b);
        xorS = xorString(a,b);
        stack<int> pos;
        startIndex(andS,pos);
        if(pos.empty())
            ans = 0;
        else
            ans = count(xorS,pos);
        if(!isZero)
            ans++;
        cout<<ans<<endl;
    }
    return 0;
}