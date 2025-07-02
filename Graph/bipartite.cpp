#include<bits/stdc++.h>
using namespace std;
#define int long long
 
const int mxN=1e5;
vector<int> adj[mxN];
vector<int> vis(mxN),colour(mxN);
int n,m;
void solve(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y; cin>>x>>y;
        adj[x].push_back(y); adj[y].push_back(x);
    }
    bool ok=true;
    function<void(int,int)>dfs=[&](int x,int c){
        vis[x]=1;
        colour[x]=c;
        for(auto i:adj[x]){
            if(vis[i] && c==colour[i]){
                ok=false;
            }
            if(vis[i])continue;
           dfs(i,c^1);
        }
    };
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        dfs(i,0);
    }
    if(!ok){cout<<"IMPOSSIBLE"<<endl; return;}
    for(int i=1;i<=n;i++){
        cout<<colour[i]+1<<' ';
    }
    cout<<endl;
 
} 
 
 
 
 
 
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // int t; cin>>t;
    // while(t--)
    solve();
}