
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int compare(const void* a,const void* b)
{
	if (*(int*)a > *(int*)b)
		return 1;
	else if (*(int*)a < *(int*)b)
		return -1;
	else
		return 0;
}

int main(void)
{
	// n: 열, m: 행
	int n, m;
	scanf("%d %d", &m, &n);

	int** ptr = (int**)malloc(sizeof(int*) * m);
	for (int i = 0; i < m; i++)
	{
		ptr[i] = (int*)malloc(sizeof(int) * n);
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			scanf("%d", &ptr[i][j]);
	}

	// 각 행을 정렬
	for (int i = 0; i < m; i++)
	{
		qsort(ptr[i],n,sizeof(int),compare);
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
