#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define bs binary_search
#define pb push_back
#define pp pair<ll,ll>
#define all(v) v.begin(),v.end()
#define F first 
#define S second 
#define lc "\n"
ll power(ll x,ll y,ll p){ll res=1;x=x%p;while(y>0){if(y&1)res=(res*x)%p;y=y>>1;x=(x*x)%p;}return res;} 
ll MAX=1e18 , MIN=-1e18 , MOD=1000000007;
void dfs(ll s,vector<ll>adj[],vector<ll>&vis)
{
    vis[s]=1; 
    for(auto i: adj[s])
    {
        if(!vis[i])
        dfs(i,adj,vis);
    }
}
int main() 
{
    fastio
    ll n,m,i,u,v,s,d; cin>>n>>m; 
    vector<ll>adj[n+1]; vector<ll>vis(n+1,0);
    for(i=1;i<=m;i++)
    {
        cin>>u>>v;
        adj[u].pb(v); adj[v].pb(u);
    }
    cin>>s>>d; dfs(s,adj,vis);
    if(vis[d]) cout<<1;
    else cout<<0;
    return 0;
}