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
bool bfs(ll s,vector<ll>adj[],vector<ll>&vis,vector<ll>&colour)
{
    queue<ll>q; q.push(s); 
    colour[s]=1; vis[s]=1;
    while(!q.empty())
    {
        ll j=q.front(); q.pop();
        for(auto i: adj[j])
        {
            if(!vis[i])
            {
                colour[i]=1-colour[j]; vis[i]=1;
                q.push(i);
            }
            else if(colour[i]==colour[j])
            return false;
        }
    }
    return true;
}
int main() 
{
    fastio
    ll n,m,i,u,v,f=1; cin>>n>>m; 
    vector<ll>adj[n+1]; vector<ll>vis(n+1,0);
    vector<ll>colour(n+1,0);
    for(i=1;i<=m;i++)
    {
        cin>>u>>v;
        adj[u].pb(v); adj[v].pb(u);
    }
    for(i=1;i<=n;i++)
    {
        if(!vis[i])
        f=(f&&bfs(i,adj,vis,colour));
    }
    cout<<(f?1:0);
    return 0;
}