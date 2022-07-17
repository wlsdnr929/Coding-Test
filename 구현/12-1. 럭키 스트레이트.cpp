#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

bool isLucky(string s)
{
	int len = s.length();
	// 절반 인덱스
	int half = len/2 - 1;

	int sum_front=0, sum_behind=0;
	for (int i = 0; i <= half; i++)
		sum_front += s[i] - '0';

	for (int i = half + 1; i < len; i++)
		sum_behind += s[i] - '0';

	if (sum_front == sum_behind)
		return true;
	else
		return false;
}

int main(void)
{
	string input;
	cin >> input;

	bool result = isLucky(input);
	if (result == true)
		cout << "LUCKY" << endl;
	else
		cout << "READY" << endl;


	return 0;
}
