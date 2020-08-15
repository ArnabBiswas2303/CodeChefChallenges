#include <bits/stdc++.h>
using namespace std;
#define whatis(x) cerr << #x << " is : " << x << endl;
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
typedef long long ll;
typedef unsigned long long ull;

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        ll x;
        ll minSteps = INT_MAX;
        ll ans = -1;
        for (int i = 0; i < n; i++) {
            cin >> x;
            if (x <= k) {
                if (k % x == 0) {
                    if (minSteps > k / x) {
                        minSteps = k / x;
                        ans = x;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}