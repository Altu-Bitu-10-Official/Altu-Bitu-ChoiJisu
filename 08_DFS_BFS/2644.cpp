// 촌수 계산 - 실버2
/*
- 부모-자식 관계를 양방향 그래프로 표현 후 두 사람 사이 최단 경로 길이 => 촌수
 * 부모와 자식은 1촌 - 간선 가중치 1
 * 촌수 = 두 노드 사이 간선 개수 => BFS 거리
=> 부모 -> 자식이지만 양방향으로 거슬러 올라가야 하므로(형제는 부모로 연결됨) 무방향 그래프로 만들기
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    int a, b;
    cin >> a >> b;

    int m;
    cin >> m;

    vector<vector<int>> graph(n + 1); // 인접 리스트 - 노드 번호 1부터 시작
    for (int i = 0; i < m; ++i) { // 부모-자식 관계 입력
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    // BFS로 a에서 b까지의 거리 계산
    vector<int> visited(n + 1, -1);
    visited[a] = 0; // 시작 노드의 촌수는 0
    queue<int> q;
    q.push(a);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur == b) break;
        for (int nxt : graph[cur]) {
            if (visited[nxt] == -1) {
                visited[nxt] = visited[cur] + 1;
                q.push(nxt);
            }
        }
    }

    cout << visited[b] << "\n";
    return 0;
}