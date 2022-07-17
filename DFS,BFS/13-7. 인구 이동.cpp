#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, l, r;
int map[51][51];
int united_map[51][51];

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

bool check(int y, int x, int idx)
{
	if (y<1 || y>n || x<1 || x>n)
		return false;

	// 나와 같은 연합이거나, 이미 다른 연합에 들어가있으면
	if (united_map[y][x]!= -1)
		return false;

	return true;
}

void unitedCheck(int y, int x, int idx)
{
	queue<pair<int, int>> sides;   //  bfs를 진행하기 위한 queue
	vector<pair<int, int>> united; //  연합 국가를 저장할 vector

	united_map[y][x] = idx;
	sides.push({ y,x });
	united.push_back({ y,x });

	int total = 0;
	total += map[y][x];

	while (sides.empty() == false)
	{
		int y = sides.front().first;
		int x = sides.front().second;
		sides.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (check(ny, nx, idx) == true)
			{
				// 옆 나라와의 차이가  l ~ r 사이가 아니라면 continue
				int dif = abs(map[y][x] - map[ny][nx]);
				if (dif <l || dif >r)
					continue;

				sides.push(make_pair(ny, nx));
				united.push_back({ ny,nx });
				united_map[ny][nx] = idx;
				total += map[ny][nx];
			}
		}
	}

	// 연합 결성 완료
	int avg = total / united.size();

	// map 변경                              ---->  이 부분때문에 처음에 시간초과 뜸
	for (int i = 0; i < united.size(); i++)
	{
		int y = united[i].first;
		int x = united[i].second;
		map[y][x] = avg;
	}
}

int main(void)
{
	cin >> n >> l >> r;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}

	int total_cnt = 0;

	while (1)
	{

		// united_map 초기화
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				united_map[i][j] = -1;    // 초기값 -1로

		// 마지막 나라까지 모두 연합을 판별했는지 확인하기 위해
		int index = 0;

		// 모든 나라에 대해 주변 연합 판별
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				// 아직 연합이 이루어지지 않았다면
				if (united_map[i][j] == -1)
				{
					unitedCheck(i, j, index);
					index++;
				}
			}
		}

		// index = n*n   --> 모든 나라가 연합이 없어서 
		//                   index 가 최대치(중복되는 연합 없음)로 증가한 상태
		if (index == n * n)
			break;
		total_cnt++;
	}

	cout << total_cnt;

	return 0;
}


// *** 주의할 점 ***
// : (1,1)부터 시작한다고 가정하면 안 됨
//   ->각각의 모든 나라에서 시작하는 것을 고려해야 함
// : 여러개의 연합이 생길수도 있음

// 처음풀 때 시간초과 뜸
// --> for(int i=1; i<=n; i++){
//		  for(int j=1; j<=n; j++){
//              if(united[i][j] == idx) map[i][j] =idx;   로 해서 시간초과 뜸,,,
