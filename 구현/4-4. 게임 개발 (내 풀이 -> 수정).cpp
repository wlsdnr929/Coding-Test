#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int visited[51][51];
int map[51][51];

int d_n[4] = { -1,0,1,0 };
int d_w[4] = { 0,1,0,-1 };

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

	int cur_north, cur_west;
	cin >> cur_north >> cur_west >> direction;

	int visit_cnt = 0;

	visited[cur_north][cur_west] = 1;
	visit_cnt++;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];

	int left_cnt=0;

	while (1)
	{
		turn_left();
		int next_north = cur_north + d_n[direction];
		int next_west = cur_west + d_w[direction];

		if (visited[next_north][next_west] == 0 && map[next_north][next_west] == 0)
		{
			cur_north = next_north;
			cur_west = next_west;

			visited[cur_north][cur_west] = 1;
			visit_cnt++;

			left_cnt = 0;
		}
		else
		{
			left_cnt++;
			if (left_cnt == 4)
			{
				 next_north = cur_north - d_n[direction];
				 next_west = cur_west - d_w[direction];
				if (map[next_north][next_west] == 1)
					break;
				else
				{
					cur_north = next_north;
					cur_west = next_west;
					left_cnt = 0;
				}
			}

		}
	}

	cout << visit_cnt << endl;

	return 0;
}
