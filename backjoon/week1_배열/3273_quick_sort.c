#include <stdio.h>
void quick_sort(int *arr, int s_i, int e_i);
int separate(int *arr, int s_i, int e_i);

int main()
{
    int n;
    int series[100000];
    int res = 0; 

    scanf("%d", &n);
    getchar();

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &(series[i]));
        getchar();
    }
    int x;
    scanf("%d", &x);
    getchar();

    // ascending order sort
    quick_sort(series, 0, n - 1);
    // for(int i = 0; i < n; i++)
    // {
    //     printf("%d ", series[i]);
    // }
    int k;
    for(k = 0; k < n; k++)
    {
        if (series[k] > x)
            break;
    }
    for(int i = 0; i < k; i++)
    {
        for(int j = i + 1; j < k; j++)
        {
            if (x == (series[i] + series[j]))
                res++;
            else if (x < (series[i] + series[j]))
                break;
        }
    }
    printf("%d", res);
    return (0);
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

int separate(int *arr, int s_i, int e_i)
{
    int tmp = arr[s_i];
    while (1)
    {
        while((tmp <= arr[e_i]) && (s_i < e_i))
            e_i--;
        if(s_i >= e_i)
            break;
        arr[s_i++] = arr[e_i];
        while((arr[s_i] <= tmp) && (s_i < e_i))
            s_i++;
        if(s_i >= e_i)
            break;
        arr[e_i--] = arr[s_i];
    }
    arr[e_i] = tmp;
    return (e_i);
}