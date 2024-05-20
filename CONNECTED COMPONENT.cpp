#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX=1e5+10;
vector<ll> g[MAX];
bool vis[MAX];

void dfs(ll vertex) {
    vis[vertex] = true;
    for(ll child : g[vertex]) {
        if(!vis[child]) {
         vis[child]=true;
            dfs(child); 
        }
    }
}
 
int main() {
    ll n, m;
    cin >> n >> m;
    for(ll i = 0; i < m; ++i) {
        ll v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
 
    ll cnt = 0; 
    for(ll i = 1; i <= n; i++) {
        if(!vis[i]) {
            dfs(i); 
            cnt++; 
        }
    }
 
    cout << cnt << endl; 
    return 0;
}
