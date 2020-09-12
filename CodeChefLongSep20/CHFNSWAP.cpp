// Problem Link : https://www.codechef.com/SEPT20B/problems/CHFNSWAP

#include <bits/stdc++.h>
using namespace std;
#define whatis(x) cerr << #x << " is : " << x << endl;
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

bool sumLeftLess(long& n, long long& totalSum) {
    long long leftSum = (n * (n + 1)) / 2;
    long long rightSum = totalSum - leftSum;
    if (leftSum <= rightSum)
        return true;
    return false;
}

bool rightEnd(long& target, long long& rightSum, long& pivot) {
    long reqNum = target - (rightSum - pivot);
    if (reqNum > 0 && reqNum <= pivot)
        return true;
    return false;
}

int main() {
    // FASTIO;
    long t;
    cin >> t;
    while (t--) {
        long n;
        cin >> n;
        if (n < 3)
            cout << 0 << "\n";
        else {
            long long totalSum = (n * (n + 1)) / 2;
            if (totalSum % 2) {
                cout << 0 << "\n";
                continue;
            }
            long l = 1, r = n;
            while (l < r) {
                long mid = (l + r) / 2;
                if (sumLeftLess(mid, totalSum)) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            long pivot = sumLeftLess(l, totalSum) ? l : l - 1;
            long target = totalSum / 2;
            long count = 0;
            long long sumLeft = (pivot * (pivot + 1)) / 2;
            if (sumLeft == target) {
                count += (pivot * (pivot - 1)) / 2;
                count += ((n - pivot) * (n - pivot - 1)) / 2;
            }
            long long rightSum = totalSum - ((pivot * (pivot + 1)) / 2);
            l = ++pivot;
            r = n;
            while (l < r) {
                long mid = (l + r) / 2;
                if (rightEnd(target, rightSum, mid))
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            if (rightEnd(target, rightSum, l)) {
                count += (l - pivot + 1);
            } else {
                count += (l - pivot);
            }
            cout << count << "\n";
        }
    }
    return 0;
}