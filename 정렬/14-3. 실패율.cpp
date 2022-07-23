#include <string>
#include <vector>
#include <algorithm>
#include<iostream>

using namespace std;

bool compare(pair<int, double>a, pair<int, double> b){

    if (a.second == b.second)
        return a.first < b.first;

    return a.second > b.second;
}

vector<int> solution(int n, vector<int> stages) {
    vector<int> answer;

    vector<pair<int, double>> v;    // stage, fail
    int length = stages.size();

    for (int i = 1; i <= n; i++)
    {
        
        int now =  count(stages.begin(), stages.end(), i);
    
        double fail = 0;
        
        if (length >= 1)
        {
            fail = (double)now / (double)length;
        }

        // 실패율 push_back
        v.push_back(make_pair(i, fail));
        // length 변화
        length -= now;
    }
    
    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < v.size(); i++)
        answer.push_back(v[i].first);

    for (int i = 0; i < v.size(); i++)
        cout << v[i].first << '\n';

    return answer;
}
int main(void)
{
    solution(4, { 4,4,4,4});
    return 0;
}




// 핵심내용 
/*
    length 의 값 변화
    --> 현재 스테이지에 머물러있는 것만 보면 됨
*/

// 주의사항
/*
    length가 0이 될 경우
*/
