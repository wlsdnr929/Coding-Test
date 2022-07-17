#define _CRT_SECURE_NO_WARNGINS
#include <iostream>
#include <algorithm>

using namespace std;

int arr[11];

int main(void)
{
	int n, m;
	cin >> n >> m;

	int input;

	// 해당 무게를 인덱스로 하는 배열(해당 무게 공 있으면 +	1)
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		arr[input] += 1;
	}

	// 자기 무게 빼고 다른 무게의 공들과의 조합(자신 보다 앞은 중복이니까 제외)
	int answer = 0;
	for (int i = 1; i <=m; i++)
	{
		n -= arr[i];     ---> n 값은 계속 줄어듦
		answer += n * arr[i];
	}
	
	cout << "답: " << answer << endl;

	return 0;
}
