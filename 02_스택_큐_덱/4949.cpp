// 균형잡힌 세상 - 실버4
/* 문제

어떤 문자열이 주어졌을 때, 괄호들의 균형이 잘 맞춰져 있는지 판단하는 프로그램

문자열에 포함되는 괄호는 소괄호("()") 와 대괄호("[]")로 2종류이고,
문자열이 균형을 이루는 조건은 아래와 같다.

모든 왼쪽 소괄호("(")는 오른쪽 소괄호(")")와만 짝을 이뤄야 한다.
모든 왼쪽 대괄호("[")는 오른쪽 대괄호("]")와만 짝을 이뤄야 한다.
모든 오른쪽 괄호들은 자신과 짝을 이룰 수 있는 왼쪽 괄호가 존재한다.
모든 괄호들의 짝은 1:1 매칭만 가능하다. 즉, 괄호 하나가 둘 이상의 괄호와 짝지어지지 않는다.

짝을 이루는 두 괄호가 있을 때,
그 사이에 있는 문자열도 균형이 잡혀야 한다. <= 괄호 안에 괄호도 만족해야 한다는 뜻


문자열이 주어졌을 때 균형잡힌 문자열인지 아닌지를 판단해보자.


- 입력
각 문자열은 마지막 글자를 제외하고
영문 알파벳, 공백, 소괄호("( )"), 대괄호("[ ]")로 이루어져 있으며,
온점(".")으로 끝나고, 길이는 100글자보다 작거나 같다.

- 출력
각 줄마다 해당 문자열이 균형을 이루고 있으면 "yes"를, 아니면 "no"를 출력


힌트 : cpp 입력 cin/cout 사용 많이 했는데 띄어쓰기 포함해 문장 받으려면?
- getline 함수
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;

    while (getline(cin, str))
    {
        if (str == ".")
        {
            break;
        }

        stack<char> s;
        bool check = true;

        for (char ch : str)
        {
            if (ch == '(' || ch == '[')
            {
                s.push(ch);
            }
            else if (ch == ')')
            {
                if (s.empty() || s.top() != '(')
                {
                    check = false;
                    break;
                }
                s.pop();
            }
            else if (ch == ']')
            {
                if (s.empty() || s.top() != '[')
                {
                    check = false;
                    break;
                }
                s.pop();
            }
        }

        if (!s.empty())
        {
            check = false;
        }

        cout << (check ? "yes" : "no") << "\n";
    }

    return 0;
}