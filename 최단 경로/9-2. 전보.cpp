#include <iostream>
#include <vector>
#include <queue>

#define INF 1000000000

using namespace std;

int n, m, c;
vector<pair<int, int>> graph[30001];
int d[30001];

void dijkstra(int start)
{
	priority_queue<pair<int, int>> pq;
	d[start] = 0;
	pq.push({ 0,start });

	while (!pq.empty()) {
		// 가장 최단 거리가 짧은 노드에 대한 정보 꺼내기
		int dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		// 현재 노드가 이미 처리된 적이 있는 노드라면 무시  !!!!!!!,,,
		if (d[now] < dist)
			continue;

		// 현재 노드와 연결된 다른 인접한 노드들을 확인     !!!!!!!,,,,
		for (int i = 0; i < graph[now].size(); i++) {
			// start에서 i번째 노드를 가는 것보다
			// 중간에 now를 거쳐가는게 빠르면 갱신
			int distance = dist + graph[now][i].second;

			if (distance< d[graph[now][i].first])
			{
				d[graph[now][i].first] = distance;
				pq.push(make_pair(-distance, graph[now][i].first));
			}
		}
	}
}

int main(void)
{
	cin >> n >> m >> c;

	// 최단 거리 테이블을 모두 무한으로 초기화
	fill_n(d, 30001, INF);

	// 모든 간선 정보를 입력받기
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		// a번 노드에서 b번 노드로 가는 비용이 c라는 의미
		graph[a].push_back({ b,c });
	}

	// 다익스트라 알고리즘을 수행 (dijkstra)
	dijkstra(c);
	
	int num = 0;

	// 도달할 수 있는 노드 중에서, 가장 멀리 있는 노드와의 최단 거리
	int max_time = 0;
	for (int i = 1; i <= n; i++) {
		if (d[i] != INF) {
			num++;
			max_time = max(max_time, d[i]);
		}
	}

	// 시작 노드는 제외해야 하므로 count - 1을 출력
	cout << num-1 << ' ' << max_time << '\n';

	return 0;
}

// 틀린부분
/*
	 - 이미 처리된 노드는 아래의 코드를 실행하지 않고
	   continue를 이용해 넘어감

	 - pq에 push할 노드를 찾으려면
	   현재 노드와 연결된 노드들을 일단 확인해야 함
*/
