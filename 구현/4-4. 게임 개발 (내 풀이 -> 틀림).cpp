
// 다시 돌아가는 부분 틀림

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;


int visited[51][51];
int map[51][51];

// 북 동 남 서
int d_n[4] = { -1,0,1,0 };
int d_w[4] = { 0,1,0,-1 };

// 바라보는 방향
int direction;

void turn_left()
{
	direction--;
	if (direction == -1)
		direction = 3;
}

int main(void)
{
	int n, m;
	cin >> n >> m;

	// 현재 북, 서로부터 떨어진 위치
	int from_north, from_west;
	
	cin >> from_north >> from_west >> direction;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];

	// 변화되는 위치 값
	int cur_north, cur_west;

	int left_count=0;
	int visit_cnt = 0;

	// 처음 위치
	visited[from_north][from_west] = 1;
	visit_cnt++;
	while (1)
	{
		// 왼쪽으로 돌기
		turn_left();
		left_count++;

		// 다음 칸
		cur_north = from_north + d_n[direction];
		cur_west = from_west + d_w[direction];

		// 가본 곳이 아니고 육지이면
		if (visited[cur_north][cur_west] == 0 && map[cur_north][cur_west] == 0)
		{
			visited[cur_north][cur_west] = 1;
			visit_cnt++;
			left_count = 0;

			// 한 칸 이동
			from_north = cur_north;
			from_west = cur_west;
		}
		// 이미 방문 했거나 바다면
		else
		{
			// 네 방향 모두 갈 수 없다면
			if (left_count == 4)
			{
				// 뒤로 갈 수 있다면
				if (map[from_north][from_west] == 0)
				{
					cur_north = from_north;
					cur_west = from_west;
					left_count = 0;
				}
				// 아무곳도 갈 수 없으면
				break;
			}
		}
	}

	cout << visit_cnt << endl;
}
