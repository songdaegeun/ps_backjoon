#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

int chk_win(char player, vector<string> &board)
{
    for(int i=0; i<3; i++) {
        if (board[i][0] == player && board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return true;

        if (board[0][i] == player && board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return true;
    }

    if (board[0][0] == player && board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return true;

    if (board[2][0] == player && board[2][0] == board[1][1] && board[1][1] == board[0][2])
        return true;

    return false;
}

int solution(vector<string> board) {
    int answer = -1;
    
    
    int o_cnt = 0;
    int x_cnt = 0;
    
    for(auto el: board) {
        for(int i = 0; i < 3; i++) {
            o_cnt += (el[i] == 'O');
            x_cnt += (el[i] == 'X');
        }    
    }
    // cout <<  o_cnt - x_cnt << ',' << triple_cnt << '\n';
    if (!(1 >= o_cnt - x_cnt && o_cnt - x_cnt >= 0))
        answer = 0;
    else if((chk_win('O', board) && !((o_cnt - x_cnt) == 1)) || \
       (chk_win('X', board) && !((o_cnt - x_cnt) == 0))) {
        answer = 0;
    }
    else if(chk_win('O', board) && chk_win('X', board)){
        answer = 0;
    }
    else
        answer = 1;
    return answer;
}