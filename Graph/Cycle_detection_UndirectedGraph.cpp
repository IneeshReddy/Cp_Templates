#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mxN=1e5+10;
vector<int> adj[mxN];
vector<int> vis(mxN),par(mxN),ans;
int n,m; 
void dfs(int x,int p){
    vis[x]=1;
    par[x]=p;
    for(auto i:adj[x]){
        if(i==p)
            continue;
        if(vis[i]){
            int u=x;
           while(i^x){
               ans.push_back(x);
               x=par[x];
           }
           ans.push_back(i);
           ans.push_back(u);
           cout<<ans.size()<<endl;
           for(auto k:ans)
              cout<<k<<" ";
           exit(0);
        }
        else
            dfs(i,x);
        
    }
}
 
void solve(){
      cin>>n>>m;
      for(int i=0;i<m;i++){
        int x,y; cin>>x>>y;
        adj[x].push_back(y); adj[y].push_back(x);
      }
      for(int i=0;i<n;i++){
         if(vis[i])continue;
         dfs(i,-1);
      }
     cout<<"IMPOSSIBLE"<<endl;
      
}
 
 
 
 
 
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // int t; cin>>t;
    // while(t--)
    solve();
}