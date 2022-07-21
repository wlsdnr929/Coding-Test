#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> house;

int n;

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		house.push_back(input);
	}

	sort(house.begin(), house.end());

	int mid = (n-1) / 2;

	cout << house[mid];

	return 0;
}



// 틀린 이유
/*
	처음풀이에서는 모든 경우를 다 계산

	--> 사실, 중간값만 알면 됨
*/
