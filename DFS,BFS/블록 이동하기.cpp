#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Robot {
public:
    int y1;
    int x1;
    int y2;
    int x2;
    Robot(int y1, int x1, int y2, int x2) {
        this->y1 = y1;
        this->x1 = x1;
        this->y2 = y2;
        this->x2 = x2;
    }
};

vector<Robot> getNext(Robot now, vector<vector<int>> board)
{
    vector<Robot> next;
    // 상 하 좌 우 
    int dy[4] = { -1,1,0,0 };
    int dx[4] = { 0,0,-1,1 };
    for (int i = 0; i < 4; i++)
    {
        int n1y = now.y1 + dy[i];
        int n1x = now.x1 + dx[i];
        int n2y = now.y2 + dy[i];
        int n2x = now.x2 + dx[i];
        Robot temp(n1y, n1x, n2y, n2x);

        // 조건 만족하면 push
        if (board[n1y][n1x]==0 && board[n2y][n2x] == 0)
            next.push_back(temp);
    }

    // 회전하는 경우
    
    // 가로 (위 또는 아래 각각 2개의 좌표들이 모두 0)
    int hor[] = { -1,1 };
    if (now.y1 == now.y2) {
        for (int i = 0; i < 2; i++)
        {
            if ((board[now.y1 + hor[i]][now.x1]==0) && (board[now.y2 + hor[i]][now.x2]==0))
            {
                //  next.push_back(Robot(now.y1 + hor[i], now.x1, now.y2 + hor[i], now.x2));      --->   처음에 이렇게만 써서 틀림
                next.push_back(Robot(now.y1, now.x1, now.y1 + hor[i], now.x1));
                next.push_back(Robot(now.y2, now.x2, now.y2 + hor[i], now.x2));
            }
        }
    }

    // 세로 (왼 또는 오른쪽 각각 2개의 좌표들이 모두 0)
    int ver[] = { -1,1 };
    if (now.x1 == now.x2) {
        for (int i = 0; i < 2; i++)
        {
            if ((board[now.y1][now.x1 + ver[i]]==0) && (board[now.y2][now.x2 + ver[i]]==0))
            {
                //  next.push_back(Robot(now.y1, now.x1 + ver[i], now.y2, now.x2 + ver[i]));      --->  처음에 이렇게만 써서 틀림
                next.push_back(Robot(now.y1, now.x1, now.y1, now.x1 + ver[i]));
                next.push_back(Robot(now.y2, now.x2, now.y2, now.x2 + ver[i]));
            }
        }
    }
    return next;
}

int solution(vector<vector<int>> board) {

    int answer=0;
    int n = board.size();        // 한 변의 길이
    vector<Robot> visited;       // 방문한 것들 저장
    queue<pair<Robot, int>> q;   // bfs를 위한 queue (Robot 과 시간 저장)

    // board 를 1로 둘러싸고 있는 큰 board 만들기
    //  --> 벽이 있다고 가정
    vector<vector<int>> new_board(n + 2, vector<int>(n + 2, 1));  //  모두 1로 채움

    for (int i = 0; i < n ; i++) {
        for (int j = 0; j < n ; j++) {
            new_board[i+1][j+1] = board[i][j];                        //  원래 board 복사
        }
    }

    //  초기값 push
    visited.push_back(Robot(1, 1, 1, 2));
    // queue에도 push
    q.push({ Robot(1, 1, 1, 2), 0 });

    while (q.empty() == false)
    {
        Robot now = q.front().first;
        int time = q.front().second;
        q.pop();

        // 마지막에 도착했다면 시간 return
        if ((now.y1 == n && now.x1 == n) || (now.y2 == n && now.x2 == n))
            return time;

        // 다음으로 이동할 수 있는 좌표들 구하기
        vector<Robot> next = getNext(now, new_board);

        // 가능한 좌표들을 q에 push
        for (int i = 0; i < next.size(); i++)
        {
            bool check = true;
            // 만약 방문했다면 push하지 않음
            for (int j = 0; j < visited.size(); j++)
            {
                if ((next[i].y1 == visited[j].y1) && (next[i].x1 == visited[j].x1) && (next[i].y2 == visited[j].y2) && (next[i].x2 == visited[j].x2)) 
                {
                    check = false;
                    break;
                }
            }
            if (check == true) 
            {
                q.push({ next[i],time + 1 });
                visited.push_back(next[i]);
            }
        }
    }
}




//
//int main(void)
//{
//    solution({ {0,0,0,1,1},{0,0,0,1,0},{0,1,0,1,1},{1,1,0,0,1,},{0,0,0,0,0} });
//    
//    return 0;
//}




// --- 핵심내용 ---
/*
   회전에 대해 고려할 때,,,,
   회전을 하기 위해서는
   위 / 아래   or   왼 / 오    두 좌표들이 모두 0이어야함
   하나라도 1이 있으면 회전 불가 !!!,,,,,
*/

// --- 틀린이유 ---
/*
   회전하는 부분에서 가로와 세로 각 부분에서 push해야하는
   경우의 수 빼먹음
*/
