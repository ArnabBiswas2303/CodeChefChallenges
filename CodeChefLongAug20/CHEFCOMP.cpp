#include <bits/stdc++.h>
using namespace std;
#define whatis(x) cerr << #x << " is : " << x << endl;
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
typedef long long ll;
typedef unsigned long long ull;

bool visited[1000006];
int days[1000006];

// Recursively eat the fruits
void dfs(int** arr, int* b, int node, int& a, int& n, int& day) {
    visited[node] = true;
    b[node] -= min(b[node], a);
    if (days[node] == -1 && b[node] == 0) {
        days[node] = day;
    }
    for (int i = 1; i <= n; i++) {
        if (arr[node][i] && !visited[i]) {
            dfs(arr, b, i, a, n, day);
        }
    }
    visited[node] = false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        memset(visited, false, sizeof(visited));
        memset(days, -1, sizeof(days));

        // Declare the array
        int** arr = new int*[n + 1];
        for (int i = 0; i <= n; i++) {
            arr[i] = new int[n + 1];
        }

        // Initialize the array
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                arr[i][j] = 0;
            }
        }

        // Connect the nodes
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            arr[u][v] = 1;
            arr[v][u] = 1;
        }

        // Declare the arrays
        int* p = new int[n + 1];
        int* a = new int[n + 1];
        int* b = new int[n + 1];

        for (int i = 1; i <= n; i++) {
            cin >> p[i];
        }

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }

        // DFS on the tree from the current node
        // and eat the fruits of the reachable node
        for (int i = 1; i <= n; i++) {
            dfs(arr, b, p[i], a[p[i]], n, i);
            for (int j = 1; j <= n; j++) {
                if (arr[p[i]][j] == 1) {
                    arr[p[i]][j] = 0;
                    arr[j][p[i]] = 0;
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            cout << days[i] << " ";
        }
        cout << endl;

        // Delete the allocated memory
        for (int i = 0; i <= n; i++) {
            delete[] arr[i];
        }

        delete[] arr;
        delete[] p;
        delete[] a;
        delete[] b;
    }
    return 0;
}
