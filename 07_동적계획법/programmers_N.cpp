// N으로 표현 - Lv.3
/* 문제 설명
아래와 같이 5와 사칙연산만으로 12를 표현할 수 있습니다.

12 = 5 + 5 + (5 / 5) + (5 / 5)
12 = 55 / 5 + 5 / 5
12 = (55 + 5) / 5

5를 사용한 횟수는 각각 6,5,4 입니다. 그리고 이중 가장 작은 경우는 4입니다.
이처럼 숫자 N과 number가 주어질 때, N과 사칙연산만 사용해서 표현 할 수 있는 방법 중 N 사용횟수의 최솟값을 return 하도록 solution 함수를 작성하세요.

- 제한사항
N은 1 이상 9 이하입니다.
number는 1 이상 32,000 이하입니다.
수식에는 괄호와 사칙연산만 가능하며 나누기 연산에서 나머지는 무시합니다.
최솟값이 8보다 크면 -1을 return 합니다.
*/
#include <string>
#include <vector>
#include <set>

using namespace std;

// dp[j]와 dp[k]의 원소들을 사칙연산으로 결합해 target 집합에 추가
void combine(set<int>& target, const set<int>& a, const set<int>& b) {
    for (int x : a) {
        for (int y : b) {
            target.insert(x + y);
            target.insert(x - y);
            target.insert(x * y);
            if (y != 0) target.insert(x / y);
        }
    }
}

// N을 i개 이어붙인 수 반환 (N=5, i=3 → 555)
int repunit(int N, int i) {
    long long result = 0;
    for (int k = 0; k < i; k++) result = result * 10 + N;
    return (result <= 32000) ? (int)result : -1;
}

int solution(int N, int number) {
    if (N == number) return 1;

    vector<set<int>> dp(9);

    // 이어붙인 수 초기화
    for (int i = 1; i <= 8; i++) {
        int r = repunit(N, i);
        if (r != -1) dp[i].insert(r);
    }

    // DP 채우기
    for (int i = 2; i <= 8; i++) {
        for (int j = 1; j < i; j++) {
            combine(dp[i], dp[j], dp[i - j]);
        }
        if (dp[i].count(number)) return i;
    }

    return -1;
}