// N과 M (11)
/*
## 문제

N개의 자연수와 자연수 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

- N개의 자연수 중에서 M개를 고른 수열
- 같은 수를 여러 번 골라도 된다.

## 입력

첫째 줄에 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 7)

둘째 줄에 N개의 수가 주어진다. 입력으로 주어지는 수는 10,000보다 작거나 같은 자연수이다.

## 출력

한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.

수열은 사전 순으로 증가하는 순서로 출력해야 한다.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> nums;
vector<int> picked;

void backtracking(int depth) {
    if (depth == m) {
        for (int x : picked) cout << x << ' ';
        cout << '\n';
        return;
    }
    for (int i = 0; i < (int)nums.size(); i++) {
        picked.push_back(nums[i]);
        backtracking(depth + 1);
        picked.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    nums.resize(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    // 같은 수를 여러 번 고를 수 있으므로, 중복 수열을 막으려면
    // 후보 집합 자체를 정렬 + 중복 제거하면 충분
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    backtracking(0);

    return 0;
}