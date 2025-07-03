#include<bits/stdc++.h>
using namespace std;
#define int long long
 
int n,q; 
const int mxN=2e5+10;
vector<int> adj[mxN];
int dep[mxN];
vector<vector<int>> up(mxN,vector<int> (20));
 
void dfs(int x,int c=0){
     up[x][0]=c;
     for(int i=1;i<20;i++){
         up[x][i]=up[up[x][i-1]][i-1];
     }
     for(auto i:adj[x]){
         if(i==c)continue;
         dep[i]=dep[x]+1;
         dfs(i,x);
     }
}
 
 
void solve(){
    cin>>n>>q;
    for(int i=2;i<=n;i++){
         int x; cin>>x;
         adj[i].push_back(x);
         adj[x].push_back(i);
    }
    dfs(1);
    while(q--){
         int x,k; cin>>x>>k;
         if(dep[x]<k){
             cout<<-1<<endl;
             continue;
         }
         for(int j=0;j<20;j++){
             if(k>>j&1)
              x=up[x][j];
         }
         cout<<x<<endl;
    }
}
 
 
 
 
 
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // int t; cin>>t;
    // while(t--)
    solve();
}