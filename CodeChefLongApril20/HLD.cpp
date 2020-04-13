// Problem Link : https://www.codechef.com/APRIL20B/problems/FCTRE
// Answer For Subtask #1 
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define whatis(x) cerr << #x << " is : " << x <<endl; 
#define IOS ios_base::sync_with_stdio(false),cin.tie(NULL);
#define N 100005
#define MAXA 1000001 
#define MOD 1000000007
typedef long long ll;
vector< vector<ll> > adj;
ll MAX;
ll chainId;
ll pos;
ll segTree[N * 4];
ll chain[N];
ll chainHead[N];
ll position[N];
ll subTreeSize[N];
ll parent[N][16];
ll level[N];
ll arr[N];
ll spf[MAXA]; 

void sieve(){ 
	spf[1] = 1; 
	for (ll i=2; i<MAXA; i++)
		spf[i] = i;
		
	for (ll i=4; i<MAXA; i+=2) 
		spf[i] = 2; 

	for (ll i=3; i*i<MAXA; i++){
		if (spf[i] == i){
			for (ll j=i*i; j<MAXA; j+=i)
				if (spf[j]==j)
					spf[j] = i;
		} 
	} 
} 
vector<ll> getFactorization(ll x){ 
	vector<ll> ret; 
	while (x != 1){ 
		ret.push_back(spf[x]); 
		x = x / spf[x]; 
	} 
	return ret; 
} 

ll countFactors(unordered_map<ll,ll> m){
    ll count = 1;
    for(auto x : m){
        count = ((count  % MOD) * ((x.second+1)  % MOD)) % MOD;
    }
    return count;
}

unordered_map<ll,ll> findFactors(ll n){    
    unordered_map<ll,ll> ans;
    vector<ll> factors = getFactorization(n);
    for(ll i=0; i<factors.size(); i++){
        ans[factors[i]] = ((ans[factors[i]] % MOD)  + (1  % MOD)) % MOD;
    }
    return ans;
}

void swap(ll& u,ll& v){
    ll temp;
    temp = u;
    u = v;
    v = temp;
}

void HLD(ll v, ll par, vector< unordered_map<ll,ll> >& baseArr, vector< unordered_map<ll,ll> >& primeFactors) {
    ll heavyChild = -1, heavySize = 0;
    chain[v] = chainId;
    position[v] = pos++;    
    for(ll p : adj[v]) {
        if(p != par) {
            if(subTreeSize[p] > heavySize) {
                heavySize = subTreeSize[p];
                heavyChild = p;                    
            }
        }
    }
    baseArr[pos] = primeFactors[v];
    if(heavyChild!=-1) {                
        HLD(heavyChild, v, baseArr, primeFactors);
    }    
    for(ll p : adj[v]) {
        if(p != par && p != heavyChild) {
            chainId++;
            chainHead[chainId] = p;            
            HLD(p, v, baseArr, primeFactors);
        }
    }
}


ll LCA(ll u,ll v){
    if(level[u] > level[v])
        swap(u,v);
    ll diff = level[v] - level[u];
    for(ll i=MAX; i>=0; --i){
        if((diff & (1<<i)) != 0) {
                v = parent[v][i];
        }
    }
    if(u == v)
        return u;
    for(ll i=MAX;i>=0;--i) {
        if(parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}

void dfs(ll v, ll par, ll l, vector< unordered_map<ll,ll> >& primeFactors) {
    parent[v][0] = par;
    for(ll i=1;i<=MAX;++i) {
        if(parent[v][i-1]!=0) {
            parent[v][i] = parent[parent[v][i-1]][i-1];
        }
    }    
    subTreeSize[v] += 1;
    level[v] = l;
    for(ll p : adj[v]) {
        if(p!=par) {
            dfs(p, v, l+1, primeFactors);
            subTreeSize[v]+=subTreeSize[p];
        }
    }
}

unordered_map<ll,ll> merge(unordered_map<ll,ll> a, unordered_map<ll,ll> b){
    unordered_map<ll,ll> x ;    
    for(auto it : a){
        x[it.first] = ((x[it.first]  % MOD) + (it.second  % MOD)) % MOD;
    }
    for(auto it : b){
        x[it.first] = ((x[it.first]  % MOD) + (it.second  % MOD)) % MOD;
    }    
    return x;
}

unordered_map<ll, ll> query(ll treein,ll low,ll high,ll l,ll r, vector< unordered_map<ll,ll> >& tree){
    if(l<=low && high<=r)
        return tree[treein];
    unordered_map<ll,ll> m;
    if(low>r || high<l)
        return m;
    ll mid = (low+high)>>1;
    unordered_map<ll,ll> m1 = query(2*treein,low,mid,l,r,tree);
    unordered_map<ll,ll> m2 = query(2*treein+1,mid+1,high,l,r,tree);
    unordered_map<ll,ll> m3 = merge(m1,m2);
    return m3;
}
unordered_map<ll, ll> query(ll l,ll r, ll n, vector< unordered_map<ll,ll> >& tree){
    unordered_map<ll,ll> m;
    if(l>r) {
        return m;
    }
    return query(1,0,n-1,l,r,tree);
}
unordered_map<ll,ll> queryUp(ll from, ll to, ll n, vector< unordered_map<ll,ll> >& tree){
    ll curr = from;
    unordered_map<ll,ll> ans;
    while(chain[curr] != chain[to]) {
        ans = merge(ans, query(position[chainHead[chain[curr]]], position[curr], n, tree));
        curr = parent[chainHead[chain[curr]]][0];
    }
    ans = merge(ans, query(position[to], position[curr], n, tree));
    return ans;
}

void build(ll treein,ll low,ll high, vector< unordered_map<ll,ll> >& tree, vector< unordered_map<ll,ll> >& baseArr){
    if(low==high){
        tree[treein] = baseArr[low+1];
    }
    else{
        ll mid = (low+high)/2;
        build(2*treein,low,mid, tree, baseArr);
        build(2*treein+1,mid+1,high, tree, baseArr);
        auto x = merge(tree[2*treein],tree[2*treein+1]);
        tree[treein] = x;
    }
}

int main(){
    IOS;
    ll t;
    cin >> t;
    sieve(); 
    while(t--){
        vector< unordered_map<ll,ll> > primeFactors(N);
        vector< unordered_map<ll,ll> > baseArr(N);
        vector< unordered_map<ll,ll> > tree(N*6); 
        ll n;
        cin >> n;
        ll u, v;
        vector< vector<ll> > a(n+1);
        adj = a;
        memset(arr,0,sizeof(arr));
        for(ll i=0; i<n-1; i++){
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(ll i=1; i<=n; i++){
            cin >> arr[i];
            primeFactors[i] = findFactors(arr[i]);
        }        
        MAX = log(n)/log(2);
        chainId = 0;
        pos = 0;
        memset(segTree,0,sizeof(segTree));
        memset(chain,0,sizeof(chain));
        memset(chainHead,0,sizeof(chainHead));
        memset(position,0,sizeof(position));
        memset(subTreeSize,0,sizeof(subTreeSize));
        memset(subTreeSize,0,sizeof(subTreeSize));
        memset(parent,0,sizeof(parent));
        memset(level,0,sizeof(level));               
        dfs(1,0,0,primeFactors);        
        chainHead[0] = 1;
        HLD(1,0,baseArr,primeFactors);
        build(1,0, n-1,tree, baseArr);
        ll q;
        cin >> q;
        while(q--){            
            ll l,r;
            cin >> l >> r;
            ll lca = LCA(l,r);
            unordered_map<ll,ll> m1 = queryUp(l,lca,n,tree);
            unordered_map<ll,ll> m2 = queryUp(r,lca,n,tree);            
            unordered_map<ll,ll> m3 = merge(m1,m2);            
            unordered_map<ll,ll> lc = primeFactors[lca];
            for(auto x : lc){
                m3[x.first] -= x.second;
            }
            cout << countFactors(m3) << endl;
        }
    }
    return 0;
}