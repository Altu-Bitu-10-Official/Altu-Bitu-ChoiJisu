#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

static int visited[8];
static int max_count;

// 던전 탐험을 시도하는 함수
void explore(int fatigue, int depth, int** dungeons, size_t dungeons_rows) {
    if (depth > max_count) {
        max_count = depth;
    }

    for (size_t i = 0; i < dungeons_rows; i++) {
        if (!visited[i] && fatigue >= dungeons[i][0]) {
            visited[i] = 1;
            explore(fatigue - dungeons[i][1], depth + 1, dungeons, dungeons_rows);
            visited[i] = 0;
        }
    }
}

// dungeons_rows는 2차원 배열 dungeons의 행 길이, dungeons_cols는 2차원 배열 dungeons의 열 길이입니다.
int solution(int k, int** dungeons, size_t dungeons_rows, size_t dungeons_cols) {
    // 정적 변수 초기화 (함수가 여러 번 호출될 경우를 대비)
    for (int i = 0; i < 8; i++) visited[i] = 0;
    max_count = 0;

    explore(k, 0, dungeons, dungeons_rows);

    return max_count;
}