// 어두운 굴다리
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> x;

// 높이 H로 0~N 모든 구간을 비출 수 있는지 검사
// 각 가로등은 [x-H, x+H]를 비춤
bool check(int H) {
    int covered = 0; // 현재까지 빈틈없이 비춰진 끝 위치
    for (int i = 0; i < M; i++) {
        // 다음 가로등의 왼쪽 끝이 covered보다 크면 그 사이에 어두운 구간 발생
        if (x[i] - H > covered) return false;
        covered = max(covered, x[i] + H);
    }
    return covered >= N; // 끝(N)까지 비췄는지 확인
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    x.resize(M);
    for (int i = 0; i < M; i++) cin >> x[i];

    // 높이에 대한 이분 탐색[parametric search]
    // H가 충분히 크면 항상 비출 수 있고, 작으면 못 비추는 단조성을 이용해 가능한 최소 높이 찾기
    // 최대 높이는 N
    int lo = 0, hi = N, ans = N;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) {
            ans = mid;   // mid로 가능 -> 더 작은 높이 탐색
            hi = mid - 1;
        } else {
            lo = mid + 1; // 불가능 -> 더 큰 높이 필요
        }
    }

    cout << ans << "\n";
    return 0;
}