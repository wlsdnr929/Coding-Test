#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMin(string s)
{
	int one_cnt = 0;
	int zero_cnt = 0;
	
	int i = 0;
	while (s[i])
	{
		if (s[i] == '1')
			one_cnt++;
		else
			zero_cnt++;

		i++;
	}

	if (one_cnt < zero_cnt)
		return 1;
	else
		return 0;
}

int main(void)
{
	string s;
	cin >> s;

	int reverse_cnt = 0;

	int min_num = findMin(s);
	int change;
	if (min_num == 1)
		change = 0;
	else
		change = 1;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == min_num+'0')
		{
			reverse_cnt++;
			while (1)
			{
				s[i] = change;
				if (s[i + 1] != min_num)
					break;
				i++;
			}
		}
	}

	cout << "총 "<< reverse_cnt << " 번" << endl;

	return 0;
}

/*
*  처음 풀이: 굳이 더 적은 수를 찾고 그 수에 대해서만 할 필요 없음
*       --> 0,1 을 각각 세고 더 적은 것을 구하면 됨
*
*  핵심내용: 더 적은 수를 바꾸기 ( 훨씬 짧은 코드로 구현 가능 )
*  
*  주의: 문자와 숫자 비교할 때 --> 숫자에 48('0')을 더해서 문자로 만들기
*
* --------> 교재 코드 참고 ( 근데 왜 s.length() -1 인지, 왜 s[0]을 고려하는 지 )
*
*/
