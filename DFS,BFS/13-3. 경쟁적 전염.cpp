#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// 아래, 위, 오, 왼
int y[4] = { 1,-1,0,0 };
int x[4] = { 0,0,1,-1 };


int n, k;
int S, X, Y;
int t = 0;

int map[201][201];

struct virus {
	int y;
	int x;
	int v;
};

vector<virus> v;
queue<virus> q;

bool compare(virus a, virus b)
{
	return a.v < b.v;
}

bool check(int y, int x)
{
	if (y > n || x > n || y<1 || x<1)
		return false;
	else
		return true;
}

int main(void)
{
	cin >> n>>k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0)
				v.push_back({ i,j,map[i][j] });
		}
	}

	cin >> S >> X >> Y;

	
	// 맨 처음 한번만 정렬 필요
	sort(v.begin(),v.end(),compare);

	// 정렬된 것을 queue에 삽입
	for (int i = 0; i < v.size(); i++)
		q.push(v[i]);

	while (t < S) {

		// 현재 queue의 길이만큼                 *** 주의 ***

		int length = q.size();

		for (int i = 0; i < length; i++) {
			int now_y = q.front().y;
			int now_x = q.front().x;
			q.pop();

			for (int j = 0; j < 4; j++) {
				int next_y = now_y + y[j];
				int next_x = now_x + x[j];

				if (check(next_y, next_x) == false)
					continue;

				// 숫자가 있다는 것은 이전 시간에 이미 존재한다는 것
				if (map[next_y][next_x] == 0)
				{
					map[next_y][next_x] = map[now_y][now_x];
					q.push({ next_y,next_x });
				}
			}
		}
		t++;
	}



	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == X && j == Y)
				printf("%d\n", map[i][j]);
		}
	}


	return 0;
}




// *** 주의할 점 *** -->  map 의 범위 (0,0) 인지 (1,1) 인지
//                   -->  queue의 길이는 계속 변함 ,,, length로 초반에 값을 받아와야 함    
//                   -->  정렬시에는 바이러스 값으로 해야함 ( compare 함수 따로 지정해야 함 )

//  핵심내용
//  --> 바이러스가 퍼진 시간대가 중요하므로 queue를 이용해야함
//  --> 맨 처음 풀이에서는 queue를 사용하지 않았음

//  --> 시간대 별로 고려해야 할 줄 알았음
//		-> 동시간대이면 작은 숫자의 바이러스가 우선이지만,
//         이미 만들어진 바이러스는, 그 숫자가 나의 숫자보다 커도 건들수가 없기 때문,,,
//      -> 하지만 이 고민들을 해결하는 것이 바로 처음에 정렬을 해주는 것 !!
//         정렬을 하게되면 같은 시간대에서는 무조건 작은 숫자부터 퍼지기 때문에
//		   그 다음 바이러스는 이미 있는 숫자보다 무조건 클 것이고, 
//		   이미 있는 바이러스는 건들지 못한다는 조건도 만족
//      -> 정렬은 매순간 할 필요없이 처음에만,,, 처음에 정렬되면 그 다음것들도 자동 정렬
