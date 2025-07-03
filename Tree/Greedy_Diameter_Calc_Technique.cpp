#include<bits/stdc++.h>
using namespace std;
#define int long long
 
const int mxN=2e5+10;
int dp[mxN],dep1[mxN];
vector<int> adj[mxN];
int n;
 
void dfs(int x=1,int c=-1){
      for(auto i:adj[x]){
          if(i==c)continue;
          dp[i]=dp[x]+1;
          dfs(i,x);
      }
}
 
void dfs1(int x,int c=-1){
     for(auto i:adj[x]){
         if(i==c)continue;
         dep1[i]=dep1[x]+1;
         dfs1(i,x);
     }
}
void solve(){
          cin>>n;
          for(int i=0;i<n-1;i++) {
              int x,y; cin>>x>>y;
              if(x==y)continue;
              adj[x].push_back(y);
              adj[y].push_back(x);
          }
          dfs();
          int p=-1,x=0;
          for(int i=1;i<=n;i++){
             if(dp[i]>=x){
                x=dp[i];
                p=i;
             }
          }
          dfs1(p);
         int ans=0;
         for(int i=1;i<=n;i++)
          ans=max(ans,dep1[i]);
          cout<<ans<<endl;
} 
 
 
 
 
 
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // int t; cin>>t;
    // while(t--)
    solve();
}