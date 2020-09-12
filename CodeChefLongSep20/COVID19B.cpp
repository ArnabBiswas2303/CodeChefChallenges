// Problem Link : https://www.codechef.com/SEPT20B/problems/COVID19B

#include <bits/stdc++.h>
using namespace std;
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define whatis(x) cerr << #x << " is : " << x << endl;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int minVal = 10;
        int maxVal = 0;
        vector<int> infected;
        for (int i = 0; i < n; i++) {
            int count = 1;
            int minSpeed = arr[i];
            int maxSpeed = arr[i];
            // slowest runner infront of me
            for (int j = i + 1; j < n; j++) {
                minSpeed = min(arr[j], minSpeed);
            }
            for (int j = i - 1; j >= 0; j--) {
                maxSpeed = max(arr[j], maxSpeed);
            }
            for (int j = i + 1; j < n; j++) {
                if (maxSpeed - arr[j] > 0)
                    count++;
            }
            for (int j = i - 1; j >= 0; j--) {
                if (arr[j] - minSpeed > 0)
                    count++;
            }
            infected.push_back(count);
        }

        for (int x : infected) {
            minVal = min(x, minVal);
            maxVal = max(x, maxVal);
        }
        cout << minVal << " " << maxVal << endl;
    }
    return 0;
}