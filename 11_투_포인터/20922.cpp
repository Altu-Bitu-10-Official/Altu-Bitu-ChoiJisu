// 겹치는 건 싫어
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    // right를 늘려가며 원소를 추가하고, 조건이 깨지면 left를 줄여 복구
    vector<int> cnt(100001, 0);
    int left = 0, ans = 0;

    for (int right = 0; right < N; right++) {
        cnt[a[right]]++; // 새 원소를 윈도우에 추가

        // a[right] 추가로 K개를 초과했다면, 그 값의 개수가 K 이하가 될 때까지 left를 전진
        while (cnt[a[right]] > K) {
            cnt[a[left]]--;
            left++;
        }

        // 현재 유효한 윈도우 길이로 최댓값 갱신
        ans = max(ans, right - left + 1);
    }

    cout << ans << "\n";
    return 0;
}