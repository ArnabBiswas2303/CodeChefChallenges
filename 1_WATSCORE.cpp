// Problem Link : https://www.codechef.com/DEC19B/problems/WATSCORE

#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int maxScore[11] = {0};
        int n,p,s;
        cin >> n;
        for (int i = 0; i < n; i++){
            cin>>p>>s;
            if(maxScore[p-1] < s){
                maxScore[p-1] = s;
            }
        }
        int sum = 0;
        for (int i = 0; i < 8; i++){
            sum += maxScore[i];
        }        
        cout<<sum<<endl;
    }
    return 0;
}