#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<string> string_num[10001];
vector<string> reverse_string_num[10001];

int countRange(vector<string>& v, string left, string right)
{
    vector<string>::iterator left_idx = lower_bound(v.begin(), v.end(), left);
    vector<string>::iterator right_idx = upper_bound(v.begin(), v.end(), right);

    return right_idx - left_idx;
}

string replace_all(string s, string from, string to)
{
    int pos = 0;
    while ((pos = s.find(from,pos)) != string::npos)
    {
        s.replace(pos, from.size(), to);
        pos += to.size();
    }
    return s;
}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    for (int i = 0; i < words.size(); i++)
    {
        // 모든 단어를 접미사 배열과 접두사 배열에 삽입
        
            // 각 단어의 길이에 해당하는 인덱스에 push_back
            string_num[words[i].size()].push_back(words[i]);
            // 단어 뒤집기 -> 뒤집지 않으면 해당 길이의 모든 문자열을 뒤져야 함,,,
            reverse(words[i].begin(), words[i].end());
            // 각 단어의 길이에 해당하는 인덱스에 push_back
            reverse_string_num[words[i].size()].push_back(words[i]);
    }

    // 이분탐색을 위한 정렬
    for (int i = 0; i < 10001; i++)
    {
        sort(string_num[i].begin(), string_num[i].end());
        sort(reverse_string_num[i].begin(), reverse_string_num[i].end());
    }


    // query 각각의 단어의 개수 count
    for (int i = 0; i < queries.size(); i++)
    {
        string s = queries[i];
        int cnt = 0;

        // 접미사와 접두사 구분
        if (s[0] == '?')
        {
            // s 뒤집기 -> 뒤집지 않고 찾으면 해당길이의 모든 문자열을 비교해야 함
            reverse(s.begin(), s.end());
            // ?를 모두 a인 경우와 z인 경우로 가정하고 모든 알파벳을 범위로 설정
            cnt = countRange(reverse_string_num[s.size()], replace_all(s, "?", "a"), replace_all(s, "?", "z"));
        }
        else
        {
            // ?를 모두 a인 경우와 z인 경우로 가정하고 모든 알파벳을 범위로 설정
            cnt = countRange(string_num[s.size()], replace_all(s, "?", "a"), replace_all(s, "?", "z"));
        }
        answer.push_back(cnt);
    }


    return answer;
}

