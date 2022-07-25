#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, num;
vector<int> arr;

int find_first()
{
	int start = 0;
	int end = arr.size()-1;

	while (start <= end)
	{
		int middle = (start + end) / 2;

		if (num < arr[middle])
			end = middle - 1;
		else if (num > arr[middle])
			start = middle + 1;
		else
		{
			// 첫 번째 인덱스 찾음
			if (middle == 0 || arr[middle - 1] != num)
				return middle;
			
			end = middle - 1;
		}
	}
	return -1;
}

int find_last()
{
	int start = 0;
	int end = arr.size() - 1;

	while (start <= end)
	{
		int middle = (start + end) / 2;

		if (num < arr[middle])
			end = middle - 1;
		else if (num > arr[middle])
			start = middle + 1;
		else
		{
			// 마지막 인덱스 찾음
			if (middle == arr.size()-1 || arr[middle + 1] != num)
				return middle;

			start = middle + 1;
		}
	}
	return -1;
}

int main(void)
{
	cin >> n >> num;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		arr.push_back(input);
	}


	// 일단 정렬하기
	sort(arr.begin(), arr.end());

	int first = find_first();
	int last = find_last();

	if(first == -1 || last == -1)
		cout << -1 << endl;
	else
		cout << last - first + 1 << endl;

	return 0;
}


// 핵심내용
/*

	현재 배열들은 정렬되어있음
	--> 원하는 수들이 다 붙어있음


	찾으려는 숫자의 시작 index와 마지막 index를 구해야 함

*/
