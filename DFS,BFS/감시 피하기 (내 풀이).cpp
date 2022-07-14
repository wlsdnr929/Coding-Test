#include <iostream>

using namespace std;

int n;
char map[7][7];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
bool success;

bool check(int y, int x) {
	if (y<1 || y>n || x<1 || x>n)
		return false;
	return true;
}

bool checkTeacher()
{
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] == 'T') {
					// 4가지 방향에 대해 ( 위, 아래, 왼, 오 )
					for (int k = 0; k < 4; k++) {
						int next_y = i + dy[k];
						int next_x = j + dx[k];

						while (1) {
							// 범위 넘어가면 제외
							if (check(next_y, next_x) == false)
								break;
							// 장애물 나와도 제외
							if (map[next_y][next_x] == 'O')
								break;
							// 'S'나오면 학생 잡힘
							if (map[next_y][next_x] == 'S') {
								// 잡히면 false 반환
								return false;
							}

							if (k == 0) {
								next_y--;
							}
							else if (k == 1) {
								next_y++;
							}
							else if (k == 2) {
								next_x--;
							}
							else {
								next_x++;
							}
						}
				}
			}
		}
	}
	// 여기까지 왔다는 것은 피하기 성공
	return true;
}

void solution(int wall) {

	// 장애물 3개 설치완료하면
	if (wall == 3) {
		// teacher 감시 시작
		if (checkTeacher()) {
			success = true;
			}
	}
	else {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (map[i][j] == 'X')
				{
					map[i][j] = 'O';
					solution(++wall);
					// 다시 장애물 해제
					map[i][j] = 'X';
					wall--;                        // ---> 이 부분 중요
				}
			}
		}
	}
}

int main(void)
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}

	solution(0);

	if (success)cout << "YES";
	else cout << "NO";
	return 0;
}


// 벽 설치하는 과정  --> 13-2 연구소 문제 참고
// 틀린 부분 : 벽 설치하고 다시 돌아와서 wall 값 하나 빼주기
