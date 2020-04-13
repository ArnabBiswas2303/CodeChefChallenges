// Problem Link : https://www.codechef.com/APRIL20B/problems/SQRDSUB
#include <iostream>
#include <unordered_map>
using namespace std;
#define IOS ios_base::sync_with_stdio(false),cin.tie(NULL);
typedef long long ll;

ll countArr[100005];
ll countZeros[100005];

ll countOf2(ll n){
    ll count = 0;
    n = abs(n);
    while(n%2 == 0 && n > 0){
        n /= 2;
        count++;        
    }
    return count;
}
void fillCountArr(ll arr[], ll n){
    ll count = 0;    
    countArr[0] = 0;
    countZeros[0] = 0;
    for(ll i=0; i<n; i++){
        countArr[i+1] = countArr[i] + countOf2(arr[i]);
        if (arr[i] == 0) 
            count++; 
        countZeros[i+1] = count;
    }
}
bool query(ll a, ll b){
    if(countArr[b+1] - countArr[a] >= 2 || countZeros[b+1] - countZeros[a] > 0)
        return true;
    return false;
}
ll findSubArrayForFour(ll* arr, ll n) 
{ 
	ll ans = 0;
	for (ll i = 0; i < n; i++) {
		ll low = i, high = n - 1; 
		while (low <= high) { 
			ll mid = (low + high) >> 1; 
            bool x = query(i, mid);            
			if (x) 
				high = mid - 1; 
			else
				low = mid + 1; 
		}        
		ans += n - low; 
	} 
	return ans; 
}
ll findOddSubArray(ll arr[], ll n){
    ll s = 0;
    ll e = 0;
    ll p = 1;
    ll subArr = 0;
    ll result = 0;
    while(e < n){
        p *= arr[e];
        if(p % 2 != 0){            
            while(e<n && p%2 != 0){
                subArr += (e - s + 1);
                e++;
                p *= arr[e];                
            }
            result += subArr;
        }
        e++;
        s = e;
        subArr = 0;
        p = 1;
    }
    return result;
}
int main(){
    IOS
	ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll arr[n];
        for(ll i=0; i<n; i++){
            cin >> arr[i];            
        }
        fillCountArr(arr,n);        
        ll finalAns = findSubArrayForFour(arr, n);
        finalAns += findOddSubArray(arr,n);
        cout << finalAns << "\n"; 
    }
	return 0; 
} 