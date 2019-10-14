// Link To Website: https://www.codechef.com/problems/EVEDG

#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> graph[], int u, int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void decNeighbours(vector<int> graph[], int& v, int deg[]){
    for(auto x : graph[v]){
        graph[x].erase(find(graph[x].begin(), graph[x].end(), v));
        deg[x]--;
    }
    graph[v].erase(graph[v].begin(),graph[v].end());
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        vector<int> graph[n+1];
        int u,v;
        int deg[n+1];
        int ans[n+1];
        for(int i=0; i<=n; i++){
            deg[i] = 0;
        }
        for(int i=0; i<=n; i++){
            ans[i] = 1;
        }
        for(int i=0; i<m; i++){
            cin >> u >> v;
            deg[u]++;
            deg[v]++;
            addEdge(graph,u,v);
        }
        if(m%2 == 0){
            cout<<1<<endl;
            for(int i=1; i<=n; i++){
                cout<<1<<" ";
            }
            cout<<endl;
        }else{
            int val = 2;
            int sum = 0;
            for(int i=1; i<=n; i++){
                sum += deg[i];
            }
            sum = sum / 2;
            while(sum%2 != 0){
                int odd = -1;
                for(int i=1; i<=n; i++){
                    if(deg[i]%2 != 0){
                        odd = i;
                    }
                }
                if(odd != -1){
                    ans[odd]= val;
                    val++;
                    deg[odd] = 0;
                    decNeighbours(graph,odd,deg);
                    sum = 0;
                    for(int i=1; i<=n; i++){
                        sum += deg[i];
                    }
                    sum = sum / 2;
                }else{
                    for (int i = 1; i <=n ; ++i) {
                        if(deg[i] % 2 ==0 && deg[i]!=0)
                            odd=i;
                    }
                    ans[odd]= val;
                    val++;
                    deg[odd] = 0;
                    decNeighbours(graph,odd,deg);
                }
            }
            int max = INT_MIN;
            for(int i=1; i<=n; i++){
                if(max < ans[i])
                    max = ans[i];
            }
            cout<<max<<endl;
            for(int i=1; i<=n; i++){
                cout<<ans[i]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}