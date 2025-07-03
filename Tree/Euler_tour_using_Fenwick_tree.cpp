#include<bits/stdc++.h>
using namespace std;
#define int long long
 
vector<int> v;
const int  mxN = 2e5 + 10;
vector<int> adj[mxN];
int n, q;
                
                     
int timer;       
vector<int> flat, in , out;        
int dp[2 * mxN + 10];
 
void upd(int i, int val){
    for(;i <= 2 * mxN; i += i & (-i)){
        dp[i] += val;
    }
}
 
int qry(int i){
     int ans = 0;
       for(;i;i -= i & (-i)){
         ans += dp[i];
       }
    return ans;
}
 
int qry(int l, int r){
    if(l == 1){
         return qry(r);
    }
    return qry(r) - qry(l - 1);
}
 
void dfs(int x,int c = -1){
     in[x] = timer++;
     flat[timer - 1] = v[x];
     upd(timer - 1,v[x]);
     for(auto i : adj[x]){
         if(i == c){
             continue;
         }
         dfs(i , x);
     }
     out[x] = timer;
}
                     
                     
void solve(){
            cin >> n >> q;
            timer = 1;
            in = vector<int> (n + 1);
            out = vector<int> (n + 1);
            flat = vector<int> (2 * n + 1);
            v = vector<int> (n + 1);
            for(int i = 1; i <= n; i++){
                 cin >> v[i];
            }
            for(int i = 0; i + 1 < n; i++){
                 int x , y;
                 cin >> x >> y;
                 adj[x].push_back(y);
                 adj[y].push_back(x);
            }
            dfs(1);
            while(q--){
                 int x;
                 cin >> x;
                 if(x == 1){
                     int y , val;
                     cin >> y >> val;
                     upd(in[y] , val - v[y]);
                     v[y] =  val;
                 }
                 else{
                    int y;
                    cin >> y;
                    int l = in[y] , r = out[y] - 1;
                    cout << qry(l, r) << '\n';
                 }
            }
 
}
                     
                     
                     
                     
                     
                     
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}