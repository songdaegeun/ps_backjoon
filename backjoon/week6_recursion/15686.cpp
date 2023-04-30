#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int map[51][51];
int n, m;
vector<pair<int,int>> home_v, chicken_v;
int min_chicken_dist = 1300;

void disp_map()
{
	cout << '\n';
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}

int dist(pair<int,int> a, pair<int,int> b)
{
	return(abs(a.first - b.first) + abs(a.second - b.second));
}

// void combi_deprecated(int st_i, int m, int depth)
// {
// 	if(depth == m)
// 	{
// 		int chicken_dist = 0;
// 		for (int i = 0; i < home_v.size(); i++)
// 		{
// 			int min = 2 * n;
// 			// for (pair<int,int> chicken_pos : m_chicken_v)
// 			for (int j = 0; j < m; j++)
// 			{
// 				if(min > dist(home_v[i], m_chicken_v[j]))
// 					min = dist(home_v[i], m_chicken_v[j]);
// 				// min = std::min(dist(home_v[i], m_chicken_v[j]), min);
// 			}
// 			chicken_dist += min;
// 		}
// 		if(min_chicken_dist > chicken_dist)
// 			min_chicken_dist = chicken_dist;
// 		// min_chicken_dist = std::min(chicken_dist, min_chicken_dist);
// 		return ;
// 	}
// 	for (int i = st_i; i < chicken_v.size(); i++)
// 	{
// 		// m_chicken_v.push_back(chicken_v[i]);
// 		m_chicken_v[depth] = chicken_v[i];
// 		combi_deprecated(st_i + 1, m, depth + 1);
// 		// m_chicken_v.pop_back();
// 	}
// }
void combi()
{
    vector<bool> temp(chicken_v.size(), 1);
    for(int i = 0; i < chicken_v.size() - m; i++)
        temp[i] = 0;
    do { 
		int chicken_dist = 0;
		for (int j = 0; j < home_v.size(); j++)
		{
			int min = 2 * n;
			for (int i = 0; i < chicken_v.size(); ++i)
			{
				if(temp[i])
				{
					if(min > dist(home_v[j], chicken_v[i]))
						min = dist(home_v[j], chicken_v[i]);
				}
			}
			chicken_dist += min;
		}
		if(min_chicken_dist > chicken_dist)
			min_chicken_dist = chicken_dist;
    } while (next_permutation(temp.begin(), temp.end()));
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(map[i][j] == 1)
				home_v.push_back({i, j});
			else if(map[i][j] == 2)
				chicken_v.push_back({i, j});
		}
	}
	combi();
	cout << min_chicken_dist;
}

// 5 3
// 0 0 1 0 0
// 0 0 2 0 1
// 0 1 2 0 0
// 0 0 1 0 0
// 0 0 0 0 2