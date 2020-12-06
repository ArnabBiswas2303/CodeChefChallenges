// Problem Link : https://www.codechef.com/DEC20A/problems/EVENPSUM

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
        long long a, b;
        cin >> a >> b;
        long long aeven = a / 2;
        long long beven = b / 2;
        long long aodd = a - aeven;
        long long bodd = b - beven;
        long long ans = (aeven * beven) + (aodd * bodd);
        cout << ans << endl;
    }

    return 0;
}