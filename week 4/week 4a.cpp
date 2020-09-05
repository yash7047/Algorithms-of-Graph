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
    ll n,m,u,v,w,s,d,i,j; cin>>n>>m;
    vector<pp>adj[n+1]; vector<ll>dist(n+1,MAX); 
    set<pp>st;
    for(i=1;i<=m;i++)
    {
        cin>>u>>v>>w; 
        adj[u].pb({v,w}); 
    }
    cin>>s>>d;  dist[s]=0;
    st.insert({0,s});
    while(!st.empty())
    {
        j=(*st.begin()).S; st.erase(*st.begin());
        for(auto i: adj[j])
        {
            if(dist[i.F]>dist[j]+i.S) 
            {
                dist[i.F]=dist[j]+i.S;
                st.insert({dist[i.F],i.F});
            }
        }
    }
    cout<<(dist[d]==MAX?-1:dist[d]);
    return 0;
}