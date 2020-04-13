// Problem Link : https://www.codechef.com/APRIL20B/problems/STRNO
#include <iostream>
#include <math.h>
using namespace std;
#define whatis(x) cerr << #x << " is : " << x <<endl; 
typedef long long ll;
ll numberOfPrimes(ll n){
	ll count = 0;
	for(ll i=2; i<=sqrt(n); i++){
		if(n%i == 0){					
			while(n%i == 0)				
				n/=i,++count;
		}
	}
	if(n != 1)
		++count;
	return count;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        ll n,k;
        cin >> n >> k;
        ll numP = numberOfPrimes(n);
        if(numP >= k)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}