/* 
* 핵심 내용: 반복되는 수열에 대해 파악
* ==> 반복되는 수열은 (가장 큰 수 * k + 두 번째 큰 수), 가장 큰 수가 k번보다 많이 나올 수 없으므로
*     m에 대해서 (k+1) 이 몇 번 반복되는 지, 나누어떨어지지 않는 경우도 고려
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v;

int main(void)
{
	// n: 숫자갯수, m: 더하는 횟수, k: 더할수 있는 최대 횟수
	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++)
	{
		int n;
		cin >> n;
		v.push_back(n);
	}

	// 정렬 후 첫 번째와 두 번째로 큰 수 찾기
	sort(v.begin(), v.end());
	int first = v[n - 1];
	int second = v[n - 2];

	// 가장 큰 수가 더해지는 횟수
	int first_num = m / (k + 1) * 3 + m % (k + 1);
	// 두 번째 수가 더해지는 횟수
	int second_num = m - first_num;

	// 총 합
	int result = first * first_num + second * second_num;
	cout << "총 합: " << result << endl;

	return 0;
}
