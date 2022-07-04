#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, k, x; 
vector<int> graph[300001];   --> 배열 원소 :  vector<int> 이므로, 각각 push_back 가능
// 모든 도시에 대한 최단거리 초기화
vector<int> d(300001, -1);

int main(void)
{
	cin >> n >> m >> k >> x;

	// 모든 도로 정보 입력 받기
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
	}

	d[x] = 0;

	queue<int> q;
	q.push(x);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i];
			// 아직 방문하지 않았다면
			if (d[next] == -1) {
				d[next] = d[now] + 1;
				q.push(next);
			}
		}
	}

	int check = false;
	// 최단 거리가 k인 애들 오름차순으로 출력
	for (int i = 0; i <= n; i++) {
		if (d[i] == k) {
			cout << i << '\n';
			check = true;
		}
	}

	// 없다면 -1 출력
	if (check == 0)
		cout << -1 << '\n';

	return 0;
}
