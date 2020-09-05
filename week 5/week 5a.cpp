#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define pp pair<int,int>
#define all(v) v.begin(),v.end()
#define sz(v) v.size()
#define F first 
#define S second 
#define lc "\n"
ll power(ll x,ll y,ll p){ll res=1;x=x%p;while(y>0){if(y&1)res=(res*x)%p;y=y>>1;x=(x*x)%p;}return res;} 
ll MAX=1e18 , MIN=-1e18 , MOD=1000000007;
double dist(int x1,int y1,int x2,int y2)
{
    double s1=1.0*(x1-x2)*(x1-x2);
    double s2=1.0*(y1-y2)*(y1-y2);
    return sqrt(s1+s2);
}
int main() 
{
    fastio
    int n,i,u,v,w,j; cin>>n; pp a[n+1];
    vector<pair<int,double>>adj[n+1];  
    vector<int> par(n+1,-1),vis(n+1,0);  vector<double> key(n+1,1000000007.900);
    for(i=1;i<=n;i++) cin>>a[i].F>>a[i].S;
    for(i=1;i<=n-1;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            adj[i].pb({j,dist(a[i].F,a[i].S,a[j].F,a[j].S)});
            adj[j].pb({i,dist(a[i].F,a[i].S,a[j].F,a[j].S)});
        }
    }
    set<pair<double,int>>s; s.insert({0.0,1}); key[1]=0.0;
    while(s.size())
    {
        j=(*s.begin()).S; s.erase(*s.begin());
        vis[j]=1;
        for(auto i: adj[j])
        {
            if(!vis[i.F] && key[i.F]>i.S)
            {
                key[i.F]=i.S; par[i.F]=j;
                s.insert({key[i.F],i.F});
            }
        }
    }
    double sum=0.0;
    for(i=2;i<=n;i++) sum+=dist(a[i].F,a[i].S,a[par[i]].F,a[par[i]].S);
    cout<<fixed<<setprecision(7)<<sum;
    return 0;
}