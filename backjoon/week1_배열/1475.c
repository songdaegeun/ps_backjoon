#include <stdio.h>
#include <math.h>

int main()
{
    int num_cnt[10]= {0, };
    int room_num_int;
    int max = -1;

    scanf("%d", &room_num_int);
    getchar();
    int i = 0;
    while(room_num_int)
    {
        num_cnt[room_num_int % 10]++;
        room_num_int /= 10;
        i++;
    }
    int six_nine_aver_ceil = ceil(((double)num_cnt[6] + num_cnt[9]) / 2);
    int cmp;
    for(int i = 0; i < 10; i++)
    {
        if(i == 6 || i == 9)
            cmp = six_nine_aver_ceil;
        else 
            cmp = num_cnt[i];
        if (max < cmp)
            max = cmp;
    }
    printf("%d", max);
    return (0);
}