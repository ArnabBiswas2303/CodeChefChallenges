// Problem Link : https://www.codechef.com/APRIL20B/problems/UNITGCD
#include <iostream>
#include <stdio.h>
using namespace std;
#define whatis(x) cerr << #x << " is : " << x <<endl; 
#define IOS ios_base::sync_with_stdio(false),cin.tie(NULL)
void evenNum(int n){
    for(int i=2; i<=n; i+=2){        
        printf("2 %d %d\n",(i-1),i);
    }
}
void oddNum(int n){        
    printf("3 1 2 %d\n",(n));
    for(int i=4; i<n; i+=2){
        printf("2 %d %d\n",(i-1),i);
    }
}
int main(){
    IOS;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;             
        if(n == 1){
            printf("1\n1 1\n");
            continue;
        }
        if(n == 2){
            printf("1\n2 1 2\n");
            continue;
        }
        if(n == 3){
            printf("1\n3 1 2 3\n");
            continue;
        }
        int days = (n/2);
        printf("%d\n",days);
        if(n%2 == 0)
            evenNum(n);
        else
            oddNum(n);
    }
    return 0;
}