#include <iostream>
#define INF 1000000000 // 무한을 의미하는 값으로 10억을 설정

using namespace std;

// 노드의 개수(N), 간선의 개수(M)
int n, m;
// 2차원 배열(그래프 표현)를 만들기
int graph[101][101];

int main(void)
{
	cin >> n >> m;

	// 최단 거리 테이블을 모두 무한으로 초기화
	for (int i = 0; i < 101; i++)
		fill_n(graph[i], 101, INF);

	// 각 간선에 대한 정보를 입력 받아, 그 값으로 초기화
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		// 가장 짧은 간선 정보만 저장
		graph[a][b] = min(graph[a][b], c);
	}

	// 자기 자신에서 자기 자신으로 가는 비용은 0으로 초기화
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)
				graph[i][j] = 0;
		}
	}

	// 점화식에 따라 플로이드 워셜 알고리즘을 수행
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}

	// 수행된 결과를 출력
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			// 도달할 수 없는 경우, 0을 출력
			if (graph[i][j] == INF)
				cout << 0<<' ';
			// 도달할 수 있는 경우 거리를 출력
			else
				cout << graph[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
