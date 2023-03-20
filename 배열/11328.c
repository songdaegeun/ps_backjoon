#include <stdio.h>
#include <string.h>
int is_all_zero(int *arr, int size);

int main()
{
    int n;
    char str1[1001];
    char str2[1001];
    char *res;
    
    
    scanf("%d", &n);
    getchar();
    for(int j = 0; j < n ; j++)
    {
        int alpha_check[26];
        memset(alpha_check, 0, 26 * sizeof(int));
        scanf("%s %s", str1, str2);
        getchar();

        int i = 0;
        while(str1[i] && str2[i])
        {
            alpha_check[str1[i] - 'a']++;
            alpha_check[str2[i] - 'a']--;
            i++;
        }
        if(is_all_zero(alpha_check, 26))
            res = "Possible";
        else
            res = "Impossible";
        printf("%s\n", res);
    }
    return (0);
}

int is_all_zero(int *arr, int size)
{
    int i = 0;
    while(i < size)
    {
        if(arr[i] != 0)
            return (0);
        i++;
    }
    return (1);
}