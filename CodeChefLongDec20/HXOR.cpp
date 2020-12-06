// Problem Link : https://www.codechef.com/DEC20A/problems/HXOR

#include <bits/stdc++.h>
using namespace std;
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define whatis(x) cerr << #x << " is " << x << endl;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        long long x;
        cin >> n >> x;
        long long* arr = new long long[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long tillNow = 0;
        for (int i = 0; i < n - 1; i++) {
            for (long long j = 32; j >= 0; j--) {
                long long mask = 1LL << j;
                if (arr[i] & mask) {
                    if (mask & tillNow) {
                        arr[i] &= (~mask);
                        tillNow &= (~mask);
                    } else if (x) {
                        arr[i] &= (~mask);
                        tillNow |= mask;
                        x--;
                    }
                }
            }
        }
        arr[n - 1] ^= tillNow;
        if (x & 1 & (n == 2)) {
            arr[n - 2] ^= 1LL;
            arr[n - 1] ^= 1LL;
        }
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}