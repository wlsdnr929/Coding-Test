#include<iostream>
#include <queue>

using namespace std;

int n;
priority_queue<int> q;

int main(void)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        q.push(-input);
    }

    int sum = 0;
    int total = 0;
    while (q.size()>1)
    {
        sum = 0;
        int first = -q.top();
        q.pop();
        int second = -q.top();
        q.pop();

        sum = first + second;
        total += sum;
        q.push(-sum);
    }

    cout << total << '\n';

    return 0;
}


// 틀린이유
/*
    그냥 정렬해서 계산만 함

    --> 매 순간 가장 작은 둘을 묶어야 함

    해결방법 : 우선순위 큐를 이용하자  ( '-'를 이용하면 작은 게 우선순위)
    --> 가장 위에 있는 것을 두 번 빼면 매 순간 가장 작은 것
    --> 그 둘의 합을 다시 힙에 삽입 (자동으로 정렬 됨)




   while 문의 탈출조건 주의!!!


*/
