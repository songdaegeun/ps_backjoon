#include <iostream>
#include <queue>
#define MAX_SIZE 2000000
using namespace std;
void push(int data);
int pop();
int empty();
int size();
int front();
int back();
int full();

int q[MAX_SIZE];
int r_index = 0;
int l_index = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // queue<int> q;
    string str;
    int data;
    int n;
    cin >> n; 
    while(n--)
    {
        cin >> str;
        if (str == "push")
        {
            cin >> data;
            push(data);
        }
        else if (str == "pop")
        {
            cout << pop() << '\n';
        }
        else if (str == "size")
        {
            cout << size() << '\n';
            
        }
        else if (str == "empty")
        {
            cout << empty() << '\n';
            
        }
        else if (str == "front")
        {
            cout << front() << '\n';
        }
        else if (str == "back")
        {
            cout << back() << '\n'; 
        }
    }
}

void push(int data)
{
    if (!full())
    {
        r_index = (r_index + 1) % MAX_SIZE;
        q[r_index] = data;
    }
}

int pop()
{
    int res;

    if (!empty())
    {
        res = q[l_index + 1];
        l_index = (l_index + 1) % MAX_SIZE;
        return (res);
    }
    else
        return (-1);
}
int empty()
{
    if (r_index == l_index)
        return (1);
    return (0);
}
int size()
{
    if (l_index <= r_index)
        return (r_index - l_index);
    else
        return (MAX_SIZE - (l_index - r_index));
}
int front()
{
    if (!empty())
        return (q[l_index + 1]);
    else
        return (-1);
}
int back()
{
    if (!empty())
        return (q[r_index]); 
    else
        return (-1);
}
int full()
{
    if ((r_index + 1) % MAX_SIZE == l_index)
        return (1);
    return (0);
}

