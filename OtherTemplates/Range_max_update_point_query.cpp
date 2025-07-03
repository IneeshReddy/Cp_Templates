#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int) 1e18
                     
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

struct SegTree{
     int size;
     vector<int> tree;
     vector<int> lazy;

     int merge(int l, int r) {return max(l, r);}

     int query(int lx, int rx, int i, int l, int r){
          tree[i] = max(tree[i], lazy[i]);
          if(l != r){
             lazy[2 * i] = max(lazy[i], lazy[2 * i]);
             lazy[2 * i + 1] = max(lazy[i], lazy[2 * i + 1]);
          }
          lazy[i] = 0;
          if(l > rx || r < lx) return 0;
          if(l >= lx && r <= rx) return tree[i];
          int m = (l + r) / 2;
          int left = query(lx, rx, 2 * i, l, m);
          int right = query(lx, rx, 2 * i + 1, m + 1, r);
          return merge(left, right);
     }


     void set(int lx, int rx, int val, int i, int l, int r){
              tree[i] = max(tree[i], lazy[i]);
              if(l != r){
                 lazy[2 * i] = max(lazy[2 * i], lazy[i]);
                 lazy[2 * i + 1] = max(lazy[2 * i + 1], lazy[i]);
              }
              lazy[i] = 0;
              if(l > rx || r < lx){
                 return;
              }
              if(l >= lx && r <= rx){
                   tree[i] = max(tree[i], val);
                   if(l != r){
                     lazy[2 * i] = max(val, lazy[2 * i]);
                     lazy[2 * i + 1] = max(val, lazy[2 * i + 1]);
                   }
                   return;
              }
              int m = (l + r) / 2;
              set(lx, rx, val, 2 * i, l, m);
              set(lx, rx, val, 2 * i + 1, m + 1, r);
              tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
     }


     SegTree(int n){
       tree.resize(4 * n);
       lazy.resize(4 * n);
       size = n - 1;
     }

     void set(int lx, int rx, int val) {set(lx, rx, val, 1, 0, size); }
     int query(int lx, int rx) {return query(lx, rx, 1, 0, size); }
};

                     
                     
void Solve(){
      int n, q;
      cin >> n >> q;
      vector<int> v(n);
      SegTree st(n);
      while(q--){
           int z;
           cin >> z;
           if(z == 1){
              int l, r, val;
              cin >> l >> r >> val;
              r--;
              st.set(l, r, val);
           }  
           else{
               int i;
               cin >> i;
               cout << st.query(i, i) << '\n';
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