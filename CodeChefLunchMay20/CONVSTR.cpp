#include <bits/stdc++.h>
#include <unordered_map>
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
        int ca[26] = {0};
        string a,b;
        cin >> a >> b;
        for(int i=0; i<n; i++){
            ca[a[i] - 'a'] = 1;
        }    
        bool flag = false;
        for(int i=0; i<n; i++){
            if(a[i] < b[i])
                flag = true;                
        }
        for(int i=0; i<n; i++){
            if(!ca[b[i]-'a'])
                flag = true;
        }
        if(flag){
            cout << -1 << endl;
        }else{
            vector< vector<int> > ans;
            for(char c='z'; c >='a'; c--){
                vector<int> v;
                for(int i=0; i<n; i++){
                    if(a[i] != c and b[i] == c)
                        v.push_back(i);
                }
                if(!v.empty()){
                    for(int i=0; i<n; i++){
                        if(a[i] == c){
                            v.push_back(i);
                            break;
                        }
                    }
                }
                if(!v.empty())
                    ans.push_back(v);
                for(int i=0; i<v.size(); i++){
                    a[v[i]] = c;
                }
            }
            cout << ans.size() << endl;
            for(int i=0; i<ans.size(); i++){
                cout << ans[i].size() << " ";
                for(int &x : ans[i])
                    cout << x << " ";
                cout << endl;
            }
        }
    }
    return 0;
}