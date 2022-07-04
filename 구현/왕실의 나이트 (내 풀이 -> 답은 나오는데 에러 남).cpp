#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

// row + -> 밑으로, col + -> 오른쪽으로
int move_row[8] = { 2,2,-2,-2,1,1,-1,-1 };
int move_col[8] = { 1,-1,1,-1,2,-2,2,-2 };

bool range_check(int r, int c)
{
    if (r < 1 || r>8 || c < 1 || c>8)
        return false;
    else
        return true;
}

int main(void) 
{
    // row= num , column= english
    char input[2];             
----------------------------> 에러 이유: 문자열 2개 받으려면 공간은 3개 필요
                                         ('\0')까지   
    scanf("%s", input);

    int row = input[1]-'0';
    int col = input[0] - 'a' + 1;

    int cur_r = 0;
    int cur_c = 0;
    int cnt = 0;

    // 8가지의 경우 체크
    for (int i = 0; i < 8; i++)
    {
        cur_r = row + move_row[i];
        cur_c = col + move_col[i];

        if (range_check(cur_r, cur_c) == true) {
            // count
            cnt++;
        }
        cur_r = row;
        cur_c = col;
    }

    cout << "총 " << cnt << "개" << endl;

    return 0;
}
