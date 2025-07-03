#include <bits/stdc++.h>
using namespace std;


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


     int walk(int x, int i, int l, int r){
         if(tree[i] < x){
           return -1;
         }
         if(l == r){
           return l;
         }
         int m = (l + r) / 2;
         int left = walk(x, 2 * i, l, m);
         if(left != -1) return left;
         return walk(x, 2 * i + 1, m + 1, r);
     }


     SegTree(int n){
       tree.resize(4 * n);
       size = n - 1;
     }

     void set(int pos, int val) {set(pos, val, 1, 0, size); }
     int query(int lx, int rx) {return query(lx, rx, 1, 0, size); }

     int walk(int x) {return walk(x, 1, 0, size); }
};


int main () {
    // walk basically is a 
    //custom binary search on the segment tree that
    // finds the first position in the array where the segment value is at least x.

    // set is for point update
    // query is for range max
}