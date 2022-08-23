#include <iostream>
#include <vector>
#include <queue>
#define INF 1000000000

using namespace std;

int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
int t, n;
int graph[126][126];
int d[126][126];

bool check(int y, int x)
{
	if (x<1 || x>n || y<1 || y>n)
		return false;
	return true;
}

void dijkstra(int start)
{
	priority_queue<pair<int, pair<int, int>>> pq; // cost, node
	d[start][start] = graph[start][start];
	pq.push({ -graph[start][start],{start,start} });

	while (!pq.empty()) {
		// 가장 최단 거리가 짧은 노드에 대한 정보 꺼내기
		int cost = -pq.top().first;
		int node_y = pq.top().second.first;
		int node_x = pq.top().second.second;

		pq.pop();

		// 현재 노드가 이미 처리된 적이 있는 노드라면 무시
		if (d[node_y][node_x] < cost)
			continue;

		// 해당 노드와 인접한 노드들 확인
		for (int i = 0; i < 4; i++)
		{
			// next_y, next_x
			int ny = node_y + dy[i];
			int nx = node_x + dx[i];

			if (check(ny, nx) == false)
				continue;

			// 해당 노드를 거쳐가는 게 더 짧으면 갱신
			int cur_dis = cost + graph[ny][nx];

			if (cur_dis < d[ny][nx]) {
				d[ny][nx] = cur_dis;
				pq.push({ -cur_dis, { ny,nx } });
			}
		}
	}
	cout << d[n][n] << '\n';
}

int main(void)
{
	cin >> t;

	for (int r = 0; r < t; r++) {
		cin >> n;

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				int cost;
				cin >> cost;
				graph[i][j] = cost;
			}
		}

		for (int i = 0; i < 126; i++)
			fill_n(d[i], 126, INF);

		dijkstra(1);
	}

	return 0;
}
