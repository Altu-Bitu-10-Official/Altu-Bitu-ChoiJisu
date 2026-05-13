// 평행우주 - 실버3
/* 문제
* 지구(행성0)에서 출발 -> 행성1,2,...,n-1 순서대로 방문 -> 지구(행성n)로 복귀
* 지구에서만 속도를 올릴 수 있고, 그 후로는 떨어뜨리거나 유지만 가능
* 행성 i로 가려면 속도 v가 양의 정수배여야 함
* 지구에서 출발할 초기 속도의 최솟값 구하기

- 입력
첫째 줄에 *n*(1 ≤ *n* ≤ 3·105)이 주어진다.

둘째 줄에 *n*개의 정수 *v*1, *v*2, …, *vn*이 공백을 사이에 두고 주어진다. 모든 정수 1 ≤ *i* ≤ *n*에 대해 1 ≤ *vi* ≤ 109을 만족한다.

- 출력
수 하나를 출력한다. 이 수는 지구에서 올려야 하는 속도의 최솟값이다.
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<long long> v(n); // 속도가 최대 10^9이므로 long long으로 선언

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    long long ans = v[n-1]; // 마지막 단계(행성n-1 -> 행성n(지구)로 복귀) 속도

    // 속도를 줄일 수만 있고 늘릴 수 없으므로 거꾸로 탐색 - 뒤쪽부터 결정하면서 앞으로 가며 필요한 만큼 속도 키우기
    for (int i = n-2; i >= 0; i--) {
        // ans 이상이면서 v[i]의 배수인 최소 속도 구하기
        ans = ((ans + v[i] - 1) / v[i]) * v[i]; // ans를 v[i]로 나눈 후 올림하여 v[i]의 배수로 만듦
    }

    cout << ans << "\n";

    return 0;
}