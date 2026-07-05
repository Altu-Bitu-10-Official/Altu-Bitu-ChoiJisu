#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
int idx = 0, n;

// 트리를 미리 만들지 않고 전위 순회 배열 자체를 range(하한,상한)로 잘라가며 재귀적으로 왼쪽/오른쪽 서브트리를 판별
void build(int low, int high) {
    if (idx == n) return;
    int val = arr[idx];
    if (val < low || val > high) return; // 이 범위에 속하는 노드가 더 없음

    idx++;
    build(low, val);   // 왼쪽 서브트리: low < x < val
    build(val, high);   // 오른쪽 서브트리: val < x < high
    cout << val << "\n"; // 왼 - 오 - 루트 순서로 출력: postorder
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x;
    while (cin >> x) arr.push_back(x);
    n = (int)arr.size();

    build(0, 1000001);

    return 0;
}