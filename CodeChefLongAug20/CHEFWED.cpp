// Problem Link : https://www.codechef.com/AUG20B/problems/CHEFWED

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
        int n, k;
        cin >> n >> k;
        int freq[105] = {0};
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        // Take an extra row
        vector<vector<int> > ans(n + 1, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (i == j) {
                    ans[i][j] = k;
                } else if (freq[arr[j]]) {
                    if (freq[arr[j]] == 1)
                        ans[i][j] = ans[i][j - 1] + freq[arr[j]] + 1;
                    else
                        ans[i][j] = ans[i][j - 1] + 1;
                } else {
                    ans[i][j] = ans[i][j - 1];
                }
                freq[arr[j]]++;
            }
            for (int q = 0; q < 105; q++)
                freq[q] = 0;
        }
        for (int i = n - 1; i >= 0; i--) {
            int optimal = ans[i][n - 1];
            for (int j = i; j < n; j++) {
                optimal = min(optimal, ans[i][j] + ans[j + 1][n - 1]);
            }
            ans[i][n - 1] = optimal;
        }
        cout << ans[0][n - 1] << endl;
    }
    return 0;
}