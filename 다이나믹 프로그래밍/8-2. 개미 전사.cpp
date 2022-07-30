#include <iostream>
#include <vector>

using namespace std;

int dp[101];
int n;
vector<int> food;

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		food.push_back(input);
	}

	dp[0] = food[0];
	dp[1] = max(food[0], food[1]);
	for (int i = 2; i < n; i++)
		dp[i] = max(dp[i - 1], dp[i - 2] + food[i]);

	cout << dp[n - 1] << '\n';

	return 0;
}

// 핵심내용
/*
	현재 (i번째)의 최대값을 구하기 위해서는
	- (i-1번째) 값과 (i-2번째 값 + i번째 값) 중에 더 큰 것을 고르면 된다
	- (i번째 값) 에 (i-2번째 값)을 더하는 이유는  
	  (i번째) 값 한개 보다는, 하나라도 더 더하는 것이 값이 더 커지기 때문
*/
