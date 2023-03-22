#include <stdio.h>
#include<string.h>

int main()
{
    char buff[101];
    int alpha_cnt[26];

    scanf("%s", buff);
    getchar();

    memset(alpha_cnt, 0, 26 * sizeof(int));
    int i = 0;
    while(buff[i])
    {
        alpha_cnt[buff[i] - 'a']++;
        i++;
    }
    for(int i = 0; i < 26; i++)
    {
        printf("%d", alpha_cnt[i]);
        if(i != 25)
            printf(" ");
    }
    return (0);
}