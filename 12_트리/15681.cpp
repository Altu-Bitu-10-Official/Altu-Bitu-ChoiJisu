#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, r, q;
    cin >> n >> r >> q;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 루트(r)에서 BFS로 방문 순서와 부모를 기록
    vector<int> parent(n + 1, 0);
    vector<int> order;
    order.reserve(n);
    vector<bool> visited(n + 1, false);

    queue<int> bq;
    bq.push(r);
    visited[r] = true;
    while (!bq.empty()) {
        int cur = bq.front();
        bq.pop();
        order.push_back(cur);
        for (int nxt : adj[cur]) {
            if (!visited[nxt]) {
                visited[nxt] = true;
                parent[nxt] = cur;
                bq.push(nxt);
            }
        }
    }

    // 자식(리프에 가까운 노드)부터 부모로 크기를 더해 올라감
    vector<int> size(n + 1, 1);
    for (int i = (int)order.size() - 1; i >= 0; i--) {
        int cur = order[i];
        if (cur != r) {
            size[parent[cur]] += size[cur];
        }
    }

    while (q--) {
        int u;
        cin >> u;
        cout << size[u] << "\n";
    }

    return 0;
}