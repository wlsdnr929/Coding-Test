#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> coin;
int total;

int dp[10001];  // 각 금액마다 최소 가짓수 저장

int main(void)
{
	cin >> n>> m;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		coin.push_back(input);
	}

	for (int i = 0; i < 10001; i++)
		dp[i] = 10001;

	dp[0] = 0;

	for (int i = 0; i < coin.size(); i++)
	{
		for (int j = coin[i]; j <= m; j++)
		{
			if(dp[j-coin[i]]!=10001)
				dp[j] = min(dp[j], dp[j - coin[i]] + 1);
		}
	}

	if (dp[m] != 10001)
		cout << dp[m] << '\n';
	else
		cout << -1 << '\n';

	return 0;
}

// 핵심내용
/*
	화폐의 단위 : k라고 할 때
	coin에 있는 작은 단위화폐부터 시작
	-> 1원부터 m원까지 쭉 가면서
	-> (현재 금액 - k + 1)의 개수와 (현재 금액)의 개수 중 작은 것 저장
*/
