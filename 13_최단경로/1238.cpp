#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int> ci;
const int INF = 987654321;

// 다익스트라: start에서 각 정점까지의 최단거리 벡터 반환
vector<int> dijkstra(int start, int v, vector<vector<ci>> &graph) {
    vector<int> dist(v+1, INF);
    priority_queue<ci, vector<ci>, greater<>> pq;
    // first: 시작점으로부터의 거리, second: 정점

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int weight = pq.top().first; // 현재 정점까지의 경로값
        int node = pq.top().second;  // 현재 탐색하려는 정점
        pq.pop();

        if (weight > dist[node]) { // 이미 더 작은 값으로 기록된 정점
            continue;
        }

        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i].first;
            int next_weight = weight + graph[node][i].second;

            if (next_weight < dist[next_node]) { // 갱신
                dist[next_node] = next_weight;
                pq.push({next_weight, next_node});
            }
        }
    }
    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, x;
    cin >> n >> m >> x;

    vector<vector<ci>> graph(n+1);   // 원래 방향 (마을 -> ... -> X 로 갈 때 사용)
    vector<vector<ci>> rgraph(n+1);  // 뒤집은 방향 (X -> ... -> 마을 로 갈 때 사용)

    while (m--) {
        int a, b, t;
        cin >> a >> b >> t;
        graph[a].push_back({b, t});
        rgraph[b].push_back({a, t});
    }

    // 갈 때(마을 -> X): rgraph에서 X를 시작점으로 다익스트라
    vector<int> toX = dijkstra(x, n, rgraph);

    // 올 때(X -> 마을): graph에서 X를 시작점으로 다익스트라
    vector<int> fromX = dijkstra(x, n, graph);

    int answer = 0;
    for (int i = 1; i <= n; ++i) {
        answer = max(answer, toX[i] + fromX[i]);
    }

    cout << answer << "\n";
    return 0;
}