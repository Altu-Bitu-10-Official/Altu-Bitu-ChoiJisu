// 회전 초밥
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, d, k, c;
    cin >> N >> d >> k >> c;

    vector<int> belt(N);
    for (int i = 0; i < N; i++) cin >> belt[i];

    vector<int> cnt(d + 1, 0);
    int kinds = 0; // 현재 윈도우에 들어 있는 서로 다른 종류의 수

    // 첫 윈도우 [0, k-1] 구성
    for (int i = 0; i < k; i++) {
        if (cnt[belt[i]] == 0) kinds++; // 새 종류가 처음 등장하면 kinds 증가
        cnt[belt[i]]++;
    }

    // 윈도우에 c가 이미 있으면 kinds 그대로, 없으면 +1
    int ans = kinds + (cnt[c] == 0 ? 1 : 0);

    for (int s = 1; s < N; s++) {
        int out = belt[s - 1];
        cnt[out]--;
        if (cnt[out] == 0) kinds--; // 마지막 하나가 빠지면 종류 사라짐

        int in = belt[(s + k - 1) % N];
        if (cnt[in] == 0) kinds++;
        cnt[in]++;

        // 쿠폰 포함 가짓수로 최댓값 갱신
        int cur = kinds + (cnt[c] == 0 ? 1 : 0);
        ans = max(ans, cur);
    }

    cout << ans << "\n";
    return 0;
}