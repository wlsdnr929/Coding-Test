#define _CRT_SECURE_NO_WARNGINS
#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;

	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	// 정렬 후 전체에서 안 되는 것 빼기 (중복 제거)
	
	int all = n * (n - 1) / 2;
	int cnt = 0;
	sort(arr, arr + n);
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (arr[i] == arr[j])
				cnt++;
		}
	}

	cout << "답: " << all - cnt << endl;

	return 0;
}
