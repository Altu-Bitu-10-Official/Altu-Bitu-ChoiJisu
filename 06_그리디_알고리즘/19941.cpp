// 햄버거 분배 - 실버3
/* 문제
* 사람(P)과 햄버거(H)가 일렬 배치
* 각 사람은 자신 위치 기준 거리 K 이내 햄버거 섭취 가능
* 햄버거 하나 당 한 사람만
* 햄버거를 먹는 사람의 최대 수 구하기

- 입력
첫 줄에 두 정수 $N$과 $K$가 있다. 그리고 다음 줄에 사람과 햄버거의 위치가 문자 P(사람)와 H(햄버거)로 이루어지는 길이 $N$인 문자열로 주어진다.

- 출력
첫 줄에 햄버거를 먹을 수 있는 최대 사람 수를 나타낸다.
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // 왼쪽에 있는 사람부터 차례로, 가능한 가장 왼쪽 햄버거 먹게 하기

    int n, k;
    string s;
    cin >> n >> k >> s;

    vector<bool> eaten(n, false); // 햄버거 사용 여부를 나타내는 벡터

    int ans = 0; // 햄버거를 먹는 사람 수

    for (int i = 0; i < n; i++) {
        if (s[i] != 'P') {
            continue; // 사람(P)이 아닌 경우 넘어감
        }
        
        // [i-k, i+k] 범위 내에서 가장 왼쪽에 있는 햄버거(H)를 찾음
        int left = max(0, i - k); // 범위의 왼쪽 끝
        int right = min(n - 1, i + k); // 범위의 오른쪽 끝

        for (int j = left; j <= right; j++) {
            if (s[j] == 'H' && !eaten[j]) { // 햄버거(H)이고 아직 먹히지 않은 경우
                eaten[j] = true; // 해당 햄버거를 먹음
                ans++; // 햄버거를 먹는 사람 수 증가
                break; // 다음 사람으로 넘어감
            }
        }
    }

    cout << ans << "\n";

    return 0;
}