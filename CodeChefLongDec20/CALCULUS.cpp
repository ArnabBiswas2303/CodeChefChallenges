// Problem Link : https://www.codechef.com/DEC20A/problems/CALCULUS

#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define whatis(x) cerr << #x << " is " << x << endl;

unsigned long long fast_pow(unsigned long long base, unsigned long long n, unsigned long long M) {
    if (n == 0)
        return 1;
    if (n == 1)
        return base;
    unsigned long long halfn = fast_pow(base, n / 2, M);
    if (n % 2 == 0)
        return (halfn * halfn) % M;
    else
        return (((halfn * halfn) % M) * base) % M;
}

unsigned long long findMMI_fermat(unsigned long long n, unsigned long long M) {
    return fast_pow(n, M - 2, M);
}

unsigned long long MOD = 998244353;

int main() {
    unsigned long long n;
    cin >> n;
    n--;
    unsigned long long sum = 1;
    unsigned long long den = 3;    
    while(n--){
        sum += (findMMI_fermat(den,MOD));
        den += 2;
        sum %= MOD;
    }
    sum *= 2;
    sum %= MOD;    
    cout << sum << endl;
    return 0;
}