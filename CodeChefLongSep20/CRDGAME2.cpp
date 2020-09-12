// Problem Link : https://www.codechef.com/SEPT20B/problems/CRDGAME2

#include <bits/stdc++.h>
using namespace std;
#define whatis(x) cerr << #x << " is : " << x << endl;
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

const long long MOD = 1000000007;

unsigned long long fact[1000006];

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

unsigned long long nCr(unsigned long long n, unsigned long long r) {
    unsigned long long numerator, denominator, mmi_denominator;
    numerator = fact[n];
    denominator = (fact[r] * fact[n - r]) % MOD;
    mmi_denominator = findMMI_fermat(denominator, MOD);
    return (numerator * mmi_denominator) % MOD;
}

int main() {
    int t;
    cin >> t;
    fact[0] = 1;
    int j = 1;
    while (j <= 1000000) {
        fact[j] = (fact[j - 1] * j) % MOD;
        j++;
    }
    while (t--) {
        long long n;
        cin >> n;
        map<long long, long long> arr;
        long long ele;
        long long maxEle = -1;
        for (int i = 0; i < n; i++) {
            cin >> ele;
            maxEle = max(ele, maxEle);
            arr[ele] += 1;
        }
        long long totalPossible = 0;
        if (arr[maxEle] % 2 == 0) {
            totalPossible += fast_pow(2, arr[maxEle], MOD) - nCr(arr[maxEle], arr[maxEle] / 2);
        } else {
            totalPossible += fast_pow(2, arr[maxEle], MOD);
        }
        if (totalPossible < 0) {
            totalPossible += MOD;
            totalPossible %= MOD;
        }
        for (auto it = arr.begin(); it != arr.end(); it++) {
            if (it->first != maxEle) {
                totalPossible = (totalPossible % MOD) * fast_pow(2, it->second, MOD);
                totalPossible %= MOD;
            }
        }
        if (totalPossible < 0) {
            totalPossible += MOD;
            totalPossible %= MOD;
        }
        cout << totalPossible << endl;
    }
    return 0;
}