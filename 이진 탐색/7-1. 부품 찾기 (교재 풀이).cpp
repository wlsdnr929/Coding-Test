#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> shop;
vector<int> check;

void find(int target, int start, int end)
{
	while (start <= end)
	{
		int middle = (start + end) / 2;
		if (target < shop[middle])
			end = middle - 1;
		else if (target > shop[middle])
			start = middle + 1;
		else
		{
			cout << "yes" << '\n';
			return;
		}
	}

	cout << "no" << '\n';
	return;
}

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		shop.push_back(input);
	}

	sort(shop.begin(), shop.end());

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int input;
		cin >> input;
		check.push_back(input);
	}

	for (int i = 0; i < m; i++)
		find(check[i], 0, n);

}
