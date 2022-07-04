#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

int city[51][51];
int n, m;

// 1: 집, 2: 치킨 집
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;

int countChicken(int subset)
{
	int cnt = 0;

	while (subset)
	{
		if (subset & 1 == 1)
			cnt++;
		subset >>= 1;
	}
	return cnt;
}

int solve()
{
	// m 개의 치킨집을 고르고 그 때의 치킨 거리가 최소인 것을 구하기

	// 치킨 집의 개수만큼 비트 수를 지정
	// 예) 3 개면 000~111

	int result_chicken_root = 126456789;
	for (int subset = 0; subset < (1<<chicken.size()); ++subset)
	{
		int city_chicken_root = 0;                       //  ---> 이거 안 해서 틀림

		// 그 중 M개의 치킨 집을 고르는 경우
		// 비트로 봤을 때 1의 개수가 m개일 때만 치킨거리 구하기
		if (countChicken(subset) == m)
		{
			// 모든 집에 대해서 선택된 m개의 치킨 집에 대한 거리를 구하기
			for (int h = 0; h < house.size(); ++h)
			{
				// 현재 집에 대해서
				// 부분집합에 속한 치킨 집 중에서 거리가 최소인 거 찾기
				int min_chicken_root = 1000;
				for (int c = 0; c < chicken.size(); ++c)
				{
					// 해당 치킨 집이 선택되었으면
					// 비트로 봤을 때 해당 위치에 1이 있을 때만
					if (subset & (1 << c)) // 결과 값이 0이 아니면
					{
						// 치킨 거리 구하기
						int chicken_root = abs(house[h].first - chicken[c].first) + abs(house[h].second - chicken[c].second);
						min_chicken_root = min(chicken_root, min_chicken_root);
					}
				}
				city_chicken_root += min_chicken_root;
			}
			result_chicken_root = min(result_chicken_root, city_chicken_root);
		}
	}
	return result_chicken_root;
}

int main(void)
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int input;
			cin >> input;
			if (input == 1)
				house.push_back({ i ,j });
			else if (input == 2)
				chicken.push_back({ i,j });
		}
	}

	cout << solve() << endl;
}


// ===========================================================
(교재 풀이)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int arr[50][50];
vector<pair<int, int> > chicken;
vector<pair<int, int> > house;

// 치킨 거리의 합을 계산하는 함수
int getSum(vector<pair<int, int> > candidates) {
    int result = 0;
    // 모든 집에 대하여
    for (int i = 0; i < house.size(); i++) {
        int hx = house[i].first;
        int hy = house[i].second;
        // 가장 가까운 치킨 집을 찾기
        int temp = 1e9;
        for (int j = 0; j < candidates.size(); j++) {
            int cx = candidates[j].first;
            int cy = candidates[j].second;
            temp = min(temp, abs(hx - cx) + abs(hy - cy));
        }
        // 가장 가까운 치킨 집까지의 거리를 더하기
        result += temp;
    }
    // 치킨 거리의 합 반환
    return result;
}

int main(void) {
    cin >> n >> m;

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            cin >> arr[r][c];
            if (arr[r][c] == 1) house.push_back({ r, c }); // 일반 집
            else if (arr[r][c] == 2) chicken.push_back({ r, c }); // 치킨집
        }
    }

    // 모든 치킨 집 중에서 m개의 치킨 집을 뽑는 조합 계산
    vector<bool> binary(chicken.size());
    fill(binary.end() - m, binary.end(), true);

    // 치킨 거리의 합의 최소를 찾아 출력
    int result = 1e9;

    do {
        vector<pair<int, int>> now;
        for (int i = 0; i < chicken.size(); i++) {
            if (binary[i] == 1) {
                int cx = chicken[i].first;
                int cy = chicken[i].second;
                now.push_back({ cx,cy });
            }
        }
        result = min(result, getSum(now));
    } while (next_permutation(binary.begin(), binary.end()));

    cout << result << '\n';
}
