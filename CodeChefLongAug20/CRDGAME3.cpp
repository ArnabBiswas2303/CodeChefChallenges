// Problem Link : https://www.codechef.com/AUG20B/problems/CRDGAME3

#include <bits/stdc++.h>
using namespace std;
#define whatis(x) cerr << #x << " is : " << x << endl;
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
typedef long long ll;
typedef unsigned long long ull;

int numDigit(int n) {
    int count = 0;
    count += (n % 9) ? 1 : 0;
    count += n / 9;
    return count;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int cp, cr;
        cin >> cp >> cr;
        int chef, rick;
        chef = numDigit(cp);
        rick = numDigit(cr);
        if (chef < rick) {
            cout << 0 << " " << chef << endl;
        } else {
            cout << 1 << " " << rick << endl;
        }
    }
    return 0;
}