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
    ll n,m,i,j,u,v; cin>>n>>m;
    vector<ll>adj[n+1]; vector<ll>in(n+1,0);
    for(i=1;i<=m;i++)
    {
        cin>>u>>v;
        adj[u].pb(v); in[v]++;
    }
    queue<ll>q;  vector<ll>ans;
    for(i=1;i<=n;i++) 
    if(!in[i]) q.push(i);
    while(!q.empty())
    {
        j=q.front(); q.pop(); ans.pb(j);
        for(auto i: adj[j])
        {
            in[i]--;
            if(in[i]==0) q.push(i);
        }
    }
    for(auto i: ans) cout<<i<<" "; 
    return 0;
}