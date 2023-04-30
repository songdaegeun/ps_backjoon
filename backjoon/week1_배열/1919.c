#include <stdio.h>
#define ABS(x) ((x) < 0)? -1 * (x) : (x) 
int cnt_rm_char(int *arr, int size);

int main()
{
    char str1[1001];
    char str2[1001];
    int alpha_check[26] = {};
    int res = 0;

    // for(int i = 0; i < 26 ; i++)
    // {
    //     printf("%d ", alpha_check[i]);
    // }
    scanf("%s", str1);
    getchar();
    scanf("%s", str2);
    getchar();

    int i = 0;
    while(str1[i])
    {
        alpha_check[str1[i] - 'a']++;
        i++;
    }
    i = 0;
    while(str2[i])
    {
        alpha_check[str2[i] - 'a']--;
        i++;
    }

    // printf("%d ", sizeof(alpha_check) / sizeof(int));
    res = cnt_rm_char(alpha_check, sizeof(alpha_check) / sizeof(int));
    printf("%d", res);
    return (0);
}

int cnt_rm_char(int *arr, int size)
{
    int i = 0;
    int cnt = 0;
    while(i < size)
    {
        if(arr[i] != 0)
            cnt += ABS(arr[i]);
        i++;
    }
    return (cnt);
}