#include<bits/stdc++.h>
using namespace std;
 
                     
void Solve()
{                    
    int n;
    cin >> n;
    string s[n];
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
 
    string ans;
    ans.push_back(s[0][0]);
 
    vector <vector <pair <int, int>>> d(2 * n - 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            d[i + j].push_back({i, j});
        }
    }
 
    vector <vector <int>> vis(n, vector <int> (n));
    vis[0][0] = 1;
 
    for (int len = 1; len <= 2 * n - 2; len++) {
        char c = '~';
        for (auto [x, y] : d[len]) {
            if (x - 1 >= 0 && vis[x - 1][y]) {
                c = min(c, s[x][y]);
            }
            if (y - 1 >= 0 && vis[x][y - 1]) {
                c = min(c, s[x][y]);
            }
        }
 
        ans.push_back(c);
        for (auto [x, y] : d[len]) {
            bool ok = false;
            ok |= (x - 1 >= 0 && vis[x - 1][y] && s[x][y] == c);
            ok |= (y - 1 >= 0 && vis[x][y - 1] && s[x][y] == c);
 
            if (ok) {
                vis[x][y] = 1;
            }
        }
    }
 
    cout << ans << '\n';
}
                     
int32_t main()
{                              
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