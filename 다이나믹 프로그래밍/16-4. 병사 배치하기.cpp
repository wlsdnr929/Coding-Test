#include <iostream>

using namespace std;

int n;
int arr[2001];

int d[2001];  // LIS 저장하는 배열

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		arr[i] = input;
	}

	for (int i = 0; i < 2001; i++)
		d[i] = 1;

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[i]) {
				d[i] = max(d[i], d[j]+1);
			}
		}
	}

	int big=0;
	for (int i = 0; i < n; i++) {
		big = max(d[i], big);
	}

	cout << n - big;

	return 0;
}


// 핵심내용
/*
	가장 긴 증가하는 부분 수열 (LIS) → Longest Increasing Subsequence
	-> 현재와 바로 다음 것을 비교하는 것이 아닌 (X)
	-> i번 째와  (0부터 i번 바로전까지를 순차적으로 지나치는) j번째를 비교,
	   *** i번 째를 계속 갱신해주는 것 ***
*/
