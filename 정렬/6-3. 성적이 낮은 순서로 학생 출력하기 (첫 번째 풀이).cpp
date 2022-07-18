#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

class Info {
public:
	string name;
	int score;
	Info(string name, int score)
	{
		this->name = name;
		this->score = score;
	}

	bool operator < (Info& other)
	{
		return this->score < other.score;
	}
};


int main(void)
{
	cin >> n;
	vector<Info> v;
	for (int i = 0; i < n; i++)
	{
		string name;
		int score;
		cin >> name >> score;
		v.push_back(Info(name, score));
	}

	// 정렬
	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++)
		cout << v[i].name << ' ';

	return 0;
}
