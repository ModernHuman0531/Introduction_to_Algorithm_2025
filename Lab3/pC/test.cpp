#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to;
    long long w;
    int ti;
};

int n, m;
long long k;
vector<vector<Edge>> adj;

// ✅ 計算「從時間 t 開始要等多久」才能合法出發
// 禁止區間為 [ti - w + 1, ti] (mod k)
long long wait_time(long long t, long long w, int ti, long long k) {
    if (ti == -1) return 0;  // 永不維修，隨時可走

    long long mod = t % k;
    long long start = (ti - w + 1 + k) % k;
    long long end = ti;

    bool in_range = false;
    if (start <= end) in_range = (mod >= start && mod <= end);
    else in_range = (mod >= start || mod <= end);

    if (!in_range) return 0;
    return (ti - mod + 1 + k) % k;  // 等到維修結束後的下個時間
}

// ✅ Dijkstra (O((n+m) log n))
long long dijkstra() {
    const long long INF = LLONG_MAX / 4;
    vector<long long> dist(n + 1, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [t, u] = pq.top();
        pq.pop();
        if (t > dist[u]) continue;
        if (u == n) return t;

        for (auto &ed : adj[u]) {
            long long wait = wait_time(t, ed.w, ed.ti, k);
            // 若 wi >= k，且此路有維修點，一定會撞到（無法通行）
            if (ed.ti != -1 && ed.w >= k) continue;
            long long nt = t + wait + ed.w;
            if (nt < dist[ed.to]) {
                dist[ed.to] = nt;
                pq.push({nt, ed.to});
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    adj.assign(n + 1, {});

    for (int i = 0; i < m; ++i) {
        int u, v;
        long long w;
        int ti;
        cin >> u >> v >> w >> ti;
        adj[u].push_back({v, w, ti});
        adj[v].push_back({u, w, ti});
    }

    long long ans = dijkstra();
    cout << ans << "\n";
    return 0;
}
