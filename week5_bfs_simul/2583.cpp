#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k;
int map[100][100];
int visited[100][100];
int area_arr[5000];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void swap(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void select_sort(int *area_arr, int cnt)
{
	for(int i = 0; i < cnt; i++)
	{
		for(int j = i + 1; j < cnt; j++)
		{
			if(area_arr[i] > area_arr[j])
				swap(&area_arr[i] , &area_arr[j]);
		}
	}
}
void bubble_sort(int *area_arr, int cnt)
{
	for(int i = 0; i < cnt; i++)
	{
		for(int j = 1; j < cnt - i; j++)
		{
			if(area_arr[j] < area_arr[j - 1])
				swap(&area_arr[j] , &area_arr[j - 1]);
		}
	}
}

int separate(int *arr, int s_i, int e_i)
{
    int tmp = arr[s_i];
    while (1)
    {
        while((tmp <= arr[e_i]) && (s_i < e_i))
            e_i--;
        if(s_i == e_i)
            break;
        arr[s_i++] = arr[e_i];
        while((arr[s_i] <= tmp) && (s_i < e_i))
            s_i++;
        if(s_i == e_i)
            break;
        arr[e_i--] = arr[s_i];
    }
    arr[e_i] = tmp;
    return (e_i);
}

void quick_sort(int *arr, int s_i, int e_i)
{
    int mid;
    if(s_i >= e_i)
        return ;
    mid = separate(arr, s_i, e_i);
    quick_sort(arr, s_i, mid - 1);
    quick_sort(arr, mid + 1, e_i);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	
	cin >> m >> n >> k;
	int left_down_x, left_down_y, right_up_x, right_up_y;
	while(k--)
	{
		cin >> left_down_x >> left_down_y >> right_up_x >> right_up_y;
		for(int i = left_down_x; i < right_up_x; i++)
		{
			for(int j = left_down_y; j < right_up_y; j++)
			{
				map[i][j] = 1;
			}
		}
	}
	// for(int i = 0; i < n; i++)
	// {
	// 	for(int j = 0; j < m; j++)
	// 	{
	// 		cout << map[i][j] << ' ';
	// 	}
	// 	cout << '\n';
	// }
	queue<pair<int,int>> q;
	vector<int> area_vector;
	int cnt = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(map[i][j] == 1 || visited[i][j]) continue;
			cnt++;
			int area = 0;
			visited[i][j] = 1;
			q.push({i,j});
			while(!q.empty())
			{
				pair<int,int> pos = q.front();
				q.pop();
				area++;
				int x = pos.first;
				int y = pos.second;
				for(int k = 0; k < 4; k++)
				{
					int nx = x + dx[k];
					int ny = y + dy[k];
					if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if(map[nx][ny] == 1 || visited[nx][ny]) continue;
					visited[nx][ny] = 1;
					q.push({nx,ny});
				}
			}
			// area_arr[cnt - 1] = area;
			area_vector.push_back(area);
		}
	}
	// select_sort(area_arr, cnt);
	// bubble_sort(area_arr, cnt);
	// quick_sort(area_arr, 0, cnt - 1);
	sort(area_vector.begin(), area_vector.end());
	cout << area_vector.size() << '\n';
	for(int i = 0; i < area_vector.size(); i++)
	{
		cout  << area_vector[i] << ' ';
	}
}


// 5 7 3
// 0 2 4 4
// 1 1 2 5
// 4 0 6 2
