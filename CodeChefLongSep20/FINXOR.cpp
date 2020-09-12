// Problem Link : https://www.codechef.com/SEPT20B/problems/FINXOR

#include <bits/stdc++.h>
using namespace std;
#define whatis(x) cerr << #x << " is : " << x << endl;
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long k = 1 << 20;
        cout << 1 << " " << k << endl;
        long long sum;
        cin >> sum;
        if (sum == -1) {
            exit(0);
        }
        sum -= (k * n);
        long long i = 0;
        k = 1 << i;
        long long diff = 0;
        vector<long long> digits;
        while ((sum - diff) > 0 && digits.size() < 19) {
            cout << 1 << " " << k << endl;
            long long q;
            if (q == -1) {
                exit(0);
            }
            cin >> q;
            long long sumMidColZero = ((q + sum) - (n * k)) / 2;
            long long noBits = (sum - sumMidColZero) / k;
            digits.push_back(noBits);
            diff += (noBits * k);
            k <<= 1;
        }
        if ((sum - diff) > 0) {
            digits.push_back(((sum - diff) / k));
        }
        long long ans = 0;
        for (int j = 0; j < digits.size(); j++) {
            if (digits[j] % 2) {
                ans |= 1 << j;
            }
        }
        cout << 2 << " " << ans << endl;
        int valid;
        cin >> valid;
        if (valid == -1) {
            exit(0);
        }
    }
    return 0;
}