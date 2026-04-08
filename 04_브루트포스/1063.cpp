// 킹 - 실버3
/* 문제
8*8크기의 체스판에 왕이 하나 있다. 킹의 현재 위치가 주어진다.
체스판에서 말의 위치는 다음과 같이 주어진다.
    알파벳 하나와 숫자 하나로 이루어져 있는데, 알파벳은 열을 상징하고, 숫자는 행을 상징한다.
    열은 가장 왼쪽 열이 A이고, 가장 오른쪽 열이 H까지 이고, 행은 가장 아래가 1이고 가장 위가 8이다.
    예를 들어, 왼쪽 아래 코너는 A1이고, 그 오른쪽 칸은 B1이다.

킹은 다음과 같이 움직일 수 있다.

R : 한 칸 오른쪽으로
L : 한 칸 왼쪽으로
B : 한 칸 아래로
T : 한 칸 위로
RT : 오른쪽 위 대각선으로
LT : 왼쪽 위 대각선으로
RB : 오른쪽 아래 대각선으로
LB : 왼쪽 아래 대각선으로

체스판에는 돌이 하나 있는데, 돌과 같은 곳으로 이동할 때는, 돌을 킹이 움직인 방향과 같은 방향으로 한 칸 이동시킨다. 아래 그림을 참고하자.


입력으로 킹이 어떻게 움직여야 하는지 주어진다. 입력으로 주어진 대로 움직여서 킹이나 돌이 체스판 밖으로 나갈 경우에는 그 이동은 건너 뛰고 다음 이동을 한다.

킹과 돌의 마지막 위치를 구하는 프로그램을 작성하시오.


- 입력
첫째 줄에 킹의 위치, 돌의 위치, 움직이는 횟수 N이 주어진다.
둘째 줄부터 N개의 줄에는 킹이 어떻게 움직여야 하는지 주어진다.
N은 50보다 작거나 같은 자연수이고, 움직이는 정보는 위에 쓰여 있는 8가지 중 하나이다.

- 출력
첫째 줄에 킹의 마지막 위치, 둘째 줄에 돌의 마지막 위치를 출력한다.

*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string king, stone;
    int n;
    cin >> king >> stone >> n;

    while(n--) {
        string move;
        cin >> move;

        int kx = king[0] - 'A'; // 알파벳을 숫자로 변환
        int ky = king[1] - '1'; // 숫자를 숫자로 변환
        int sx = stone[0] - 'A';
        int sy = stone[1] - '1';

        int dx = 0, dy = 0; // 이동 방향

        if (move == "R") {
            dx = 1;
        } else if (move == "L") {
            dx = -1;
        } else if (move == "B") {
            dy = -1;
        } else if (move == "T") {
            dy = 1;
        } else if (move == "RT") {
            dx = 1; dy = 1;
        } else if (move == "LT") {
            dx = -1; dy = 1;
        } else if (move == "RB") {
            dx = 1; dy = -1;
        } else if (move == "LB") {
            dx = -1; dy = -1;
        }

        int nkx = kx + dx; // 킹의 새로운 위치
        int nky = ky + dy;

        // 킹이 체스판 밖으로 나가는 경우
        if (nkx < 0 || nkx >= 8 || nky < 0 || nky >= 8) {
            continue; // 이동 건너뛰기
        }

        // 킹이 돌과 같은 위치로 이동하는 경우
        if (nkx == sx && nky == sy) {
            int nsx = sx + dx; // 돌의 새로운 위치
            int nsy = sy + dy;

            // 돌이 체스판 밖으로 나가는 경우
            if (nsx < 0 || nsx >= 8 || nsy < 0 || nsy >= 8) {
                continue; // 이동 건너뛰기
            }

            // 돌 이동
            stone[0] = nsx + 'A';
            stone[1] = nsy + '1';
        }

        // 킹 이동
        king[0] = nkx + 'A';
        king[1] = nky + '1';
    }

    cout << king << '\n' << stone << '\n';

    return 0;
}