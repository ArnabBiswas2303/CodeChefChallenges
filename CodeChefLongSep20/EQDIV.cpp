// Problem Link : https://www.codechef.com/SEPT20B/problems/EQDIV
// 5 points Solution

#include <bits/stdc++.h>
using namespace std;
#define whatis(x) cerr << #x << " is : " << x << endl;
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
int main() {
    int k;
    cin >> k;
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        vector<int> ans(n + 1);
        long long a = 0;
        long long b = 0;
        long long sum = ((n * (n + 1)) / 2) / 2;
        for (int i = n; i > 0; i--) {
            if ((sum - i) >= 0) {
                sum -= i;
                ans[i] = 1;
                a += i;
            } else {
                ans[i] = 0;
                b += i;
            }
        }
        cout << abs(a - b) << endl;
        for (int i = 1; i <= n; i++) {
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}