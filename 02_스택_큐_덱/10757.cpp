// 큰 수 A+B - 브론즈4
/* 문제
두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성

- 입력
첫째 줄에 A와 B가 주어진다.(0 < A,B < 10^10000)
=> int 범위 훨씬 넘어섬 => string으로 받아서 해결

- 출력
첫째 줄에 A+B를 출력

*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a, b;
    cin >> a >> b;

    // 두 문자열의 길이 중 최대 길이
    int lenA = a.length();
    int lenB = b.length();
    int maxLen = max(lenA, lenB);

    vector<int> result;
    int carry = 0;

    // 끝에서부터 하나씩 더하기
    for (int i = 1; i <= maxLen; i++)
    {
        // 현재 자리의 숫자 담을 변수
        int curA = 0;
        int curB = 0;

        // a의 끝에서 i번째 자리 있으면 문자에서 숫자로 변환
        if (i <= lenA)
        {
            curA = a[lenA - i] - '0';
        }

        // b의 끝에서 i번째 자리 있으면 문자에서 숫자로 변환
        if (i <= lenB)
        {
            curB = b[lenB - i] - '0';
        }

        int sum = curA + curB + carry;
        result.push_back(sum % 10); // 현재 자리에 쓸 숫자
        carry = sum / 10; // 다음 자리로 넘길 올림수
    }

    // carry 남아있으면 최상위 자리 추가
    if (carry > 0)
    {
        result.push_back(carry);
    }

    // 끝에서 더했으므로 역순으로 출력
    for (int i = result.size() - 1; i >= 0; i--)
    {
        cout << result[i];
    }
    cout << "\n";

    return 0;
}