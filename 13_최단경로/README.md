### 📚 최단경로(Shortest Path)
###      Dijkstra / Floyd-Warshall / Bellman-Ford

#### 1. 개념
최단경로 알고리즘은 **그래프에서 한 정점(혹은 모든 정점) 사이의 가장 짧은 경로를 구하는 알고리즘**이다.
그래프의 특성(음수 간선 유무, 모든 쌍인지 한 쌍인지)에 따라 적합한 알고리즘이 다르며, 이번 수업에서는 대표적인 세 가지(다익스트라, 플로이드-워셜, 벨만-포드)를 다뤘다.
완전 탐색으로 모든 경로를 확인하면 시간 초과가 나는 문제들도, 상황에 맞는 알고리즘을 고르면 `O((V+E)logV)` ~ `O(V³)` 수준으로 해결할 수 있다.

#### 2. 동작 원리 — 다익스트라(Dijkstra)
**음수 간선이 없을 때**, 한 정점에서 모든 정점까지의 최단거리를 구하는 알고리즘이다.
우선순위 큐(최소 힙)를 이용해 매번 "아직 확정되지 않은 정점 중 거리가 가장 짧은 정점"을 꺼내 그 정점을 거쳐 갈 수 있는 다른 정점들의 거리를 갱신한다.
```cpp
vector<int> dijkstra(int start, int v, vector<vector<ci>> &graph) {
    vector<int> dist(v+1, INF);
    priority_queue<ci, vector<ci>, greater<>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (weight > dist[node]) continue; // 이미 더 짧은 경로로 확정된 정점

        for (auto &edge : graph[node]) {
            int next_node = edge.first;
            int next_weight = weight + edge.second;
            if (next_weight < dist[next_node]) {
                dist[next_node] = next_weight;
                pq.push({next_weight, next_node});
            }
        }
    }
    return dist;
}
```
> `1753_dijkstra.cpp`(최단경로)에서 직접 구현해봄. 한 정점에서 출발해 나머지 모든 정점까지의 최단거리를 우선순위 큐로 구했다.
> `1238_party.cpp`(파티)에서는 다익스트라를 **두 번** 활용했다. 원래 그래프로 한 번, **간선을 뒤집은 그래프**로 한 번 돌려서 "갈 때 최단거리"와 "올 때 최단거리"를 각각 구하고 더했다.

#### 3. 동작 원리 — 플로이드-워셜(Floyd-Warshall)
**모든 정점 쌍**에 대한 최단거리를 한 번에 구하는 알고리즘이다.
"중간 정점 k를 거쳐 가는 것이 더 짧은가?"를 모든 (i, j) 쌍에 대해 확인하며 갱신하는 것이 핵심이다.
```cpp
for (int k = 1; k <= n; ++k) {       // 중간 정점
    for (int i = 1; i <= n; ++i) {   // 출발 정점
        for (int j = 1; j <= n; ++j) { // 도착 정점
            graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
        }
    }
}
```
> `11404_floydWarshall.cpp`(플로이드)에서 직접 구현해봄. 간선이 여러 개면 최솟값으로 초기화한 뒤 3중 반복문으로 모든 쌍의 최단거리를 갱신했다.
> `2458_height.cpp`(키 순서)에서는 거리 대신 **"도달 가능 여부(비트셋)"** 를 같은 구조로 전파시켰다. `reach[i] |= reach[k]` 한 줄로 `i → k → j` 전이를 한 번에 처리해 `O(N³/64)`로 빠르게 계산했다.

#### 4. 동작 원리 — 벨만-포드(Bellman-Ford)
**음수 간선이 있을 수 있을 때** 한 정점에서 모든 정점까지의 최단거리를 구하는 알고리즘이다.
모든 간선을 `V-1`번 반복해서 완화(relax)시키고, 마지막에 한 번 더 반복했을 때도 갱신이 일어나면 **음수 사이클이 존재**한다고 판단한다.
```cpp
void bellmanFord() {
    dist[1] = 0;
    for (int i = 1; i <= n - 1; ++i) {           // V-1번 반복
        for (auto &e : edges) {
            int st = e.first.first, en = e.first.second, cost = e.second;
            if (dist[st] == INF) continue;
            if (dist[en] > dist[st] + cost) {
                dist[en] = dist[st] + cost;      // 완화
            }
        }
    }

    // 한 번 더 돌려서 갱신이 일어나면 음수 사이클 존재
    for (auto &e : edges) {
        int st = e.first.first, en = e.first.second, cost = e.second;
        if (dist[st] != INF && dist[en] > dist[st] + cost) {
            cout << -1;
            return;
        }
    }
}
```
> `11657_belman.cpp`(타임머신)에서 직접 구현해봄. `V-1`번 완화 후 한 번 더 검사해서 음수 사이클 유무를 판별하는 패턴을 익혔다.

#### 5. 세 알고리즘 비교 및 핵심 포인트
| 알고리즘 | 대상 | 음수 간선 | 시간복잡도 |
|---|---|---|---|
| 다익스트라 | 한 정점 → 전체 | 불가능 | `O((V+E)logV)` |
| 플로이드-워셜 | 모든 정점 쌍 | 가능(음수 사이클만 없으면) | `O(V³)` |
| 벨만-포드 | 한 정점 → 전체 | 가능 | `O(VE)` |

* 그래프에 **음수 간선이 있는지**, **모든 쌍을 구해야 하는지 한 쌍만 구하면 되는지**를 먼저 파악하고 알고리즘을 선택해야 한다.
* 다익스트라는 "이미 확정된 정점은 다시 방문하지 않는다"는 그리디한 성질을 이용하므로 음수 간선이 있으면 성립하지 않는다.
* 방향이 있는 그래프에서 "역방향 최단거리"가 필요하면, 간선을 뒤집은 그래프를 따로 만들어 같은 알고리즘을 재사용할 수 있다(`1238_party.cpp` 참고).
* 플로이드-워셜의 3중 반복문 구조는 거리뿐 아니라 **도달 가능성(불리언/비트셋)** 같은 다른 값에도 그대로 응용할 수 있다(`2458_height.cpp` 참고).

#### 6. 느낀 점
같은 "최단경로"라는 주제 안에서도 그래프의 조건(음수 간선 유무, 한 쌍 vs 모든 쌍)에 따라 완전히 다른 알고리즘을 써야 한다는 점이 인상 깊었다. 특히 다익스트라를 그래프를 뒤집어서 한 번 더 돌리는 것만으로 "왕복 거리" 문제를 풀 수 있었던 것처럼, 알고리즘 자체보다 **그래프를 어떻게 모델링하느냐**가 문제 해결의 핵심이라는 걸 체감했다. 플로이드-워셜의 갱신 구조를 거리 계산이 아닌 도달 가능성 판별에 그대로 재사용해본 것도, 알고리즘의 틀과 그 안에 들어가는 값(거리, 불리언 등)을 분리해서 생각하는 좋은 연습이 되었다.