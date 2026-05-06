// 화장실의 규칙 - 골드4
/* 문제
데카는 회사의 화장실을 이용하려고 했다.
하지만 수도 시설 고장으로 회사 내의 모든 화장실 사용이 금지됐고,
사원들은 단 하나의 임시 화장실을 이용해야 했다. 

임시 화장실의 앞에 데카를 포함한 N명의 사원이 대기하고 있다.
데카는 N명의 줄에서 K + 1번째로 줄을 섰다.
즉, 데카보다 먼저 도착한 사람이 K명이 있다.
줄이 길어지자 사장은 M개의 줄로 나눠서 대기하라 하였다.

N명의 사원은 순서대로 M개의 줄로 나눠 섰다.
기존 줄의 1번째 사원은 1번째 줄에, 2번째 사원은 2번째 줄에, ...
M번째 사원은 M번째 줄에, 그리고 M + 1번째 사원은 1번째 줄의 뒤에 서는 방식이다. 

M개의 줄로 나눠 선 것을 본 사장은 매우 흡족해하며 자리를 떠났다.

M개의 줄의 사원들은 암묵적으로 다음의 규칙에 따라 화장실을 이용하기로 하였다.

선두란, 어떤 줄에서 가장 먼저 와서, 가장 앞에 선 사람을 말한다.
M개의 줄의 선두 중 근무 일수 Di가 가장 높은 선두가 화장실을 이용한다.
M개의 줄의 선두 중 근무 일수 Di가 가장 높은 선두가 둘 이상인 경우,
    해당 선두들 중 화장실이 급한 정도 Hi가 가장 높은 선두가 화장실을 이용한다.
M개의 줄의 선두 중 근무 일수 Di가 가장 높은 선두가 둘 이상이며,
    해당 선두들의 화장실이 급한 정도 Hi도 모두 같다면,
    해당 선두 중 줄의 번호가 가장 낮은 줄에 선 선두가 화장실을 이용한다.

과연 몇 명의 사원이 화장실을 이용하고 나서야 데카의 차례가 올까?
매우 초조해지기 시작한 데카를 대신해 계산해주자.

- 입력
첫 번째 줄에는 임시 화장실에 대기하고 있는 사원의 수 N (1 ≤ N ≤ 105),
사장이 지시한 새로운 줄의 수 M (2 ≤ M ≤ 105),
데카가 화장실에 도착했을 때 자신의 앞에 서 있던 사원의 수 K (0 ≤ K ≤ N − 1)가 빈칸을 사이에 두고 주어진다.

두 번째 줄부터 각 N개의 줄에 임시 화장실에 i번째로 줄을 섰던
사원의 근무 일수 Di (0 ≤ Di ≤ 36,500),
화장실이 급한 정도를 나타내는 정수 Hi (0 ≤ Hi ≤ 108)가 가장 먼저 도착한 사원부터 빈칸을 사이에 두고 주어진다.

- 출력
데카가 화장실을 이용하기까지 몇 명의 사원이 화장실을 이용할 것인지 출력한다.

*/
#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

struct Person {
    int d, h, line, origIdx;
};

struct cmp {
    bool operator()(const Person& a, const Person& b) const {
        if (a.d != b.d) return a.d < b.d; // D 큰 게 우선
        if (a.h != b.h) return a.h < b.h; // H 큰 게 우선
        return a.line > b.line; // 줄 번호 작은 게 우선
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    vector<queue<Person>> lines(M);
    for (int i = 0; i < N; i++) {
        int d, h;
        cin >> d >> h;
        int lineIdx = i % M;
        lines[lineIdx].push({d, h, lineIdx, i});
    }

    priority_queue<Person, vector<Person>, cmp> pq;
    for (int i = 0; i < M; i++) {
        if (!lines[i].empty()) {
            pq.push(lines[i].front()); // 맨 앞 우선순위에 삽입
        }
    }

    int count = 0;
    while (!pq.empty()) {
        Person cur = pq.top();
        pq.pop();

        if (cur.origIdx == K) {
            cout << count << "\n";
            return 0;
        }

        count++;
        lines[cur.line].pop();
        if (!lines[cur.line].empty()) {
            pq.push(lines[cur.line].front());
        }
    }

    return 0;
}