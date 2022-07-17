#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;
vector<char> vec;

// 균형잡힌 괄호 문자열 찾기
string find_u(string p) {
    vector<char> v;
    for (int i = 0; i < p.length(); i++)
        v.push_back(p[i]);

    int index = 0;
    int right = 0, left = 0; //  right =  ')',  left = '('
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == '(') left++;
        else right++;

        // left와 right의 개수가 같으면 그 index 저장해서 탈출
        if (left == right) {
            index = i;
            break;
        }
    }

    
    return p.substr(0, index + 1);
}

// 올바른 괄호 문자열 판별
bool find_correct(string s) {
    queue<char> q;
    for (int i = 0; i < s.length(); i++)
        q.push(s[i]);

    int left = 0;  // '('
    int right = 0; // ')'

    int length = q.size();
    int flag = 0;

    // '(' 가 ')' 보다 많을 때에만 진행 (그렇지 않으면 올바른 괄호 아님)
    while (length--)
    {
        if (q.front() == '(') {
            left++;
            q.pop();
        }
        else {
            right++;
            q.pop();
        }

        // ')' 의 개수가 많아지는 순간 탈출 (올바른 괄호 아님)
        if (right > left) {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        return true;
    else
        return false;
}

string makeAnswer(string p) {
    string answer = "";

    // p가 null 이면 반환
    if (p == "") return " ";

    // 처음부터 이미 올바른 이면 바로 반환
    if (find_correct(p))
        return p;

    string u = find_u(p);  // 균형잡인 괄호 문자열 찾기
    string v = p.substr(u.length());
    
    // u 가 올바른 인지 아닌지에 따라 분류
    if (find_correct(u)) {
        // v를 다시 u,v로 나눠서 실행
        v = makeAnswer(v);

        string temp = u + v;
        temp.erase(remove(temp.begin(), temp.end(), ' '), temp.end());

        return temp;
    }
    else {
        // u 가 올바른 아니면
        v = makeAnswer(v);
        // 첫 번째와 마지막 문자 제거
        u = u.substr(1, u.length() - 2);
        for (int i = 0; i < u.length(); i++) {
            if (u[i] == '(')
                u[i] = ')';
            else
                u[i] = '(';
        }


        string temp = '(' + v + ')' + u;
        temp.erase(remove(temp.begin(), temp.end(), ' '), temp.end());
        return temp;
    }
}

string solution(string p) {
    string answer = "";
    answer = makeAnswer(p);
    return answer;
}
