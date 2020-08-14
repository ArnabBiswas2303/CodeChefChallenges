#include <bits/stdc++.h>
using namespace std;
#define whatis(x) cerr << #x << " is : " << x << endl;
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
typedef long long ll;
typedef unsigned long long ull;

const ll MOD = 1000000007;

ull fact[1000006];
ull freq[1000006];
ull remain[1000006];
ull ans[1000006];
ull ways[1000006];

ull fast_pow(ull base, ull n, ull M) {
    if (n == 0)
        return 1;
    if (n == 1)
        return base;
    ull halfn = fast_pow(base, n / 2, M);
    if (n % 2 == 0)
        return (halfn * halfn) % M;
    else
        return (((halfn * halfn) % M) * base) % M;
}

ull findMMI_fermat(ull n, ull M) {
    return fast_pow(n, M - 2, M);
}

ull nCr(ull n, ull r) {
    ull numerator, denominator, mmi_denominator;
    numerator = fact[n];
    denominator = (fact[r] * fact[n - r]) % MOD;
    mmi_denominator = findMMI_fermat(denominator, MOD);
    return (numerator * mmi_denominator) % MOD;
}

int main() {
    IOS;
    int t;
    cin >> t;
    fact[0] = 1;
    int j = 1;
    while (j <= 1000000) {
        fact[j] = (fact[j - 1] * j) % MOD;
        j++;
    }
    while (t--) {
        // Initialize
        memset(freq, 0, sizeof(freq));
        memset(remain, 0, sizeof(remain));
        memset(ans, 0, sizeof(ans));

        for (int i = 0; i < 1000006; i++) {
            ways[i] = 1;
        }

        ull n;
        cin >> n;
        ull* input = new ull[n + 4];
        // ull* order = new ull[n];
        ull* finalAns = new ull[n + 4];
        for (int i = 0; i < n; i++) {
            cin >> input[i];
            // order[i] = input[i];
            finalAns[i] = 0;
        }
        finalAns[n] = 0;

        // Sort the array in acesending order
        sort(input, input + n);

        // Count the frequency
        for (int i = 0; i < n; i++) {
            freq[input[i]]++;
            remain[input[i]]++;
        }

        ull total = 1;
        queue<ull> q;

        for (int i = 1000006; i >= 0; i--) {
            if (freq[i]) {
                ans[i] += total * freq[i];
                ans[i] %= MOD;
                total = ((total % MOD) * ((freq[i] + 1) % MOD)) % MOD;
                ways[i] = (freq[i] + 1);
                remain[i]--;
                if (remain[i])
                    q.push(i);
            }
        }
        ull r = 2;
        ull curr = q.size();
        while (!q.empty()) {
            if (curr == 0) {
                r++;
                curr = q.size();
            }
            curr--;

            ull num = q.front();
            q.pop();
            remain[num]--;
            if (remain[num])
                q.push(num);

            ull possibleComb = nCr(freq[num], r);
            total = total * fast_pow(ways[num], MOD - 2, MOD);
            total %= MOD;
            ull val = ((possibleComb % MOD) * (total % MOD)) % MOD;
            ans[num] = ((ans[num] % MOD) + (val % MOD)) % MOD;
            ways[num] = ways[num] + possibleComb;
            ways[num] %= MOD;
            total = ((total % MOD) * ((ways[num]) % MOD)) % MOD;
        }

        for (int i = 1; i <= n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
        cout.flush();
    }
    return 0;
}
