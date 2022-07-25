#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, order;

vector<int> rice_cake;

void solution()
{
	int start = 0;
	int end = 1'000'000'000;
	int total = 0;

	while (start <= end)
	{

		int middle = (start + end) / 2;

		if (middle == 16)
		{
			int a=1, b=1;
			//int c = a + b;
		}

		total = 0;

		for (int i = 0; i < rice_cake.size(); i++)
		{
			// 잘리는 것이 있다면 합산 
			if (rice_cake[i] >= middle)
			{
				total += rice_cake[i] - middle;
			}
		}

		//// total 확인용
		//cout << "현재 total: " << total << '\n';


		// 잘린 떡들의 합이 부족하다면
		if (total < order)
			end = middle - 1;

		// 잘린 떡들의 합이 넘친다면
		else if (total > order)
			start = middle + 1;


		else   // total == order
		{
			cout << middle << '\n';
			return;
		}
	}
}


int main(void)
{
	cin >> n >> order;

	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		rice_cake.push_back(input);
	}

	solution();

	return 0;
}
