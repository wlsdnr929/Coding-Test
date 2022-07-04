
/*
*  핵심내용: 더하기 보단 곱하기를 먼저
*  
*  주의: 0뿐만 아니라 1일때도 더하기로 !!! , result가 1보다 작을 때도 더하기로 !!!
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	char s[21];
	cin >> s;

	int total = s[0]-'0';
	for (int i = 1; s[i] != '\0'; i++)
	{
		// 0일 경우 '+'  --> 'x'(곱하기) 할 경우 0 됨
		if (s[i] <= '1' || total<=1)
			total += s[i]-'0';
		else
			total *= s[i]-'0';
	}
	cout << total << endl;
	return 0;

	return 0;
}
