#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <queue>
#include <deque>


using namespace std;

int n, m;
int map[1000][1000];
queue<pair<int, int>> q;

int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };

// 범위 체크
bool check(int y, int x) {
    if (y < 0 || y >= n || x < 0 || x >= m || map[y][x]==0) {
        return false;
    }
    return true;
}

int bfs(int y, int x) {
    queue<pair<int, int>> q;
    // 일단 push
    q.push(make_pair(y, x));

   // queue가 빌 때까지
    while (q.empty() == false) {
        
        // 일단 저장해두고 pop
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        // 4가지 방향 check 후 push
        for (int i = 0; i < 4; i++) {
            int n_y = y+dy[i];
            int n_x = x+dx[i];

            if (check(n_y, n_x)) {
                // 처음 방문할 경우에만
                if (map[n_y][n_x] == 1) {
                    q.push({ n_y,n_x });
                    map[n_y][n_x] += map[y][x];
                }
            }
        }
    }
    return map[n - 1][m - 1];
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    cout << bfs(0,0);
    return 0;
}



// 틀린이유: 처음 방문할 경우에만 이전의 거리를 더해줘야 함
