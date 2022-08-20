#include <iostream>
#include <vector>

#define INF 1000000000

using namespace std;

int n, m, x, k;

int graph[101][101];

int main(void)
{
	cin >> n >> m;

	// 최단 거리 테이블을 모두 무한으로 초기화
	for (int i = 0; i < 101; i++)
		fill_n(graph[i], 101, INF);

	// 자기 자신에서 자기 자신으로 가는 비용은 0으로 초기화
	for (int i = 1; i < 101; i++) {
		for (int j = 1; j < 101; j++) {
			if (i == j)
				graph[i][j] = 0;
		}
	}

	// 각 간선에 대한 정보를 입력 받아, 그 값으로 초기화
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a>> b;
		graph[a][b] = 1;
		graph[b][a] = 1;     // a,b 서로에게 해줘야 함
	}

	// 점화식에 따라 플로이드 워셜 알고리즘을 수행
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}

	// 거쳐 갈 노드 X와 최종 목적지 노드 K를 입력받기
	cin >> x >> k;

	// 수행된 결과를 출력
	int result = graph[1][k] + graph[k][x];

	// 도달할 수 없는 경우, -1을 출력
	if (result >=INF)
		cout << -1 << '\n';
	// 도달할 수 있다면, 최단 거리를 출력
	else
		cout << result<<'\n';

	return 0;
}
