#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

class Info {
public:
	string name;
	int kor;
	int eng;
	int math;

	Info(string name, int kor, int eng, int math)
	{
		this->name = name;
		this->kor = kor;
		this->eng = eng;
		this->math = math;
	}

	// 정렬하기
	bool operator < (Info& other)
	{
		if (this->kor == other.kor && this->eng == other.eng && this->math == other.math)
			return this->name < other.name;

		if (this->kor == other.kor && this->eng == other.eng)
			return this->math > other.math;

		if (this->kor == other.kor)
			return this->eng < other.eng;

		return this->kor > other.kor;
	}
};


int main(void)
{

	vector<Info> v;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string name;
		int kor, eng, math;
		cin >> name>>kor >> eng >> math;
		Info temp(name,kor, eng, math);
		v.push_back(temp);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
		cout << v[i].name << '\n';

	return 0;
}
