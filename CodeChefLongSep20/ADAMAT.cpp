// Problem Link : https://www.codechef.com/SEPT20B/problems/ADAMAT

#include <bits/stdc++.h>
using namespace std;
#define whatis(x) cerr << #x << " is : " << x << endl;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> arr[i][j];
            }
        }
        bool colIterate = (arr[1][0] == 2) ? false : true;  // Iterate column wise or row wise
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (colIterate) {
                if (arr[0][i] != (i + 1)) {
                    ans++;
                    colIterate = false;
                }
            } else {
                if (arr[i][0] != (i + 1)) {
                    ans++;
                    colIterate = true;
                }
            }
        }
        if (!colIterate) {
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}