// Problem Link : https://www.codechef.com/APRIL20B/problems/COVIDLQ
#include <iostream>
using namespace std;
#define whatis(x) cerr << #x << " is : " << x <<endl; 
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
        bool flag = true;
        int pre = -1;
        for(int i=0; i<n; i++){
            if(arr[i] == 1){
                if(pre == -1)
                    pre = i;
                else if(i - pre < 6){
                    flag = false;
                    break;
                }else
                    pre = i;                   
            }             
        }
        if(flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}