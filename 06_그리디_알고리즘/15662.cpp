// 톱니바퀴(2) - 골드5
/* 문제
* T개 톱니바퀴, 각각 8개의 톱니(N극=0, S극=1)
* 12시 방향부터 시계순으로 인덱스 0~7
* 톱니바퀴 i와 i+1이 맞닿는 부분:
    톱니바퀴 i의 3시 방향 => 인덱스 2
    톱니바퀴 i+1의 9시 방향 => 인덱스 6
* 한 톱니바퀴 회전 -> 인접 톱니바퀴에 연쇄적으로 영향 줌(단, 회전 결정은 회전 전 상태 기준)
    * 시계방향 회전: 인덱스 한 칸씩 뒤로 (0->1, 1->2, ..., 7->0)
    * 반시계방향 회전: 인덱스 한 칸씩 앞으로 (1->0, 2->1, ..., 0->7)

- 입력
첫째 줄에 톱니바퀴의 개수 T (1 ≤ T ≤ 1,000)가 주어진다.

둘째 줄부터 T개의 줄에 톱니바퀴의 상태가 가장 왼쪽 톱니바퀴부터 순서대로 주어진다. 상태는 8개의 정수로 이루어져 있고, 12시방향부터 시계방향 순서대로 주어진다. N극은 0, S극은 1로 나타나있다.

다음 줄에는 회전 횟수 K(1 ≤ K ≤ 1,000)가 주어진다. 다음 K개 줄에는 회전시킨 방법이 순서대로 주어진다. 각 방법은 두 개의 정수로 이루어져 있고, 첫 번째 정수는 회전시킨 톱니바퀴의 번호, 두 번째 정수는 방향이다. 방향이 1인 경우는 시계 방향이고, -1인 경우는 반시계 방향이다.

- 출력
총 K번 회전시킨 이후에 12시방향이 S극인 톱니바퀴의 개수를 출력한다.
*/
#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, K;
    cin >> T;
    vector<deque<int>> gears(T, deque<int>(8)); // 톱니바퀴 상태 저장
    for (int i = 0; i < T; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 8; j++) {
            gears[i][j] = s[j] - '0'; // 톱니바퀴 상태 입력
        }
    }

    cin >> K;
    while (K--) {
        int num, dir; // 회전시킨 톱니바퀴 번호와 방향 입력
        cin >> num >> dir;
        num--; // 0-based index로 변환

        // 각 톱니바퀴의 회전 방향 결정 (0이면 회전 안 함)
        vector<int> rot(T, 0); // 각 톱니바퀴의 회전 방향 저장
        rot[num] = dir; // 회전시킨 톱니바퀴의 방향 설정
        
        // 왼쪽으로 연쇄
        for (int i = num; i > 0; i--) {
            // gears[i-1]의 3시(인덱스2) vs gears[i]의 9시(인덱스6)
            if (gears[i-1][2] != gears[i][6]) { // 맞닿은 부분이 다르면 회전
                rot[i-1] = -rot[i]; // 반대 방향으로 회전
            } else {
                break; // 맞닿은 부분이 같으면 더 이상 연쇄되지 않음
            }
        }

        // 오른쪽으로 연쇄
        for (int i = num; i < T - 1; i++) {
            if (gears[i][2] != gears[i+1][6]) { // 맞닿은 부분이 다르면 회전
                rot[i+1] = -rot[i]; // 반대 방향으로 회전
            } else {
                break; // 맞닿은 부분이 같으면 더 이상 연쇄되지 않음
            }
        }

        // 각 톱니바퀴에 실제 회전 적용
        for (int i = 0; i < T; i++) {
            if (rot[i] == 1) {
                // 시계방향: 마지막 원소를 앞으로
                int last = gears[i].back();
                gears[i].pop_back();
                gears[i].push_front(last);
            }
            else if (rot[i] == -1) {
                // 반시계방향: 첫 원소를 뒤로
                int first = gears[i].front();
                gears[i].pop_front();
                gears[i].push_back(first);
            }
        }
    }

    // 12시 방향(인덱스 0)이 S극(1)인 톱니바퀴 개수 세기
    int count = 0;
    for (int i = 0; i < T; i++) {
        if (gears[i][0] == 1) {
            count++;
        }
    }
    cout << count << "\n";
    return 0;
}