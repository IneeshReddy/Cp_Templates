#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int) 1e18
                     
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

// Question is to find the first element >= l which is at position >= j

struct SegTree{
     int size;
     vector<int> tree;

     int merge(int l, int r) {return max(l, r); }

     void set(int pos, int val, int i, int l, int r){
         if(l > pos || r < pos) return;
         if(l == r){ tree[i] = val; return; }
         int m = (l + r) / 2;
         set(pos, val, 2 * i, l, m);
         set(pos, val, 2 * i + 1, m + 1, r);
         tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
     }

     int query(int lx, int rx, int i, int l, int r){
          if(lx > r || rx < l) return 0;
          if(l >= lx && r <= rx) return tree[i];
          int m = (l + r) / 2;
          int left = query(lx, rx, 2 * i, l, m);
          int right = query(lx, rx, 2 * i + 1, m + 1, r);
          return merge(left, right);
     }


     int hue(int x, int lx, int rx, int i, int l, int r){
         if(tree[i] < x || lx > r || rx < l){
           return -1;
         }
         if(l == r){
           return l;
         }
         int m = (l + r) / 2;
         int left = hue(x, lx, rx, 2 * i, l, m);
         if(left != -1) return left;
         return hue(x, lx, rx, 2 * i + 1, m + 1, r);
     }


     SegTree(int n){
       tree.resize(4 * n);
       size = n - 1;
     }

     void set(int pos, int val) {set(pos, val, 1, 0, size); }
     int query(int lx, int rx) {return query(lx, rx, 1, 0, size); }

     int hue(int x, int lx) {return hue(x, lx, size, 1, 0, size); }
};

                     
                     
void Solve(){
        int n, q;
        cin >> n >> q;             
        vector<int> v(n);
        SegTree s(n);
        for(int i = 0; i < n; i++){
           cin >> v[i];
           s.set(i, v[i]);
        }
        while(q--){
            int z;
            cin >> z;
            if(z == 1){
               int i, val;
               cin >> i >> val;
               s.set(i, val);
            }
            else{
                int x, l;
                cin >> x >> l;
                int ans = s.hue(x, l);
                cout << ans << '\n';
            }
        }
}
                     
                     
int32_t main(){
   auto begin = std::chrono::high_resolution_clock::now();
   ios_base::sync_with_stdio(0);
   cin.tie(0);
                             
                             
   int T = 1;
  //  cin >> T;
   for(int i = 1; i <= T; i++) {
       //std::cout << "Case #" << i << ": ";
       Solve();
   }
                             
                             
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    //std::cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}