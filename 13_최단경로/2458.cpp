#include <iostream>
#include <bitset>

using namespace std;

const int MAXN = 501;
bitset<MAXN> reach[MAXN]; // reach[i][j] = i번 학생이 j번 학생보다 작다고 알 수 있는지

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        reach[a][b] = 1; // a번 학생 키 < b번 학생 키
    }

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            if (reach[i][k]) {
                reach[i] |= reach[k];
            }
        }
    }

    int answer = 0;
    for (int i = 1; i <= n; ++i) {
        int cnt = 0;
        for (int j = 1; j <= n; ++j) {
            if (i == j) continue;
            if (reach[i][j] || reach[j][i]) cnt++;
        }
        if (cnt == n - 1) answer++; // 자신을 제외한 모든 사람과 순서를 비교할 수 있으면 확정
    }

    cout << answer << "\n";
    return 0;
}