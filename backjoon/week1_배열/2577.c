#include <unistd.h>
#include <stdio.h>

int main(){
    int a,b,c;
    int mul;
    int cnt[10] = {0,};

    scanf("%d", &a);
    getchar();
    scanf("%d", &b);
    getchar();
    scanf("%d", &c);
    getchar();
    mul = a * b * c;
    while(mul)
    {
        cnt[mul % 10]++;
        mul /= 10;
    }
    for(int i = 0; i < 10; i++)
    {
        printf("%d\n", cnt[i]);
    }
    return (0);    
}