#include <iostream>
#include <algorithm>

using namespace std;

int n,m;

int shop[1000000];
int want[100000];

void find(int check, int num)
{
	int start = 0;
	int end = num - 1;
	int middle = (start + end) / 2;
	
	while (start <= end)
	{
		// 찾으려는 것이 더 작다면
		if (check < shop[middle])
		{
			end = middle-1;
			middle = (start + end) / 2;
		}
		// 찾으려는 것이 더 크다면
		else if (check > shop[middle])
		{
			start = middle+1;
			middle = (start + end) / 2;
		}
		// 찾았다면 
		else {
			cout << "yes";
			return;
		}
	}
	
	cout << "no";
	return;
}

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> shop[i];

	cin >> m;
	for (int i = 0; i < m; i++) 
		cin >> want[i];
		
	// 정렬해주기
	sort(shop, shop + n);

	for(int i=0;i<m;i++)
		find(want[i], n);

	return 0;
}


// 틀린 이유
/*
	middle 값 위치 선정
*/
