#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
 
 const int mxN=2e5+10;
 int up[mxN][30];
int n,q;
 
 
 
 
void solve(){
        cin>>n>>q;
        
        for(int i=1;i<=n;i++){
             cin>>up[i][0];
        }
        
 
        for(int j=1;j<30;j++){
              for(int i=1;i<=n;i++){
                  up[i][j]=up[up[i][j-1]][j-1];
              }
        }
 
        while(q--){
         
         int x,K; cin>>x>>K;
 
 
        for(int j=0;j<30;j++){
             if(K>>j&1){
                 x=up[x][j];
             }
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