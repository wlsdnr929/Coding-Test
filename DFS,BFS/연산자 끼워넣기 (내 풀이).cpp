#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> num;
int input_cal[4] ;
vector<int> cal;   //    + - * /      차례대로 개수만큼 
int n;

int calculate(int a, int b, int c)
{
	if (c == '+')
		return a + b;
	else if (c == '-')
		return a - b;
	else if (c == '*')
		return a * b;
	else
		return a / b;
}

void solution()
{
	int max = -1000000000;      //  ---> 범위 항상 조심
	int min = 1000000000;

	do {
		int result = calculate(num[0], num[1], cal[0]);
		for (int i = 1; i < num.size()-1; i++) {
			result = calculate(result, num[i + 1], cal[i]);
		}

		if (result > max) max = result;
		if (result < min) min = result;

	} while (next_permutation(cal.begin(), cal.end()));

	cout << max << '\n' << min;

}

int main(void)
{ 
	int n;
	cin>>n;
	int input;
	for (int i = 0; i < n; i++) {
		cin >> input;
		num.push_back(input);
	}

	for (int i = 0; i < 4; i++) {
		cin >> input_cal[i];
	}
		
	//   + - * /   차례대로 개수만큼 vector<char> cal 에 push_back
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < input_cal[i]; j++) {

			if (i == 0) cal.push_back('+');
			else if (i == 1) cal.push_back('-');
			else if (i == 2) cal.push_back('*');
			else  cal.push_back('/');
		}
	}

	// 순열을 사용하기 위한 정렬
	sort(cal.begin(), cal.end());

	solution();

	/*vector<int> v;
	v.push_back(22);
	v.push_back(11);
	

	do {
		for (int i = 0; i < 2; i++) 
			cout << v[i]<<' ';
	} while (next_permutation(v.begin(), v.end()));*/


	return 0;
}


// ***  핵심내용  ***
//  정렬이 되지 않은 채로 시작하면 결과가 끝까지 나오지 않음
//  ex) 오름차순일 경우, 시작보다 큰 것들만 수행


// ***  주의할 점 ***
//  - 범위 항상 조심
