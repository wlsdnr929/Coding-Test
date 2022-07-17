#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

int solution(string s) {

	int answer = s.size();
	int len = s.length();

	string compressed="", pre;
	string now="";

	// 문자열 단위 증가 ( 1부터 len/2 까지 )
	for (int step = 1; step <= len / 2; step++)
	{
		pre = s.substr(0, step);
		int cnt = 1;
		for (int i = step; i<len; i+=step)  //  처음엔 i <= len - step;  --> 범위틀림
		{
			now = s.substr(i, step);
			// pre 와 그 다음 것이 같다면
			if (pre == now)
				cnt++;
			else
			{
				// 같은 것이 존재한다면
				if (cnt >= 2)
					compressed += to_string(cnt) + pre;
				else
					compressed += pre;

				// pre 갱신
				pre = now;
				// cnt 초기화
				cnt = 1;
			}
		}
		// 남아있는 것들 옮기기
		compressed += (cnt >= 2) ? to_string(cnt) + pre : pre;
		answer= min(answer, (int)compressed.size());

		// compressed 초기화 ( 한 step 넘어가면 초기화 )
		// ----------------------------->  이 부분 안 해줘서 틀림 ,,,
		compressed = "";   //  " " (X) , "" (O)

	}
	return answer;
}
