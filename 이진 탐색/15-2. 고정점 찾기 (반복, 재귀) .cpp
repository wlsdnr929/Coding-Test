#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> arr;

int find(int start, int end)
{	
	// 종료 조건
	if (start > end)
		return -1;

	int middle = (start + end) / 2;

	if (middle < arr[middle])
		find(start, middle - 1);
	else if (middle > arr[middle])
		find(middle+1, end);
	else
		return middle;
}

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int  input;
		cin >> input;
		arr.push_back(input);
	}

	int start = 0;
	int end = arr.size() - 1;
	/*while (start <= end)
	{
		int middle = (start + end) / 2;

		if (middle < arr[middle])
			end = middle - 1;
		else if (middle > arr[middle])
			start = middle + 1;
		else
		{
			cout << arr[middle];
			return 0;
		}
	}
	cout << -1 << '\n';*/

	// 또는 재귀함수
	cout<<find(0, arr.size()-1);


	return 0;
}



// 핵심내용
/*
	중간값보다 작거나 크면 범위가 반으로 줄어듦
	--> 나머지 반은 보지 않아도 됨
	--> 나머지 반에서 조건에 만족하는 숫자가 있을 수 없음
*/
