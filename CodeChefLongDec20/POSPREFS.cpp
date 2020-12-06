// Problem Link : https://www.codechef.com/DEC20A/problems/POSPREFS

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
        int n, k;
        cin >> n >> k;
        int* arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = i + 1;
        }
        if (n / 2 <= k) {
            int remaining = n - k;
            for (int i = 0; i < n && remaining; i += 2, remaining--) {
                arr[i] = -arr[i];
            }
        } else {
            int i;
            for (i = 0; i < n && k; i += 2, k--) {
                arr[i] = -arr[i];
            }
            for (; i < n; i++) {
                arr[i] = -arr[i];
            }
        }
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}