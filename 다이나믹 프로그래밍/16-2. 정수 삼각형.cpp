#include <iostream>

using namespace std;

int dp[500][500];

int n;

int main(void)
{
	// dp 초기화
	for (int i = 0; i < 500; i++)
	{
		for (int j = 0; j < 500; j++)
		{
			dp[i][j] = -1;
		}
	}

	// 값 대입
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			int input;
			cin >> input;
			dp[i][j] = input;
		}
	}

	// 왼쪽 위 : leftup, 바로 위 : nowup
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			int leftup = dp[i - 1][j - 1];
			int nowup = dp[i - 1][j];
			dp[i][j] = max(leftup, nowup) + dp[i][j];
		}
	}

	int result = 0;
	for (int i = 0; i < n; i++)
		result = max(result, dp[n - 1][i]);

	cout << result << '\n';

	return 0;
}

// 핵심내용
/*
	위, 아래 중 아래쪽을 기준으로 생각해보면
	-> 왼쪽 위, 바로 위 에서 오는 것이라 생각할 수 있음

	*** '바로 위'인 이유 ***
	: 사이사이에 엇갈려있기 때문에

	--> 예시를 아래와 같이 생각
	7
	3 8
	8 1 0
	2 7 4 4
	4 5 2 6 5

*/
