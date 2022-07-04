#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = dist.size() + 1;
    
    int w_s= weak.size();
    // weak 길이 2배로 늘려서 1차원배열로 관리
    for (int i = 0; i < w_s; i++) {
        weak.push_back(weak[i] + n);
    }

    // dist 정렬
    sort(dist.begin(), dist.end());

    // 취약지점 처음부터 순서대로 탐색
    for (int i = 0; i < w_s; i++) {
        
        // 순열을 이용해 한 가지의 dist 선택
        do {
            int num = 1;
            int position = weak[i] + dist[num - 1];
            // 선택된 dist를 정해진 취약점부터 대입해보기
            for (int j = i; j < i + w_s; j++) {
                
                // 현재 놈으로 다음 취약점까지 갈 수 있다면
                if (position >= weak[j]) {
                    // j만 증가
                }
                else {
                    // 현재 놈으로 다음 취약점까지 갈 수 없으면
                    num++;
                    // 더 투입할 놈이 없다면 종료
                    if (num > dist.size()) break;
                    // 다음 취약점부터 시작
                    position = weak[j] + dist[num - 1];
                }
            }
            answer = min(answer, num);
        } while (next_permutation(dist.begin(), dist.end()));
    }
    if(answer > dist.size()) return -1;
    return answer;
}


----------------------------------------------------------------------
// 틀린이유 : 처음 배열 2배하는 부분  --> 배열이 커지면 i도 같이 커져서 무한루프, 
//            다음 인덱스의 dist를 현재 위치의 바로 뒤에 붙였음

// 해결     : 다음 인덱스의 dist에 도달하지 못하면  --> 바로 뒤에 이어서
//          : 다음 인덱스의 dist를 넘어가면         --> 바로 뒤 말고, 다음 인덱스의 dist부터 시작
