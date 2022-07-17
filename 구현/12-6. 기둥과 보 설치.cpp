
------------------------------------( 내 풀이 )

#include <string>
#include <vector>

using namespace std;

int row[101][101];
int cross[101][101];

bool check_row(int x, int y){
    // 바닥위
    if (y == 0)
        return true;
    // 보의 한쪽 끝
    if (x>0 && cross[x - 1][y] == 1)
        return true;
    // 다른 기둥 위
    if (row[x][y - 1] == 1)
        return true;
    // 현재 자리에 보가 있을 때
    if (cross[x][y] == 1)
        return true;
    return false;
}

bool check_cross(int x, int y){
    // 기둥 한쪽 끝
    if (((y>0) && (row[x][y - 1] == 1)) || ((y>0) && (row[x+1][y-1]==1)))
        return true;
    // 양쪽 끝에 보
    if ((x>0 && cross[x - 1][y] == 1) && cross[x + 1][y])
        return true;
    return false;
}

bool check_all(vector<vector<int>> b,int n) {
    for (int i = 0; i <n; i++) {
            // 기둥이고 설치되어 있다면 
            // --> 어차피 설치할 수 없는 것 때문에 false가 나면 안됨 ( ex (2,2,0,1) )
        if (row[b[i][0]][b[i][1]]==1) {
            if (check_row(b[i][0], b[i][1]) == false)
                return false;
        }// 보이고 설치되어 있다면
        if (cross[b[i][0]][b[i][1]] == 1) {
            if (check_cross(b[i][0], b[i][1]) == false)
                return false;
        }
    }
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    for (int i = 0; i < build_frame.size(); i++)
    {
        int x = build_frame[i][0];
        int y = build_frame[i][1];
        int type = build_frame[i][2];
        int cmd = build_frame[i][3];
        // 기둥
        if (type == 0){
            //설치
            if (cmd == 1){
                if (check_row(x, y))
                    row[x][y] = 1;
            }// 삭제
            else{
                // 일단 삭제
                row[x][y] = 0;
                // 삭제할 수 없으면 복구 ,  i : 현재의 삭제가 일어난 순간까지만 확인하기 위해
                if (check_all(build_frame,build_frame.size()) == 0)
                    row[x][y] = 1;
            }
        }
        // 보
        else{
            //설치
            if (cmd == 1){
                if (check_cross(x, y))
                    cross[x][y] = 1;
            }
            // 삭제
            else{
                // 일단 삭제
                cross[x][y] = 0;
                // 삭제할 수 없으면 복구
                if (check_all(build_frame,build_frame.size()) == 0)
                    cross[x][y] = 1;
            }
        }
    }

    for (int x = 0; x <= n; x++) {
        for (int y = 0; y <= n; y++) {
            if (row[x][y] == 1)
                answer.push_back({ x,y,0 });
            if (cross[x][y] == 1)
                answer.push_back({ x,y,1 });
        }
    }
    return answer;
}

// int main(void)
// {
//     vector<vector<int>> b;
//     b.push_back({ 0,0,0,1 });
//     b.push_back({ 2,0,0,1 });
//     b.push_back({ 4,0,0,1 });
//     b.push_back({ 0,1,1,1 });
//     b.push_back({ 1,1,1,1 });
//     b.push_back({ 2,1,1,1 });
//     b.push_back({ 3,1,1,1 });
//     b.push_back({ 2,0,0,0 });
//     b.push_back({ 1,1,1,0 });
//     b.push_back({ 2,2,0,1 });
//     solution(5,b);
// }


// 틀린이유
// --> 기둥이나 보를 설치할 경우, 좌표의 범위를 넘어갔는지 체크 안 함,,,,
// --> 기둥의 설치 조건 중 , 현재 자리에 보가 있을 때를 체크 안 함,,,



------------------------------------ (유튜브 풀이)



#include <string>
#include <vector>

using namespace std;

int pillar[101][101];
int bar[101][101];

// 기둥을 세울 수 있는 지 확인
bool checkPillar(int x, int y)
{
    // 바닥이면 가능
    if (x >= 0 && y == 0)
        return true;
    // 또 다른 기둥위에
    if (y>0 && pillar[x][y - 1] == 1)
        return true;
    // 보의 한쪽 끝
    if ((x>0 && bar[x - 1][y] == 1) || bar[x][y] == 1)
        return true;
    return false;
}


// 보를 설치할 수 있는 지 확인
bool checkBar(int x, int y)
{
    // 한 쪽 끝이 기둥이면 가능
    if ((y>0 && pillar[x][y - 1] == 1) ||(y>0 && pillar[x + 1][y - 1] == 1))
        return true;

    // 양 쪽이 보일 때 가능
    if (x>0 && bar[x - 1][y] == 1 && bar[x + 1][y] == 1)
        return true;

    return false;
}

bool deletePossible(int x, int y)
{
    // x가 음수일 때와 y가 100보다 클 때 처리하는 법
    for (int i = max(x-2,0); i <min(101,x+3); i++)
    {
        for (int j = max(y-2,0); j < min(101,y+3); j++)
        {
            if (pillar[i][ j] == 1)
            {
                if (checkPillar(i, j) == false)
                    return false;
            }
            if (bar[i][j] == 1)
            {
                if (checkBar(i, j) == false)
                    return false;
            }
        }
    }
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;

    for (int i = 0; i < build_frame.size(); i++)
    {
        int x = build_frame[i][0];
        int y = build_frame[i][1];
        int type = build_frame[i][2]; // 0은 기둥, 1은 보
        int cmd = build_frame[i][3];  // 0은 삭제, 1은 설치

        // 설치할 경우
        if (cmd == 1)
        {
            // 기둥일 경우
            if (type == 0)
            {
                if (checkPillar(x, y) == true)
                {
                    // 설치
                    pillar[x][y] = 1;
                }
            }
            // 보일 경우
            else
            {
                if (checkBar(x, y) == true)
                {
                    // 설치
                    bar[x][y] = true;
                }
            }
        }
        // 삭제할 경우
        // 일단 삭제하고 주변 것들이 존재가능한지 여부를 가지고 판단
        else
        {
            // 기둥일 경우
            if (type == 0)
            {
                pillar[x][y] = 0;
                if (deletePossible(x, y) == false)
                    pillar[x][y] = 1;
            }
            // 보일 경우
            else
            {
                bar[x][y] = 0;
                if (deletePossible(x, y) == false)
                    bar[x][y] = 1;
            }
        }
        
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (pillar[i][j] == 1)
                answer.push_back({ i,j,0});
            if (bar[i][j] == 1)
                answer.push_back({ i,j,1});
        }
    }
   
    return answer;
}
