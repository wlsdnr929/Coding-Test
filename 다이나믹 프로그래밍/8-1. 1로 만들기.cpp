#include <iostream>
using namespace std;

int arr[30001];
int n;

int main(void)
{
	cin >> n;

	int cnt = 0;

	for (int i = 2; i <= n; i++)
	{
		// 아무런 조건 만족하지 않을 경우
		arr[i] = arr[i - 1] + 1;
		
		if (i % 5 == 0)
			arr[i] = min(arr[i], arr[i / 5] + 1);

		if (i % 3 == 0)
			arr[i] = min(arr[i], arr[i / 3] + 1);

		if (i % 2 == 0)
			arr[i] = min(arr[i], arr[i / 2] + 1);
	}

	cout << arr[n] << '\n';

	return 0;
}
