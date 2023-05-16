#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

string name[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    unordered_map<string,int> dict;
    // string을 key로하면 dict,
    // int를 index로하면 nema array.
    for (int i = 0; i < n; i++)
    {
        cin >> name[i + 1];
        dict[name[i + 1]] = i + 1;
    }
    for (int i = 0; i < m; i++)
    {
        string query;
        cin >> query;
        if('0' <= query[0] && query[0] <= '9') 
        {
            int num = stoi(query);
            // for (auto el : dict)
            // {
            //     if (el.second == num)
            //     {
            //         cout << el.first << '\n';
            //         break;
            //     }
            // }
            cout << name[num] << '\n';
        }
        else           // string
            cout << dict[query] << '\n';
    }
}
// 26 5
// Bulbasaur
// Ivysaur
// Venusaur
// Charmander
// Charmeleon
// Charizard
// Squirtle
// Wartortle
// Blastoise
// Caterpie
// Metapod
// Butterfree
// Weedle
// Kakuna
// Beedrill
// Pidgey
// Pidgeotto
// Pidgeot
// Rattata
// Raticate
// Spearow
// Fearow
// Ekans
// Arbok
// Pikachu
// Raichu
// 25
// Raichu
// 3
// Pidgey
// Kakuna