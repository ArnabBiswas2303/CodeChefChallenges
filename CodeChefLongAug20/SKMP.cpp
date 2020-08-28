// Problem Link : https://www.codechef.com/AUG20B/problems/SKMP

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
        string s, p;
        string alpha = "abcdefghijklmnopqrstuvwxyz";
        int freq[27] = {0};
        cin >> s >> p;
        int slen = s.length();
        int plen = p.length();
        for (int i = 0; i < slen; i++) {
            int ind = s[i] - 'a';
            freq[ind]++;
        }
        for (int i = 0; i < plen; i++) {
            int ind = p[i] - 'a';
            freq[ind]--;
        }
        string ans1 = "", ans2 = "";
        int start = p[0] - 'a';
        for (int i = 0; i < 27; i++) {
            if (i == start) {
                ans1 += p;
            }
            if (i == (start + 1)) {
                ans2 += p;
            }
            for (int j = 0; j < freq[i]; j++) {
                ans1 += alpha[i];
                ans2 += alpha[i];
            }
        }
        if (ans1 < ans2)
            cout << ans1 << endl;
        else
            cout << ans2 << endl;
    }
    return 0;
}