
#include <stdio.h>

int fakt-rek(int n) {
    int f;
    if (n==1||n==0)
        return 1;
    else
        return fakt-rek(n)
}

int main()
{
    int n=5;
    printf("%d faktoriális %d\n", n, fakt(n));

}
