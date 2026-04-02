// 숨바꼭질6 - 실버2
/* 문제
수빈이는 동생 N명과 숨바꼭질을 하고 있다.
현재 점 S에 있고,
동생은 A1, A2, ..., AN에 있다.

수빈이는 걸어서 이동을 할 수 있다.
수빈이의 위치가 X일때 걷는다면 1초 후에 X+D나 X-D로 이동할 수 있다.
수빈이의 위치가 동생이 있는 위치와 같으면, 동생을 찾았다고 한다.

모든 동생을 찾기위해 D의 값을 정하려고 한다.
가능한 D의 최댓값을 구해보자.
 => S + D = A1, S + 2D = A2, ... S + nD = An
    D는 모든 A - S의 최대공약수

 - 입력
// 동생 N명, 수빈이 위치 S
첫째 줄에 N(1 ≤ N ≤ 105)과 S(1 ≤ S ≤ 109)가 주어진다.
둘째 줄에 동생의 위치 Ai(1 ≤ Ai ≤ 109)가 주어진다.
동생의 위치는 모두 다르며, 수빈이의 위치와 같지 않다.

- 출력
가능한 D값의 최댓값을 출력
*/
#include <iostream>

using namespace std;

// 유클리드 호제법
int getGcdIter(int a, int b) {
    while(b!=0) { // while(b) 와 같음
        a%=b;
        swap(a,b);
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, s;
    cin >> n >> s;

    int d = 0;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        int diff = abs(a-s);
        d = getGcdIter(d, diff); // 최대공약수
    }
    cout << d << "\n";

    return 0;
}