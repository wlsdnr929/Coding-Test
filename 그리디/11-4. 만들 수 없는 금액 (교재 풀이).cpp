// 핵심내용: n-1까지의 모든 수를 만들 수 있다는 가정하에 
//           n번째 수를 만들 수 있는가?

#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> arr;

int main(void) {
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    sort(arr.begin(), arr.end());

    int target = 1;
    for (int i = 0; i < n; i++) {
        // 만들 수 없는 금액을 찾았을 때 반복 종료
        if (target < arr[i]) break;
        target += arr[i];
    }

    // 만들 수 없는 금액 출력
    cout << target << '\n';
}

// target보다 작은 수는 만들 수 있다고 가정 ( 실제로도 그럼 ) 
--> 이해안되면 예시들어서...
ex) 1 2 4 는 가능 
  ㄴ target 1 -> 1
  ㄴ target 2로 갱신 -> 2
  ㄴ target 4로 갱신 -> 4
  ㄴ target 8로 갱신 --> 7까지는 만들 수 있음
