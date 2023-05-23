#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

int solution(vector<int> nums)
{
    int n = nums.size();
    unordered_set<int> s(nums.begin(), nums.end());
    
    if (s.size() > n / 2)
        return (n / 2);
    else
        return (s.size());
}

// 문제 설명에 고르는 방법 6가지가 있다고 친절히 예시를 보여주는데, 
// 마치 backtracking으로 comb를 구현해야할 것같아서 처음에 시도한 방법은 다음과 같다.
// 1. nums에서 n/2개를 선택하는 모든 경우를 탐색하는 combination함수 작성.
// 2. 각 경우마다 중복되지 않는 폰켓못 종류의 개수를 세고 그 갯수를 최대값과 비교하며 더 크면 최대값갱신.
// 3. 최대값 출력.
// 하지만 timeout이 나왔다.
// 해쉬를 썼는데 timeout...?
// 해쉬 맵 자료접근은 O(1)인데 그럼 내 로직이 잘못됐구나하고 문제를 다시보니 그냥 중복된 걸 없애고 요소개수를 n / 2과 비교하면 되는 문제였다.
// 폰켓몬의 종류를 물어봤으니 그것만 신경쓰면 되는데, 폰켓몬의 갯수도 사용될 여지가 있어서 계속 갖고 있어야 한다고 착각했었던 것 같다.