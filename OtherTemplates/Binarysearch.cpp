#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define mod 1000000007

void solve()
{
    int n, x;
    cin >> n >> x;
    vector <int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    int l = 0, r = n - 1, ans = -1;
    while(l <= r) {
        int m = l + (r - l) / 2;
        if(arr[m] > x) {
            r = m - 1;
        }
        else{
            ans = m;
            l = m + 1;
        }
    }
    cout << ans << '\n';
    // binary search to find max index <= x in a sorted array
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}