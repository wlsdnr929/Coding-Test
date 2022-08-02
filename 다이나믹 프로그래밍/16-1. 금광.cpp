#include <iostream>

using namespace std;

int map[21][21];

int dp[21][21];

int t, n, m;

int main(void)
{
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				int input;
				cin >> input;
				map[i][j]= input;
				dp[i][j]= input;
			}
		}


		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				// 1번째 열은 건너뛰기
				if (i == 1)
					continue;
				dp[j][i] = max(max(dp[j - 1][i - 1], dp[j][i - 1]), dp[j + 1][i - 1]) + dp[j][i];
			}
		}

		int result = 0;
		// 마지막 열 중에서 가장 큰 것 찾기
		for (int i = 1; i <= n; i++)
			result = max(result, dp[i][m]);

		cout << result << '\n';


		// 초기화
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				map[i][j] = 0;
				dp[i][j]=0;
			}
		}

	}

	return 0;
}


// 핵심내용
/*
	문제에서 오른쪽 위, 오른쪽, 오른쪽 아래 로 간다고 해서
	오른쪽 방향으로 생각할 것이 아니라
	--> 도착한 입장에서 생각 (왼쪽 위, 왼쪽, 왼쪽 아래에서 온다고 생각)
	--> 셋 중 가장 큰 것을 저장
*/
