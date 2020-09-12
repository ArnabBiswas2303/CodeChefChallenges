// Problem Link : https://www.codechef.com/SEPT20B/problems/TREE2

#include <bits/stdc++.h>

using namespace std;
#define whatis(x) cerr << #x << " is : " << x << endl;
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
typedef long long ll;
typedef unsigned long long ull;

int main() {
    int t;  // For the test cases
    cin >> t;
    while (t--) {
        int n;  // Number of sticks
        cin >> n;
        unordered_set<int> sticks;
        int x;
        for (int i = 0; i < n; i++) {
            cin >> x;
            if (x != 0)
                sticks.insert(x);
        }
        cout << sticks.size() << endl;
    }
    return 0;
}