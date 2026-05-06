// 꽃길 - 실버2
/* 문제
진아에게는 꽃의 씨앗이 세개밖에 없었으므로 세 개의 꽃이 하나도 죽지 않고 1년후에 꽃잎이 만개하길 원한다.

꽃밭은 N*N의 격자 모양이고 진아는 씨앗을 (1,1)~(N,N)의 지점 중 한곳에 심을 수 있다.
꽃의 씨앗은 그림 (a)처럼 심어지며 1년 후 꽃이 피면 그림 (b)모양[+]이 된다.

꽃을 심을 때는 주의할 점이있다. 어떤 씨앗이 꽃이 핀 뒤 다른 꽃잎(혹은 꽃술)과 닿게 될 경우 두 꽃 모두 죽어버린다. 또 화단 밖으로 꽃잎이 나가게 된다면 그 꽃은 죽어버리고 만다.

그림(c)는 세 꽃이 정상적으로 핀 모양이고 그림(d)는 두 꽃이 죽어버린 모양이다.

하이테크 앞 화단의 대여 가격은 격자의 한 점마다 다르기 때문에
진아는 서로 다른 세 씨앗을 모두 꽃이 피게하면서 가장 싼 가격에 화단을 대여하고 싶다.

단 화단을 대여할 때는 꽃잎이 핀 모양을 기준으로 대여를 해야하므로 꽃 하나당 5평의 땅을 대여해야만 한다.

돈이 많지 않은 진아를 위하여 진아가 꽃을 심기 위해 필요한 최소비용을 구해주자!


- 입력
입력의 첫째 줄에 화단의 한 변의 길이 N(6≤N≤10)이 들어온다.
이후 N개의 줄에 N개씩 화단의 지점당 가격(0≤G≤200)이 주어진다.

- 출력
꽃을 심기 위한 최소 비용을 출력한다.


* 힌트
    테두리를 제외한 칸 (n-2)*(n-2)개 중에서 3개를 고르는 조합을 구해서 각각의 조합에 대해서 꽃이 피는 모양이 겹치는지 확인하고 겹치지 않는다면 비용을 계산해서 최소값을 갱신하는 방식으로 풀이할 수 있다.

    3칸 중 어떤 두 칸 (r1, c1), (r2, c2)가 abs(r1-r2) + abs(c1-c2) <= 2 인 경우를 제외시키면 된다.

    칸을 고를 때, (n-2)*(n-2) 크기의 판에 순서대로 0~(n-2)*(n-2) -1 만큼의 숫자를 할당했다고 가정할 때,
    어떤 칸이 x(0<=x<(n-2)*(n-2))라면, 그 칸의 좌표는 (x/(n-2)+1, x%(n-2)+1)로 구할 수 있다.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<vector<int>> garden;

int getCost(int r, int c) {
    return garden[r][c] + garden[r - 1][c] + garden[r + 1][c] + garden[r][c - 1] + garden[r][c + 1];
}

bool isValid(vector<pair<int, int>>& flowers) {
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            int d = abs(flowers[i].first - flowers[j].first) + abs(flowers[i].second - flowers[j].second);
            if (d <= 2) { // 꽃이 겹치는 경우
                return false;
            }
        }
    }
    return true; // 모든 꽃이 겹치지 않는 경우
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    garden.resize(n, vector<int>(n));

    // 화단 가격 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> garden[i][j];
        }
    }

    int size = (n - 2) * (n - 2);
    
    vector<int> select(size, 0);
    fill(select.end() - 3, select.end(), 1); // 마지막 3개를 1로 설정하여 조합 생성

    int min_cost = 1e9; // 충분히 큰 값으로 초기화

    // 3개의 조합을 생성
    do {

        vector<pair<int, int>> store; // 꽃이 피는 위치 좌표 저장
        
        // 선택된 위치 좌표 계산
        for (int i = 0; i < size; i++) {
            if (select[i]) {
                int r = i / (n - 2) + 1;
                int c = i % (n - 2) + 1;
                store.push_back({r, c});
            }
        }

        if (isValid(store)) {
            int cost = 0;
            for (const auto& s : store) {
                cost += getCost(s.first, s.second);
            }
            min_cost = min(min_cost, cost);
        }
    } while (next_permutation(select.begin(), select.end()));

    cout << min_cost << "\n";
    return 0;
}