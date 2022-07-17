
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int map[101][101];

int n;
int change_cnt;  // 방향 전환 횟수
vector<pair<int, char>> info; // 시간와 방향 정보

// 동 남 서 북
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

int turn(int direction, char c)
{
	if (c == 'L')
		direction = (direction == 0) ? 3 : --direction;
	else
		direction = (direction + 1) % 4;

	return direction;
}

int simulate()
{
	// 뱀의 위치는 queue에 저장
	queue<pair<int, int>> q;
	q.push({ 1,1 });
	// 현재 뱀이 있으면 2로 표시
	map[1][1] = 2;

	int direction = 0;  // 현재 동쪽
	int cur_y = 1, cur_x = 1;
	int next_y, next_x;
	int index = 0;      // 이번이 몇 번째의 방향 전환인지
	int time = 0;

	while (1)
	{
		next_y = cur_y + dy[direction];
		next_x = cur_x + dx[direction];

		// 벽에 부딪히거나 몸통에 부딪히면 중지
		if (next_y<1 || next_y>n || next_x <1 || next_x>n || map[next_y][next_x] == 2)
		{
			time++;
			break;
		}

		// 다음 갈 위치에 사과가 있다면
		if (map[next_y][next_x] == 1)
		{
			map[next_y][next_x] = 2;
			// 꼬리는 가만히 있고 머리만 이동
			q.push({ next_y,next_x });
		}
		else
		{
			map[next_y][next_x] = 2;
			// 사과 없다면
			// 머리 이동 후 꼬리 제거
			q.push({ next_y,next_x });
			// 꼬리가 있던 칸 0으로 만들기
			int y = q.front().first;
			int x = q.front().second;
			map[y][x] = 0;
			q.pop();
		}

		cur_y = next_y;
		cur_x = next_x;
		time++;

		// 현재 시간이 앞쪽 info에 담긴 시간과 같다면
		if (time == info[index].first)
		{
			direction = turn(direction, info[index].second);
			index++;
		}
	}
	return time;
}

int main(void)
{
	int apple;
	cin >> n >> apple;

	int row, col;
	for (int i = 0; i < apple; i++)
	{
		cin >> row >> col;
		// 사과 1로 표시
		map[row][col] = 1;
	}

	cin >> change_cnt;
	int t;
	char c;
	for (int i = 0; i < change_cnt; i++)
	{
		cin >> t >> c;
		info.push_back({ t,c });
	}

	cout << simulate() << endl;
}


// 유의사항 : turn 함수에서 'L'일 때 '--'수식 주의 ( 앞인지 뒤인지 ),
         
              index++ 들어가는 위치 주의
     
