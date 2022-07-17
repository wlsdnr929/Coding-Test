#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;


vector<vector<int>> right_rot_90(vector<vector<int>> cur)
{
	int n = cur.size();    

	vector<vector<int>> result(n, vector<int> (n));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			result[j][n - 1 - i] = cur[i][j];

	return result;
}

bool check(vector<vector<int>> big, vector<vector<int>> key, vector<vector<int>> lock)
{
	// lock 범위 안에 있는 것 중, 모든 칸의 합이 1
	for (int i = 0; i < lock.size(); i++)
	{
		for (int j = 0; j < lock.size(); j++)
		{
			// lock범위 안의 숫자 중 하나라도 1이 아니면 false
			if (big[i + key.size() - 1][j + key.size() - 1] != 1)
				return false;
		}
	}
	return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {

	// key와 lock이 모두 들어갈 수 있는 큰 판 만들기
	int n = key.size();
	int m = lock.size();

	// big을 모두 2로 초기화
	vector<vector<int>> big(m + 2 * n - 2, vector<int>(m + 2 * n - 2, 2));

	// big의 가운데에 lock 복사
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			big[i + n - 1][j + n - 1] = lock[i][j];


	// key에 대해 모든 lock을 검사 ( key가 회전할 때 마다)
	// 최대 4번 회전 
	for (int i = 0; i < 4; i++)
	{
		key = right_rot_90(key);

		// key를 한 칸씩 이동시키며
		for (int x = 0; x <= big.size() - n; x++)         //  --> 처음엔   x < big.size()-n 이라고 함
		{
			for (int y = 0; y <= big.size() - n; y++)       //  --> 처음엔   y < big.size()-n 이라고 함
			{
				// key와 lock 더하기
				for (int j = 0; j < key.size(); j++)
					for (int k = 0; k < key.size(); k++)
						big[x + j][y + k] += key[j][k];

				// 그 때마다 한 번씩 check
				if (check(big, key, lock))
					return true;
				// check 후 key값 돌려놓기
				for (int j = 0; j < key.size(); j++)
					for (int k = 0; k < key.size(); k++)
						big[x + j][y + k] -= key[j][k];
			}
		}
	}
	return false;
}
