
/* 처음 풀이: 가장 큰 수만 구하려고 했음
* 
*  핵심 내용
*  ==>> 결국 필요한 건 가장 큰 수와 두 번 째로 큰 수
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

using namespace std;
int arr[1001];

int findFirstMax()
{
	int max = arr[0];
	for (int i = 0; i < 1001; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}

int findSecondMax(int fm)
{
	int max = arr[0];

	// first_max의 인덱스 찾기
	int fm_idx;
	int i;
	for ( i = 0; i < 1001; i++)
	{
		if (arr[i] == fm)
			break;
	}
	fm_idx = i;

	for (int i = 0; i < 1001; i++)
	{
		if (arr[i] > max) {
			if (i != fm_idx)
				max = arr[i];
		}
	}

	return max;
}

int main(void)
{
	// n: 숫자갯수, m: 더하는 횟수, k: 더할수 있는 최대 횟수
	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int first_max = findFirstMax();
	int second_max = findSecondMax(first_max);

	int total = 0; // 총 합
	int num = 0;   // 같은 것 더하는 횟수

	while (1)
	{
		if (num == m)
			break;
		for (int i = 0; i < k; i++)
		{
			total += first_max;
			num++;
			if (num == m)
				break;
		}
		// 두 번째로 큰 수 한 번 더해주기
		total += second_max;
		num++;
	}

	cout << "가장 큰 수: " << total << endl;

	return 0;
}
