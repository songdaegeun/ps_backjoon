#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    int occur[2][6];
    int n, k, s, y;

    memset(occur, 0, 12 * sizeof(int));
    scanf("%d %d", &n, &k);
    getchar();
    for(int i = 0; i < n ; i++)
    {
        scanf("%d %d", &s, &y);
        getchar();
        occur[s][y - 1]++;
    }
    int cnt = 0;
    for(int i = 0; i < 2 ; i++)
    {
        for(int j = 0; j < 6 ; j++)
            cnt += ceil((double)occur[i][j] / k);
    }
    printf("%d", cnt);
    return (0);
}