#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    unordered_map<string, string> map;
    for (int i = 0; i < n; i++)
    {
        // addr, passwd input.
        string addr, passwd;
        cin >> addr >> passwd;
        map[addr] = passwd;
    }
    for (int i = 0; i < m; i++)
    {
        string addr;
        cin >> addr;
        cout << map[addr] << '\n';
    }
    
}

// 16 4
// noj.am IU
// acmicpc.net UAENA
// startlink.io THEKINGOD
// google.com ZEZE
// nate.com VOICEMAIL
// naver.com REDQUEEN
// daum.net MODERNTIMES
// utube.com BLACKOUT
// zum.com LASTFANTASY
// dreamwiz.com RAINDROP
// hanyang.ac.kr SOMEDAY
// dhlottery.co.kr BOO
// duksoo.hs.kr HAVANA
// hanyang-u.ms.kr OBLIVIATE
// yd.es.kr LOVEATTACK
// mcc.hanyang.ac.kr ADREAMER
// startlink.io
// acmicpc.net
// noj.am
// mcc.hanyang.ac.kr