#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int) 1e18
                     
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};                     
                     
void Solve(){
     int n, m; cin >> n >> m;
     vector<vector<int>> vis(n, vector<int> (m)), d(n, vector<int> (m, INF));
     queue<pair<int,int>> q;  
     int cx, cy;             
     string s[n];
     for(int i = 0; i < n; i++){
         cin >> s[i];
         for(int j = 0; j < m; j++){
             if(s[i][j] == 'M'){
                q.push({i, j});
                d[i][j] = 0;
             }
             if(s[i][j] == 'A'){
                cx = i, cy = j;
             }
         }
     }
 
     auto check = [&](int i, int j){
         return i < n && i >= 0 && j < m && j >= 0 && s[i][j] != '#';
     };
 
     while(!q.empty()){
        auto [i, j] = q.front();
        q.pop();
        for(int k = 0; k < 4; k++){
             int x = i + dx[k], y = j + dy[k];
             if(check(x, y) && d[x][y] == INF){
                d[x][y] = d[i][j] + 1;
                q.push({x, y});
             }
        }
     }
     vector<vector<int>> d1(n, vector<int> (m, -1));
     d1[cx][cy] = 0;
     q.push({cx, cy});
     while(!q.empty()){
         auto [i, j] = q.front();
         q.pop();
         for(int k = 0; k < 4; k++){
             int x = i + dx[k], y = j + dy[k];
             if(check(x, y) && d1[x][y] == -1){
                d1[x][y] = d1[i][j] + 1;
                q.push({x, y});
             }
         }
     }
 
     vector<vector<int>> good(n, vector<int> (m));
     for(int i = 0; i < n; i++){
         for(int j = 0; j < m; j++){
             if(d1[i][j] < d[i][j] && (d[i][j] != INF || d1[i][j] != -1)){
                good[i][j] = 1;
             }
         }
     }
 
     string ans;
     vector<vector<pair<int,int>>> par(n, vector<pair<int,int>> (m, {-1, -1}));
     pair<int,int> p = {-1, -1};
 
 
     function<void(int, int)> dfs = [&](int x, int y){
          if(x == n - 1 || y == m - 1 || x == 0 || y == 0){
             p = {x, y};
             return;
          }
          vis[x][y] = 1;
          for(int i = 0; i < 4; i++){
             int x1 = x + dx[i], y1 = y + dy[i];
             if(check(x1, y1) && !vis[x1][y1] && good[x1][y1]){
                par[x1][y1] = {x, y};
                dfs(x1, y1);
             }
          }
     };
     dfs(cx, cy);
     if(p.first == -1 && p.second == -1){
        cout << "NO\n";
        return;
     }
 
 
     while(par[p.first][p.second].first != -1 && par[p.first][p.second].second != -1){
         auto [x, y] = p;
         auto [x1, y1] = par[x][y];
         if(x == x1){
            if(y > y1){
                ans.push_back('R');
            }
            else{
                ans.push_back('L');
            }
         }
         else{
            if(x < x1){
                ans.push_back('U');
            }
            else{
                ans.push_back('D');
            }
         }
         p = par[x][y];
     }
     reverse(ans.begin(), ans.end());
     cout << "YES\n" << (int)ans.size() << '\n';
     cout << ans << '\n';
}
                     
                     
int32_t main(){
   auto begin = std::chrono::high_resolution_clock::now();
   ios_base::sync_with_stdio(0);
   cin.tie(0);
                             
                             
   int T = 1;
//    cin >> T;
   for(int i = 1; i <= T; i++) {
       //std::cout << "Case #" << i << ": ";
       Solve();
   }
                             
                             
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    //std::cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}