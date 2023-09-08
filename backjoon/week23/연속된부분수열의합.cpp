#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 폐구간 내 원소의 합이 k인 구간 중, 가장 길이가 짧은 것 중, 가장 앞에 있는 것 반환. 
// 제한: O(N)
// 투포인터
vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int size = sequence.size();
	int st = 0;
	int en = 0;
	int sum = sequence[0];
	// sub sequence 최소길이
	int min_len = size + 1;
	pair<int,int> result;

	while(st <= en && en < size)
	{
		if(sum == k) {
			if(en-st+1 < min_len) {
				min_len = en-st+1;
				result = {st,en};
			}
			else if(en-st+1 == min_len) {
				if(st < result.first) {
					result = {st,en};
				}
			}
			sum -= sequence[st++];
		}
		else if(sum < k) {
			sum += sequence[++en];
		}
		else {
			sum -= sequence[st++];
		}
	}
    return {result.first, result.second};
}
