/*
*  핵심내용: 오름차순 정리 후 최소한의 구성으로 그룹을 만들면
*            그룹개수가 최대가 됨
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n;
	cin >> n;

	// 총 그룹의 개수
	int resutlt_cnt = 0;

	vector<int> v;

	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		v.push_back(input);
	}

	// 오름차순 정렬
	sort(v.begin(), v.end());

	// 현재 그룹에 포함된 구성원 수
	int cur_cnt = 0;

	for (int i = 0; i < n; i++)
	{
		cur_cnt++;
		if (cur_cnt >= v[i])
		{
			resutlt_cnt++;
			cur_cnt = 0;
		}
	}

	cout << "그룹 개수 : " << resutlt_cnt << endl;

	return 0;
}
