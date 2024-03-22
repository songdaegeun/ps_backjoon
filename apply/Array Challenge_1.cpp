#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cstring>

using namespace std;

vector<string> ana_vec, splited_str;
int idx_arr[2];

bool is_ana(string str1, string str2) {
  int alpha_cnt[26];
  memset(alpha_cnt, 0, sizeof(alpha_cnt));

  if(str1.size() != str2.size())
    return (false);
  for(int i = 0; i < str1.size(); i++) {
    alpha_cnt[str1[i]-'a']++;
    alpha_cnt[str2[i]-'a']--;
  }
  for(int i = 0; i < 26; i++) {
    if(alpha_cnt[i] != 0) {
      return (false);
    }
  }
  return (true);
}

void combi(int depth, int st) {
  if(depth == 2) {
    // anagram이 가능한 단어를 vector에 push
    if(is_ana(splited_str[idx_arr[0]], splited_str[idx_arr[1]])) {
      // anagram이므로 단어를 바꿔서 생각해도 됨
      splited_str[idx_arr[1]] = splited_str[idx_arr[0]];
      ana_vec.push_back(splited_str[idx_arr[0]]);
    }
    return;
  }
  for(int i = st; i < splited_str.size(); i++) {
    idx_arr[depth] = i;
    combi(depth+1, i+1);
  }
}

string ArrayChallenge(string str) {
  // string split
  istringstream ss(str);
  string str_buffer;
  while(getline(ss, str_buffer, ' ')) {
    splited_str.push_back(str_buffer);
  }
  // 정렬 후 중복제거
  sort(splited_str.begin(), splited_str.end());
  splited_str.erase(unique(splited_str.begin(), splited_str.end()), splited_str.end());

  // 2개씩 조합으로 선택
  combi(0,0);

  // 중복된 단어들을 count하고, count된 숫자 중 최대값에 해당하는 수를 string으로 출력
  sort(ana_vec.begin(), ana_vec.end());
  vector<int> cnt_vec;
  int cnt = 1;
  for(int i = 1; i < ana_vec.size(); i++) {
    if(ana_vec[i-1] == ana_vec[i])
      cnt++;
    else {
      cnt_vec.push_back(cnt);
      cnt = 1;
    }
  }
  cnt_vec.push_back(cnt);

  int max_cnt_raw = -1;
  for(auto el: cnt_vec) {
    if(max_cnt_raw < el)
      max_cnt_raw = el;
  }
  int ans = 1;
  while(max_cnt_raw*2 != (ans*(ans-1))) {
    ans++;
  }
  return (to_string(ans-1));
}

int main(void) {    
  cout << ArrayChallenge(coderbyteInternalStdinFunction(stdin));

  return 0;
}