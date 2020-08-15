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
        int h, p;
        cin >> h >> p;
        while (p) {
            h -= p;
            p /= 2;
        }
        if (h > 0)
            cout << 0 << endl;
        else
            cout << 1 << endl;
    }
    return 0;
}