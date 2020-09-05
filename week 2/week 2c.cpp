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
void dfs1(ll s,vector<ll>adj1[],vector<ll>&vis,stack<ll>&st)
{
    vis[s]=1;
    for(auto i: adj1[s])
    {
        if(!vis[i])
        dfs1(i,adj1,vis,st);
    }
    st.push(s);
}
void dfs2(ll s,vector<ll>adj2[],vector<ll>&vis)
{
    vis[s]=1; 
    for(auto i: adj2[s])
    {
        if(!vis[i])
        dfs2(i,adj2,vis);
    }
}
int main() 
{
    fastio
    ll n,m,i,j,u,v,ans=0; cin>>n>>m;
    vector<ll>adj1[n+1],adj2[n+1]; vector<ll>vis(n+1,0);
    for(i=1;i<=m;i++)
    {
        cin>>u>>v;
        adj1[u].pb(v); adj2[v].pb(u);
    }
    stack<ll>st;
    for(i=1;i<=n;i++)
    {
        if(!vis[i]) 
        dfs1(i,adj1,vis,st);
    }
    for(i=0;i<n+1;i++) vis[i]=0;
    while(!st.empty())
    {
        j=st.top(); st.pop();
        if(!vis[j])
        {
            ans++;
            dfs2(j,adj2,vis);
        }
    }
    cout<<ans;
    return 0;
}