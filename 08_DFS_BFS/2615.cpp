// 오목 - 실버1
/*
- 각 칸을 시작점으로 4가지 방향(가로, 세로, 우측 하단/상단 대각선)으로 같은 색이 5개 연속인지 확인
- 정확한 5개
- 가장 좌측 상단 좌표 출력 -> 각 방향 벡터를 양수 방향으로 잡으면, 시작점 자동으로 가장 좌측 상단이 됨
=> 좌측 상단 기준이므로 모든 방향을 행이 증가하는 방향으로 잡으면 5개 연속의 시작점이 곧 출력해야 하는 좌표가 됨
*/
// 완전 탐색
#include <iostream>

using namespace std;

int board[19][19];

// (행 증가 또는 같은 방향) 4가지 방향
const int dr[4] = {0, 1, 1, 1};
const int dc[4] = {1, 0, 1, -1};
    
inline bool inRange(int r, int c) {
    return 0 <= r && r < 19 && 0 <= c && c < 19;
}

int main() {
    // 입력
    for (int r = 0; r < 19; ++r) // 19x19 바둑판 입력
        for (int c = 0; c < 19; ++c) // 0: 빈 칸, 1: 검은 돌, 2: 흰 돌
            cin >> board[r][c];
    // 탐색
    for (int r = 0; r < 19; ++r) { // 모든 칸을 시작점으로
        for (int c = 0; c < 19; ++c) { // 0인 칸은 돌이 없으므로 건너뜀
            if (board[r][c] == 0) continue; // 돌이 있는 칸에서만 탐색 시작
            int color = board[r][c]; // 돌의 색깔 (1 또는 2)

            for (int d = 0; d < 4; ++d) { // 4가지 방향으로 탐색
                // 시작점 이전 칸이 같은 색이면 skip (중복 방지)
                int pr = r - dr[d], pc = c - dc[d]; // 시작점 이전 칸의 좌표 계산
                if (inRange(pr, pc) && board[pr][pc] == color) continue;

                // 5칸 연속 확인 - 5칸 모두 같은 색인지 확인
                bool ok = true;
                for (int k = 0; k < 5; ++k) {
                    int nr = r + dr[d] * k, nc = c + dc[d] * k; // k칸 이동한 좌표 계산
                    if (!inRange(nr, nc) || board[nr][nc] != color) { // 범위를 벗어나거나 색이 다르면 5목이 아님
                        ok = false;
                        break;
                    }
                }
                if (!ok) continue; // 5칸이 모두 같은 색이 아니면 다음 방향 탐색

                // 5번째 다음 칸이 같은 색이면 6목 이상이므로 무효
                int nr = r + dr[d] * 5, nc = c + dc[d] * 5; // 5칸 연속 다음 칸의 좌표 계산
                if (inRange(nr, nc) && board[nr][nc] == color) continue; // 6목 이상이면 무효이므로 다음 방향 탐색

                cout << color << "\n" << r + 1 << " " << c + 1 << "\n";
                return 0;
            }
        }
    }

    printf("0\n");
    return 0;
}