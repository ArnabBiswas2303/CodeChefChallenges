// Problem Link : https://www.codechef.com/APRIL20B/problems/CARSELL
#include <iostream>
#include <algorithm>
using namespace std;
#define whatis(x) cerr << #x << " is : " << x <<endl; 
#define MOD 1000000007
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
        sort(arr,arr+n,greater<int>());
        unsigned long long sum = 0;
        for(int i=0; i<n; i++){
            if(arr[i] - i >= 0)
                sum = (sum + (arr[i] - i)) % MOD;            
        }
        cout << sum << endl;
    }
    return 0;
}