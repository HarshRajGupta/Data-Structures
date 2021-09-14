#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int Arr[45];

    int *ptr;
    int p = 56;
    ptr = &p;

    scanf("%d", Arr);
    printf("%d \t %d", *Arr, *ptr);
    return 0;
}