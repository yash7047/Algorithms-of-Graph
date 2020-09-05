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
int main() 
{
    fastio
    ll n,m,i,j,u,v,s,d; cin>>n>>m;
    vector<ll>adj[n+1]; vector<ll>dist(n+1,-1);
    vector<ll>vis(n+1,0);
    for(i=1;i<=m;i++)
    {
        cin>>u>>v;
        adj[u].pb(v); adj[v].pb(u);
    }
    cin>>s>>d;  dist[s]=0; vis[s]=1;
    queue<ll>q;  q.push(s);
    while(!q.empty())
    {
        j=q.front(); q.pop();
        for(auto i: adj[j])
        {
            if(!vis[i])
            {
                dist[i]=dist[j]+1;
                vis[i]=1; q.push(i); 
            }
        }
    }
    cout<<dist[d];
    return 0;
}