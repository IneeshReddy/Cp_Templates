#include<bits/stdc++.h>
using namespace std;
#define int long long
 
 
const int mxN=1e5+10;
vector<int> adj[mxN];
queue<int> q;
int indegree[mxN];
 
void solve(){
        int n,m; cin>>n>>m;
        vector<int> path;
        for(int i=0;i<m;i++){
            int x,y; cin>>x>>y;
            adj[x].push_back(y);
            indegree[y]++;
        }
        for(int i=1;i<=n;i++) if(!indegree[i]){
            q.push(i);
        }
        while(!q.empty()){
             int x=q.front();
             q.pop();
             path.push_back(x);
             for(auto i:adj[x]){
                 if(--indegree[i]==0){
                    q.push(i);
                 }
             }
        }
        if(path.size()<n){
            cout<<"IMPOSSIBLE"<<endl;
            return;
        }
        for(auto i:path)cout<<i<<" ";
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