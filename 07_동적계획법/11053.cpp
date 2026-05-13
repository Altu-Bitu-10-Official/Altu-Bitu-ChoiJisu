// 가장 긴 증가하는 부분 수열 - 실버3
/*
dp[i] = A[i]를 마지막 원소로 하는 가장 긴 증가하는 부분 수열의 길이로 정의.

- 점화식: dp[i] = max(dp[j]) + 1 (0 ≤ j < i, A[j] < A[i])
조건을 만족하는 j 없으면 dp[i] = 1(자기 자신만 포함)

=> 현재 숫자보다 앞에 있는 작은 숫자들을 찾고, 그 중 가장 긴 증가수열 뒤에 현재 숫자를 붙임
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int a[1001], dp[1001]; // 문제에서 최대 입력 크기: 1001
    // a[i] : i번째 수열 원소
    // dp[i] : a[i]를 마지막 원소로 하는 가장 긴 증가하는 부분 수열의 길이

    // 입력과 동시에 dp 초기화
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dp[i] = 1;  // 최소 길이는 1 (자기 자신만 선택해도 길이 1짜리 증가 수열)
    }

    // 점화식 적용 - 현재 위치 i보다 앞에 있는 모든 위치 j에 대해 검사
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) { // 증가하는 수열 조건 만족 여부
                dp[i] = max(dp[i], dp[j] + 1); // dp[j] + 1 : j까지의 증가 수열에 a[i]를 추가하는 경우
            }
        }
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dp[i]);
    }
    
    cout << ans << '\n';
    return 0;
}