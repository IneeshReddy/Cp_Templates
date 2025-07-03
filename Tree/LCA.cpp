#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
vector<vector<int>> adj,up;
vector<int> dep,tin,tout;
int n,q;
int timer;
void dfs(int x,int c=0){
    if(x==1){
         up[x][0]=1;
    }
     else up[x][0]=c;
     for(int i=1;i<20;i++){
         up[x][i]=up[up[x][i-1]][i-1];
     }
     tin[x]=timer++;
     for(auto i:adj[x]){
         if(i==c)
          continue;
         dep[i]=dep[x]+1;
         dfs(i,x);
     }
     tout[x]=timer++;
}
 
 
bool check(int x,int y){
     return (tin[x]<=tin[y] && tout[x]>=tout[y]);
}
 
void solve(){
       cin>>n>>q;timer=0;
       tin=vector<int>(n+10);
       tout=vector<int> (n+10);
       adj=vector<vector<int>>(n+10);
       up=vector<vector<int>>(n+10,vector<int>(20));
       dep=vector<int>(n+1);
       for(int i=2;i<=n;i++){
         int x; cin>>x;
         adj[x].push_back(i);
         adj[i].push_back(x);
       }
       dfs(1);
       while(q--){
         int x,y; cin>>x>>y;
         if(check(x,y)){
          cout<<x<<endl;
          continue;
         }
         if(check(y,x)){
            cout<<y<<endl;
            continue;
         }
         for(int l=19;l>=0;l--){
             if(!check(up[x][l],y)){
              x=up[x][l];
             }
         }
         cout<<up[x][0]<<endl;
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