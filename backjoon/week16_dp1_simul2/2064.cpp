#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

vector<vector<int>> v; 
int net_addr[4][8];
int net_mask[4][8];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for (int i = 0; i < 4; i++)
        fill(net_mask[i], net_mask[i] + 8, 1);
    
	int n;
    cin >> n;
    unsigned int max_ip = 0;
    int max_ip_idx = 0;
    unsigned int min_ip = 4294967295;
    int min_ip_idx = 0;
    for (int i = 0; i < n; i++)
    {
        string str, token;
        cin >> str;
        stringstream ss(str);
        vector<int> tmp;
        unsigned int sum = 0;
        while (getline(ss, token, '.')) {
            int num = stoi(token);
            sum = (sum << 8) + num;
            tmp.push_back(num);
        }
        if(sum > max_ip) {
            max_ip = sum;
            max_ip_idx = i;
        }
        if(sum < min_ip) {
            min_ip = sum;
            min_ip_idx = i;
        }
        v.push_back(tmp);
    }
    // 최소와 최대 ip끼리 비교해서
    // 같은 숫자이면 네트워크 주소에 저장하고, 
    // 처음으로 다른 숫자가 나오는 idx부터 mask 요소는 0

    int flag = 0;
    for(int i = 0; i < 4; i++) {
        for(int j = 7; j >= 0; j--) {
            if(!flag && ((v[max_ip_idx][i] & (1 << j)) >> j) == ((v[min_ip_idx][i] & (1 << j)) >> j)) {
                net_addr[i][7 - j] = ((v[max_ip_idx][i] & (1 << j)) >> j);
            }
            else {
                net_mask[i][7 - j] = 0;
                flag = 1;
            }
        }
    }

    for(int i = 0; i < 4; i++) {
        int sum_addr = 0;
        for(int j = 0; j < 8; j++) {
            sum_addr = (sum_addr << 1) + net_addr[i][j];
        }
        cout << sum_addr;
        if(i != 3)
            cout << '.';
    }
    cout << '\n';

    for(int i = 0; i < 4; i++) {
        int sum_mask = 0;
        for(int j = 0; j < 8; j++) {
            sum_mask = (sum_mask << 1) + net_mask[i][j];
        }
        cout << sum_mask;
        if(i != 3)
            cout << '.';
    }
}
