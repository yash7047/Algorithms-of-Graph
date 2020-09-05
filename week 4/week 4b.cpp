#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define pp pair<ll,ll>
#define all(v) v.begin(),v.end()
#define sz(v) v.size()
#define F first 
#define S second 
#define lc "\n"
ll power(ll x,ll y,ll p){ll res=1;x=x%p;while(y>0){if(y&1)res=(res*x)%p;y=y>>1;x=(x*x)%p;}return res;} 
ll MAX=1e18 , MIN=-1e18 , MOD=1000000007;
int main() 
{
    fastio
    ll n,m,u,v,w,i,j,k,ans=0; cin>>n>>m;
    vector<ll>adj[m+1]; vector<ll>vis(n+1,0);
    for(i=1;i<=m;i++)
    {
        cin>>u>>v>>w;  adj[i].pb(u);
        adj[i].pb(v);  adj[i].pb(w);
    } 
    for(k=1;k<=n;k++)
    {
        if(!vis[k])
        {
            vector<ll>dist(n+1,MAX); dist[k]=0;
            for(i=1;i<=n-1;i++)
            {
                for(j=1;j<=m;j++)
                {
                    u=adj[j][0]; v=adj[j][1]; w=adj[j][2];
                    if(dist[u]!=MAX && dist[v]>dist[u]+w) dist[v]=dist[u]+w;        
                }
            }
            for(j=1;j<=m;j++)
            {
                u=adj[j][0]; v=adj[j][1]; w=adj[j][2];
                if(dist[u]!=MAX && dist[v]>dist[u]+w) 
                {ans=1;goto next;}        
            }
            for(i=1;i<=n;i++)
            if(dist[i]!=MAX) vis[i]=1;
        }
    }
    next: cout<<ans;
    return 0;
}