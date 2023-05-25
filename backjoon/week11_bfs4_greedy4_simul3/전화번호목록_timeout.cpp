#include <string>
#include <vector>
#include <unordered_set>

using namespace std;
// 한 번호가 다른 번호의 접두어이면 false
// 1. nP2로 case마다 substr이 일치하는지 비교하는 방법 O // N^2이라서 안됨
// 2. phone_book_pcy를 순회하면서 각 요소에 대해 그 요소(phone)의 길이만큼 순회하면서 다른 요소가 그 요소의
// 길이보다 크거나 같다면 첫번째글자를 비교해서 다르면 제거하면서 순회가 끝나고
// phone_book내에 phone.size()보다 크거나 같은 요소가 1개보다 많으면 return false
bool solution(vector<string> phone_book) {
    bool answer = true;
    for(auto phone:phone_book) {
        unordered_set<string> phone_book_cpy(phone_book.begin(), phone_book.end());
        for(int i = 0; i < phone.size(); i++) {
            auto it = phone_book_cpy.begin();
            auto last_it = phone_book_cpy.end();
            while(it != last_it) {
                if ((*it).size() >= phone.size() && phone[i] != (*it)[i]) {
                    auto tmp = it;
                    it++;
                    phone_book_cpy.erase((*tmp));
                }
                else {
                    it++;
                }
            }
        }
        int cnt = 0;
        for(auto phone_remain:phone_book_cpy) {
            if(phone_remain.size() >= phone.size()) {
                cnt++;
            }
        }
        if(cnt > 1)
            return (false);
    }
    return answer;
}