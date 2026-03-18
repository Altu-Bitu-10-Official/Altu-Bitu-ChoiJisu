// 서로 다른 부분 문자열의 개수 - 실버3
/* 문제
문자열 S가 주어졌을 때, S의 서로 다른 부분 문자열의 개수

부분 문자열은 S에서 연속된 일부분을 말하며, 길이가 1보다 크거나 같다.

예를 들어, ababc의 부분 문자열은
a, b, a, b, c, ab, ba, ab, bc, aba, bab, abc, abab, babc, ababc가 있고,
서로 다른것의 개수는 12개이다.
*/

// 힌트 : <string> 헤더의 substr 함수 사용

#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    string S;
    cin >> S;

    set<string> str;

    for (int i = 0; i < S.size(); i++)
    {
        for (int j = 1; j <= S.size() - i; j++)
        {
            str.insert(S.substr(i, j)); // S의 i번째 인덱스부터 j개의 문자열을 잘라서 set에 삽입
        }
    }

    cout << str.size() << '\n';

    return 0;
}