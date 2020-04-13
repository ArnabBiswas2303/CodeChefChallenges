
#include "bits/stdc++.h" 
using namespace std; 

#define MAXN 1000001 
typedef long long ll;
ll spf[MAXN]; 

void sieve() 
{ 
	spf[1] = 1; 
	for (ll i=2; i<MAXN; i++) 
				
		spf[i] = i; 
		
	for (ll i=4; i<MAXN; i+=2) 
		spf[i] = 2; 

	for (ll i=3; i*i<MAXN; i++) 
	{ 		
		if (spf[i] == i) 
		{ 			
			for (ll j=i*i; j<MAXN; j+=i) 
								
				if (spf[j]==j) 
					spf[j] = i; 
		} 
	} 
} 

vector<ll> getFactorization(ll x) 
{ 
	vector<ll> ret; 
	while (x != 1) 
	{ 
		ret.push_back(spf[x]); 
		x = x / spf[x]; 
	} 
	return ret; 
} 

int main(int argc, char const *argv[]) 
{ 	
	sieve(); 
	for(ll i=0; i<MAXN; i++){
		cout<< spf[i] << endl;
	}
	ll x = 1000000; 
	// cout << "prime factorization for " << x << " : "; 
	
	vector <ll> p = getFactorization(x); 

	// for (ll i=0; i<p.size(); i++) 
	// 	cout << p[i] << " "; 
	// cout << endl; 
	return 0; 
} 
