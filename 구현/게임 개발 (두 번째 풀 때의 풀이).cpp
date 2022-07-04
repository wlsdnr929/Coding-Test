#include <iostream>

using namespace std;

int dy[4] = { 1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

int map[51][51];

int main(void)
{
	int n, m;
	cin >> n >> m;
	int now_y, now_x, direction;
	cin >> now_y >> now_x>>direction;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> map[i][j];

	int visit_cnt = 1;  // 방문하면 map -> 2
	int rotation_cnt = 0;
	int next_y, next_x;

	// 교재는 시작을 (0,0)에서부터 했음
	now_y++;
	now_x++;

	map[now_y][now_x] = 2;

	while (1)
	{
		// 방향 정하기
		if (direction == 0)
			direction = 3;
		else
			direction--;

		next_y = now_y + dy[direction];
		next_x = now_x + dx[direction];

		// 갈 수 없다면 (바다 또는 이미 간 곳)
		if (map[next_y][next_x]>0)
		{
			// 이미 4번 돌았다면
			if (rotation_cnt == 4)
			{
				next_y = now_y - dy[direction];
				next_x = now_x - dx[direction];
				// 뒤로 간 것이 바다라면
				if (map[next_y][next_x]==1)
					break;
				else
				{
					now_y = next_y;
					now_x = now_x;
				}
			}
			else
			rotation_cnt++;
		}
		// 갈 수 있다면
		else
		{
			now_y = next_y;
			now_x = next_x;
			map[now_y][now_x] = 2;
			visit_cnt++;
			rotation_cnt = 0;
		}
	}

	cout << visit_cnt;
	 

	return 0;
}
