#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>

using namespace std;

int to_second(string &str, int clk_type, int n) {
    stringstream ss(str);
    string tmp;
    vector<string> vec;
    int ret;
    while (getline(ss, tmp, ':')) {
        vec.push_back(tmp);
    }
    int hms[3];
    hms[0] = stoi(vec[0]);
    hms[1] = stoi(vec[1]);
    hms[2] = stoi(vec[2]);
    // cout << vec[0] << ' ' << vec[1] << ' ' << vec[2] << '\n';
    // cout << hms[0] << ' ' << hms[1] << ' ' << hms[2] << '\n';

    if(clk_type == 1) {
        if(hms[0] == 12) {
            hms[0] = 0;
        }
    }
    else if(clk_type == 2) {
        if(hms[0] != 12) {
            hms[0] += 12;
        }
    }
    ret = hms[0]*60*60 + hms[1]*60 + hms[2] + n;
    ret %= 86400;
    return (ret);
}

string to_24(int data) {
    int hms[3];
    for(int i =0; i<3; i++) {
        hms[2 -i] = data % 60;
        data /= 60;
    }
    string ret_tmp[3];
    ret_tmp[0] = to_string(hms[0]);
    ret_tmp[1] = to_string(hms[1]);
    ret_tmp[2] = to_string(hms[2]);
    if(ret_tmp[0].size() == 1)
        ret_tmp[0] = "0" + ret_tmp[0];
    if(ret_tmp[1].size() == 1)
        ret_tmp[1] = "0" + ret_tmp[1];
    if(ret_tmp[2].size() == 1)
        ret_tmp[2] = "0" + ret_tmp[2];

    string ret = ret_tmp[0] + ":" + ret_tmp[1] + ":" + ret_tmp[2];
    // cout << ret << '\n';
    return (ret);
}

string solution(string p, int n)
{
    string answer;
    // AM: 1, PM: 2
    int clk_type = -1;

    if(p.substr(0, 2) == "AM") {
        clk_type = 1;
    }
    else if(p.substr(0, 2) == "PM") {
        clk_type = 2;
    }
    // cout << p.substr(3, 8) << '\n';
    string post_str = p.substr(3, 8);
    int sec_ret = to_second(post_str, clk_type, n);
    answer = to_24(sec_ret);
    return answer;
}