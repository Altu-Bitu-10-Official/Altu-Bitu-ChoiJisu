// 숫자 카드
#include <iostream>
#include <algorithm>

using namespace std;

int card[500000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> card[i];
    sort(card, card + n);

    int m;
    cin >> m;
    while (m--) {
        int x;
        cin >> x;
        cout << (binary_search(card, card + n, x) ? 1 : 0) << ' ';
        // 정렬된 범위에서 x의 존재 여부를 O(logN)에 판별
        // 있으면 1, 없으면 0 출력
    }
    return 0;
}