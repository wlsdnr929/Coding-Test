#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, c;
vector<int> house;

void solution()
{
	int start = 1;                        // gap의 최솟값
	int end = house[n - 1] - house[0];    // gap의 최댓값
	
	int max_gap = 0;

	while (start <= end)
	{
		int gap = (start + end) / 2;
		int wifi = 1;
		int now = house[0];
		
		for (int i = 1; i < n; i++)
		{
			if (house[i] >= now+gap)
			{
				// now 값 갱신
				now = house[i];           
				wifi++;
			}
		}

		// 공유기 c 개 이상이면 gap을 늘리면서 값 저장
		if (wifi >= c)
		{
			max_gap = gap;
			start = gap + 1;
		}

		// c 개 안됐으면 gap 줄이기
		else
			end = gap - 1;
	}

		cout << max_gap << '\n';
}

int main(void)
{
	cin >> n >> c;

	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		house.push_back(input);
	}

	// *** 항상 정렬 !!! ***
	sort(house.begin(), house.end());

	solution();

	return 0;
}

// 핵심내용
/*
	gap 을 이용
	- 최대 gap 에서 절반씩 줄여가며 확인해본다
*/
