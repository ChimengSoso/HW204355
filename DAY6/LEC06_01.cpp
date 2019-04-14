/**
 *    author:  ChimengSoso
 *    created: Thu Jan 24 2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    // freopen("input.txt", "r", stdin);
    priority_queue<ll, vector<ll>, greater<ll> > pq;
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        int a; scanf("%d", &a);
        pq.push(a);
    }
    ll rlt = 0;
    while (pq.size() > 2) {
        ll a = pq.top(); pq.pop();
        ll b = pq.top(); pq.pop();
        rlt += a+b;
        pq.push(a+b);
    }
    rlt += pq.top(); pq.pop();
    rlt += pq.top(); pq.pop();
    cout << rlt;
    return 0;
}