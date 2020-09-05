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
    int n,m,i,j,u,v; cin>>n>>m;
    vector<int>adj[n+1]; vector<int>in(n+1,0),ans;
    for(i=1;i<=m;i++)
    {
        cin>>u>>v;
        adj[u].pb(v); in[v]++;
    }
    queue<int>q; 
    for(i=1;i<=n;i++)
    if(!in[i]) q.push(i);
    while(!q.empty())
    {
        j=q.front(); q.pop();
        ans.pb(j);
        for(auto i: adj[j])
        {
            in[i]--;
            if(in[i]==0) q.push(i);
        }
    }
    if(ans.size()!=n) cout<<1;
    else cout<<0;
    return 0;
}