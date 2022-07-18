#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int change;

vector<int> v1;
vector<int> v2;

void swap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

bool compare(int a, int b)
{
	return a > b;
}

int main(void)
{
	cin >> n >> change;
	for (int i = 0; i < n; i++)
	{
		int in;
		cin >> in;
		v1.push_back(in);
	}
	for (int i = 0; i < n; i++)
	{
		int in;
		cin >> in;
		v2.push_back(in);
	}

	// 정렬
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end(),compare);      // 또는 compare 함수 없애고  --> sort(v2.rbegin(), v2.rend());

	for (int i = 0; i < change; i++)
	{
		if (v1[i] < v2[i])
			swap(v1[i], v2[i]);  //   1. swap(&v1[i], &v2[i]);   도 됨
		else                     //   2. swap 함수 따로 만들지않아도
			break;               //      원래 있음 --->  swap(v1[i], v2[i]);  (가능)
	}

	int cnt = 0;
	for (int i = 0; i < n; i++)
		cnt += v1[i];

	cout << cnt;

	return 0;
}
