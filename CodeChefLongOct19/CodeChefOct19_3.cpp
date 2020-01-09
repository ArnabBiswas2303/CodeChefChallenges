// Link To The Website: https://www.codechef.com/OCT19B/problems/MARM

#include<bits/stdc++.h>
typedef unsigned long long ull;
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        ull N,K;
        cin >> N >> K;
        ull arr[N];        
        for(int i=0; i<N; i++){
            cin >> arr[i];
        }
        if(K < N){
            for(int i=0; i<K; i++){
                arr[i%N] = arr[i%N] ^ arr[N-(i%N)-1];
            }
        }else{
            int use = (K/N)%3;
            K = K%N;
            if(use == 0){
                use = 3;
            }
            // Prepare the array
            for(int j=0; j<use; j++){
                for(int i=0; i<N; i++){
                    arr[i%N] = arr[i%N] ^ arr[N-(i%N)-1];
                }
            }
            for(int i=0; i<K; i++){
                arr[i%N] = arr[i%N] ^ arr[N-(i%N)-1];
            }
        }
        for(int i=0; i<N; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;               
    }
    return 0;
}