// Link To The Website: https://www.codechef.com/OCT19B/problems/MSV

#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;

void storeAllFactors(unordered_map<int,int>& fac,int& n){
    for (int i=1; i<=sqrt(n); i++){ 
        if (n%i == 0) { 
            if(n/i == i)
                fac[i]++;
            else{
                fac[i]++;
                fac[n/i]++;
            }
        } 
    } 
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        unordered_map<int,int> fac;
        cin >> n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        int max = INT_MIN;
        if(n > 10000){
            storeAllFactors(fac,arr[0]);
            for(int i=1; i<n; i++){
                if(fac[arr[i]] > max){
                    max = fac[arr[i]];
                }
                storeAllFactors(fac,arr[i]);
            }
            cout<<max<<endl;
        }else{
            int temp;
            for(int i=0; i<n; i++){
                temp = 0;
                for(int j=i-1; j>=0; j--){
                    if(arr[j] % arr[i] == 0)
                        temp++;
                }
                if(temp > max)
                    max = temp;
            }
            cout<<max<<endl;
        }
    }
    return 0;
}