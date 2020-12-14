// Problem Link : https://www.codechef.com/DEC20A/problems/STROPERS

#include <bits/stdc++.h>
using namespace std;
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define whatis(x) cerr << #x << " is " << x << endl;

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

struct Node {
    char val;
    Node* left;
    Node* right;
    Node(char x) {
        val = x;
        left = right = NULL;
    }
} * root;

bool insert(Node** curr, char& c) {
    if (c == '1') {
        if ((*curr)->right == NULL) {
            (*curr)->right = new Node(c);
            (*curr) = (*curr)->right;
            return false;
        } else {
            (*curr) = (*curr)->right;
            return true;
        }
    } else {
        if ((*curr)->left == NULL) {
            (*curr)->left = new Node(c);
            (*curr) = (*curr)->left;
            return false;
        } else {
            (*curr) = (*curr)->left;
            return true;
        }
    }
}

void deleteNodes(Node* curr) {
    if (curr) {
        deleteNodes(curr->left);
        deleteNodes(curr->right);
        delete curr;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.length();
        root = new Node('$');
        map<pair<int, int>, vector<pair<int, int>>> leftRight;
        set<pair<pair<int, int>, pair<int, int>>> uniqueLeft;
        int ans = 0;

        int count[5];

        char prev;
        int pointer;
        int countZero = 0;
        int countOne = 0;

        for (int i = 0; i < n - 1; i++) {
            Node* curr = root;
            countZero = 0;
            countOne = 0;
            count[0] = count[1] = count[2] = count[3] = count[4] = 0;
            prev = (s[i] == '1') ? '1' : '0';
            pointer = (prev == '1') ? 0 : 1;

            for (int j = i; j < n; j++) {
                if (s[j] == '1')
                    countOne++;
                else {
                    countZero++;
                }
                pair<int, int> comb{countZero, countOne};
                bool poss = insert(&curr, s[j]);

                if (prev != s[j]) {
                    prev = s[j];
                    pointer++;
                }

                count[pointer] += 1;

                if (pointer == 2 && count[pointer] == 2) {
                    count[0] += count[pointer];
                    count[2] = 0;
                    pointer--;
                    prev = '0';
                } else if (pointer == 4) {
                    swap(count[1], count[3]);
                    count[0] += 1;
                    count[pointer] = 0;
                    pointer--;
                    prev = '0';
                }

                if (!poss) {
                    if (comb.second < 2) {
                        ans++;
                    } else {
                        // cout << "Count: " << count[0] << " ," << count[1] << endl;
                        uniqueLeft.insert({comb, {count[0], count[1]}});
                    }
                }
            }
        }

        ans += uniqueLeft.size();
        cout << ans << endl;
        deleteNodes(root);
    }
    return 0;
}