// Problem Link : https://www.codechef.com/APRIL20B/problems/ANSLEAK
#include <iostream>
#include <climits>
using namespace std;
#define whatis(x) cerr << #x << " is : " << x <<endl; 
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m,k;
        cin >> n >> m >> k;
        int arr[n][k];        
        for(int i=0; i<n; i++){
            for(int j=0; j<k; j++){
                cin >> arr[i][j];
            }
        }
        int ans[n];
        int count[m+1];
        for(int i=0; i<n; i++){
            for(int j=1; j<=m; j++){
                count[j] = 0;
            }
            for(int j=0; j<k; j++){
                count[arr[i][j]] += 1;
            }            
            int maxCount = INT_MIN;
            int index;
            for(int j=1; j<=m; j++){                
                if(maxCount < count[j]){
                    maxCount = count[j];
                    index = j;
                }
            }
            ans[i] = index;
        }
        for(int i=0; i<n; i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}