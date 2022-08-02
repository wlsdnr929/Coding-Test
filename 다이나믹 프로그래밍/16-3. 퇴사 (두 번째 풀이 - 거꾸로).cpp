#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> t;  // time
vector<int> p;  // pay
int dp[16];     // dp

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int time, pay;
		cin >> time >> pay;
		t.push_back(time);
		p.push_back(pay);
	}
	
	int max_value = 0;

	for (int i = n - 1; i >= 0; i--)
	{
		int time = i + t[i];  // 상담시간
		if (time <= n)
		{
			dp[i] = max(p[i] + dp[time], max_value);
			max_value = dp[i];
		}
		else
			dp[i] = max_value;
	}

	cout << max_value << '\n';

	return 0;
}

// 핵심내용
/*
	뒤에서 부터 거꾸로 생각하기
	-> 해당날짜의 돈 + 끝나는 날짜(퇴사일 전이어야 함)  와  maxvalue 를 비교
*/
