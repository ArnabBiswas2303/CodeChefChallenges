// Problem Link : https://www.codechef.com/AUG20B/problems/CHEFCOMP

#include <bits/stdc++.h>

using namespace std;
#define whatis(x) cerr << #x << " is : " << x << endl;
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
typedef long long ll;
typedef unsigned long long ull;

int parent[300000];
int ans[300000];
int days[300000];
bool visited[300000];
vector<int> newTree[3000000];
vector<int> oldTree[3000000];

int findParent(int u) {
    if (u == parent[u])
        return u;
    return parent[u] = findParent(parent[u]);
}

void dfs(vector<int> newTree[], int curr, int p[], int a[], int b[], vector<ll>& garden, vector<int>& totalDays) {
    visited[curr] = true;
    garden.push_back(a[curr] + garden.back());
    totalDays.push_back(days[curr]);

    if (b[curr] <= garden.back()) {
        int ind = lower_bound(garden.begin(), garden.end(), b[curr]) - garden.begin();
        ans[curr] = totalDays[ind];
    }

    for (int child : newTree[curr]) {
        if (!visited[child]) {
            dfs(newTree, child, p, a, b, garden, totalDays);
        }
    }

    garden.pop_back();
    totalDays.pop_back();
}

int main() {
    IOS;
    int t;
    cin >> t;
    while (t--) {
        // Initialization
        memset(visited, false, sizeof(visited));
        memset(ans, -1, sizeof(ans));
        memset(days, 0, sizeof(days));
        int n;
        cin >> n;

        int* p = new int[n + 1];
        int* a = new int[n + 1];
        int* b = new int[n + 1];

        // Parent Initialization
        for (int i = 1; i <= n + 1; i++) {
            oldTree[i].clear();
            newTree[i].clear();
            parent[i] = i;
        }

        // INPUT
        int u, v;
        for (int i = 1; i <= n - 1; i++) {
            cin >> u >> v;
            oldTree[u].push_back(v);
            oldTree[v].push_back(u);
        }

        for (int i = 1; i <= n; i++) {
            cin >> p[i];
            days[p[i]] = i;
        }

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }

        // Form new tree
        for (int i = n; i > 0; i--) {
            int node = p[i];
            visited[node] = true;
            for (int child : oldTree[node]) {
                if (visited[child]) {
                    int par = findParent(child);
                    newTree[node]
                        .push_back(par);
                    newTree[par]
                        .push_back(node);
                    parent[par] = node;
                }
            }
        }

        // for (int i = 1; i <= n; i++) {
        //     cout << i << " :: ";
        //     for (int child : newTree[i]) {
        //         cout << child << " ";
        //     }
        //     cout << endl;
        // }

        vector<ll> garden;
        vector<int> totalDays;

        garden.push_back(0);
        totalDays.push_back(0);

        memset(visited, false, sizeof(visited));
        dfs(newTree, p[1], p, a, b, garden, totalDays);

        for (int i = 1; i <= n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}