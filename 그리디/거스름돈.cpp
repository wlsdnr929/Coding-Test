#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

using namespace std;
int coin[4] = { 500,100,50,10 };

int main(void)
{
	int n = 0;
	int total = 1260;

	for (int i = 0; i < 4; i++)
	{
		n += total / coin[i];
		total %= coin[i];
	}

	cout << "총 " << n << " 개" << endl;
	return 0;
}
