#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	// n: 열, m: 행
	int n, m;
	cin >> m >> n;

  // 동적할당
	int** ptr = new int* [m];

	for (int i = 0; i < m; i++)
	{
		ptr[i] = new int[n];
	}

	// 각 행 입력받기
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> ptr[i][j];

	// 각 행을 정렬
	for (int i = 0; i < m; i++)
	{
		sort(&ptr[i][0], &ptr[i][n-1]);
	}

	int max = ptr[0][0];

	// 각 행의 가장 작은 것들 중 큰 것 찾기
	for (int i = 0; i < m; i++)
	{
		if (ptr[i][0] > max)
			max = ptr[i][0];
	}

	printf("%d\n", max);

	return 0;
}
