#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int n, m, x, y, direction;
// 방문한 위치를 저장하기 위한 맵을 생성하여 0으로 초기화
int d[50][50];
// 전체 맵 정보
int arr[50][50];

// 북, 동, 남, 서 방향 정의
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

// 왼쪽으로 회전
void turn_left() {
    direction -= 1;
    if (direction == -1) direction = 3;
}

int main(void) {
    // N, M을 공백을 기준으로 구분하여 입력받기
    cin >> n >> m;
    // 현재 캐릭터의 X 좌표, Y 좌표, 방향을 입력받기
    cin >> x >> y >> direction;
    d[x][y] = 1; // 현재 좌표 방문 처리

    // 전체 맵 정보를 입력 받기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            arr[i][j] = x;
        }
    }

    // 시뮬레이션 시작
    int cnt = 1;
    int turn_time = 0;
    while (true) {
        // 왼쪽으로 회전
        turn_left();
        int nx = x + dx[direction];
        int ny = y + dy[direction];
        // 회전한 이후 정면에 가보지 않은 칸이 존재하는 경우 이동
        if (d[nx][ny] == 0 && arr[nx][ny] == 0) {
            d[nx][ny] = 1;
            x = nx;
            y = ny;
            cnt += 1;
            turn_time = 0;
            continue;
        }
        // 회전한 이후 정면에 가보지 않은 칸이 없거나 바다인 경우
        else turn_time += 1;
        // 네 방향 모두 갈 수 없는 경우
        if (turn_time == 4) {
            nx = x - dx[direction];
            ny = y - dy[direction];
            // 뒤로 갈 수 있다면 이동하기
            if (arr[nx][ny] == 0) {
                x = nx;
                y = ny;
            }
            // 뒤가 바다로 막혀있는 경우
            else break;
            turn_time = 0;
        }
    }

    cout << cnt << '\n';
}
