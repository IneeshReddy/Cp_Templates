#include <bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// template <typename T, typename R> using o_map = tree<T, R, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


//Basic syntax of ordered set (o_set <int> s; s.insert(x);)same as in multisets

//s.*find_by_order(i) this is basically gives value at index i in ordered set
//s.order_of_key() This gives the number of elements less than the given element

// We have to use #define int at last 
// Otherwise we will get error

// All op are in O(log n) same as in multiset

#define int long long

int32_t main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    o_set<int> st;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        st.insert(x);
    }
    
    cout << *st.find_by_order(n - 2) << '\n';
    // Basically finds second largest element 
}





