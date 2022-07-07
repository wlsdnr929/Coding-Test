#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
// 초기맵
int map[9][9];
// 벽 설치의 일시적인 맵
int temp[9][9];

int answer;

int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };

int count_safe() {
	int cnt = 0;

	for (int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if (temp[i][j] == 0)
				cnt++;
		}
	}
	return cnt;
}

// DFS 로 바이러스 전파
void virus(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny > 0 && ny <= n && nx > 0 && nx <= m) {
			// 해당 위치가 0일 때만 전파     ----------------------> 여기서 틀림 ( 이 조건 없으면 무한루프 )
			if (temp[ny][nx] == 0) {    
				temp[ny][nx] = 2;
				virus(ny, nx);
			}
		}
	}
}

void dfs(int wall) {
	// 벽 3개 설치완료되었다면
	if (wall == 3) {

		// 현재 map을 temp로 옮겨놓고
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				temp[i][j] = map[i][j];
			}
		}
		// 각각의 바이러스에서 전파시작
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (temp[i][j]== 2) {
					virus(i, j);
				}
			}
		}
		int now_safe = count_safe();
		answer = max(answer,now_safe);
		return;   //  -----------------------------> 이거 안 해줘서 틀림
	}

	// 아직 3개의 벽이 설치되지 않았다면
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 1;
				dfs(++wall);   //   -----> 여기서 틀림 : 처음엔 dfs(wall +1) 이라고 함
				map[i][j] = 0;   //						  --> 이렇게 되면 wall 자체값이 증가되지 않은 상태로 dfs로 넘어감
				wall--;
			}
		}
	}
}

int main(void)
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}

	// DFS로 벽 3개 조합구하고, 각각마다 바이러스 계산
	dfs(0);
	// 답 출력
	cout << answer;

	return 0;
}
