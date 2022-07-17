/*
*  핵심내용: 가진돈 중 큰 것부터 사용해서 0원 만들기
*  내가 틀린 이유: money와 i 를 바꿔씀( 60번째 줄 )..
*/

#define _CRT_SECURE_NO_WARINGS
#include <iostream>
#include <algorithm>

using namespace std;

bool des(int a, int b)
{
	return a > b;
}

//int compare(const void* a, const void* b)
//{
//	if (*(int*)a > *(int*)b)
//		return -1;
//	else if (*(int*)a < *(int*)b)
//		return 1;
//	else return 0;
//}

int main(void)
{
	int n;
	cin >> n;

	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];                //  cin 사용 시 -> &arr[i] (x)


	//// sort 사용 시 -> 꼭 '&' 쓰기 !!!    또는 arr , arr+n-1
	//// 내림 차순 -> greater<int>() 안 됨 !!  , des 함수 사용
	sort(arr, arr+n,des);       
	//qsort(arr, n, 4, compare);
	

	// 1원 부터 시작해서 1,000,000 까지 돌면서
	// 조합할 수 없는 숫자를 찾음

	int answer = 0;

	for (int i = 1; i <= 1'000'000; i++)
	{
		int money = i;
		for (int j = 0; j < n; j++)
		{
			// money보다 배열 값이 작으면
			if (arr[j] <= money)
			{
				money -= arr[j];
				if (money == 0)
					break;
			}
		}

		// 만약 money가 0 이 아니면 
		// 그 숫자가 정답
		if (money != 0)
		{
			answer = i;
			break;
		}
	}

	cout << "답: " << answer << endl;

	return 0;
}
