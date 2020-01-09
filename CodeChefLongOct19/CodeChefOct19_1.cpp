// Link To The Website: https://www.codechef.com/OCT19B/problems/S10E

#include<bits/stdc++.h>
using namespace std;
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
        int count = 1;
        bool flag = true;
        for(int i=1; i<n; i++){
            // If less than 5 days
            if(i<5){
                for(int j=0; j<i; j++){
                    if(arr[i] >= arr[j])
                        flag = false;
                }
            }else{
            // If more than or equal to 5 days
                for(int j=(i-5); j<i; j++){
                    if(arr[i] >= arr[j])
                        flag = false;
                }
            }
            if(flag)
                count++;
            flag = true;
        }
        cout<<count<<endl;
    }
    return 0;
}