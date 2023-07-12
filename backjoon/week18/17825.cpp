#include <iostream>
using namespace std;

int next_idx[33]; //21 + 11개
int score[33];    
int visited[33];    
int turn_pt[33];   // 4개
int ans;
int mal[4];		   // 4개
int dice[10];


void init()
{
	for (int i = 0; i < 21; i++) score[i] = 2*i;
	score[22] = 13; score[23] = 16;
	score[24] = 19;	score[25] = 22;
	score[26] = 24; score[27] = 28;
	score[28] = 27;	score[29] = 26;
	score[30] = 25;	score[31] = 30;
	score[32] = 35;

	for (int i = 0; i < 21; i++) next_idx[i] = i + 1;
	next_idx[21] = 21;	next_idx[22] = 23;
	next_idx[23] = 24;	next_idx[24] = 30;
	next_idx[25] = 26;	next_idx[26] = 30;
	next_idx[27] = 28;	next_idx[28] = 29;
	next_idx[29] = 30;	next_idx[30] = 31;
	next_idx[31] = 32;	next_idx[32] = 20;

	turn_pt[5] = 22;	turn_pt[10] = 25;
	turn_pt[15] = 27;
}

void sol(int depth, int sum)
{
	if(depth == 10) {
		if(ans < sum) ans = sum;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int pos = mal[i];
		int n_pos = pos;
		int step = dice[depth];

		if(turn_pt[pos] > 0) {
			n_pos = turn_pt[n_pos];
			step--;
		}
		while(step--) {
			n_pos = next_idx[n_pos];
		}
		if(n_pos != 21 && visited[n_pos] == 1) continue;
		visited[pos] = 0;
		visited[n_pos] = 1;
		mal[i] = n_pos;
		sol(depth+1, sum+score[n_pos]);
		mal[i] = pos;
		visited[pos] = 1;
		visited[n_pos] = 0;
	}
	
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
	for (int i = 0; i < 10; i++)
	{
		cin >> dice[i];
	}
	sol(0, 0);
	cout << ans;
}