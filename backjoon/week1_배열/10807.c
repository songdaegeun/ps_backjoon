#include <stdio.h>

int main()
{
  int n, x;
  int arr[100000];

  scanf("%d", &n);
  getchar();
  for(int i = 0; i < n ; i++)
  {
    scanf("%d", &arr[i]);
    getchar();
  }
  scanf("%d", &x);
  getchar();
  int cnt = 0;
  for(int i = 0; i < n ; i++)
  {
    if(x == arr[i])
        cnt++;
  }
  printf("%d", cnt);
  return (0);
}