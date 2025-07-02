#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
const int mxN=1e5+10;
vector<int> adj[mxN];
int n,vis[mxN],m,path[mxN],par[mxN];
 
 
void dfs(int x,int c=-1){
     vis[x]=1;
     path[x]=1;
     par[x]=c;
     for(auto i:adj[x]){
        //  if(i==c)continue;
         if(!vis[i]){
            dfs(i,x);
         }
         else if(path[i]){
            int z=x;
            vector<int> ans;
            ans.push_back(z);
            while(z^i){
              z=par[z];
              ans.push_back(z);
            }
            reverse(ans.begin(),ans.end());
            ans.push_back(ans[0]);
            cout<<(int)ans.size()<<endl;
            for(auto i:ans){
                cout<<i<<" ";
            }
            cout<<endl;
            exit(0);
         }    
     }
     path[x]=0;
}
 
void solve(){
            cin>>n>>m;
            for(int i=0;i<m;i++){
                 int x,y; cin>>x>>y;
                 adj[x].push_back(y);
            }
            for(int i=1;i<=n;i++){
               if(vis[i])continue;
               dfs(i);
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