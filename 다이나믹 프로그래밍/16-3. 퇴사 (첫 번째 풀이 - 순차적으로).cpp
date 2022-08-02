#include <iostream>
#include <vector>

using namespace std;

int n;
vector<pair<int, int>> info;

int dp[16];
int pay[16];
int day[16];

int main(void)
{
	cin >> n;
	
	for (int i = 1; i <=n; i++)
	{
		cin >> day[i] >> pay[i];
		
		// 처음부터 i날짜까지의 최대값을 dp 에 저장
		for (int j = 0; j < i; j++)
		{
			if(i+day[i] <=n+1 && day[j]+ j <=i)   //  "해당날짜의 상담이 퇴사전에 끝나야하고" && "이전의 상담기간이 해당날짜를 넘어서지 않을 경우에만"
			dp[i] = max(dp[i], dp[j] + pay[i]);
		}
	}


	int answer = 0;
	for (int i = 0; i <= n; i++) {
		answer = max(answer, dp[i]);
	}
	cout << answer;

	return 0;
}

// 핵심내용

/* 
	처음부터 해당날짜까지만의 최대값을 저장
	만약, 해당날짜의 상담을 퇴사전까지 끝내지 못하면 dp 에 0을 저장
*/
