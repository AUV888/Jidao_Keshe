#include <stdio.h>

int n, max_take;
//Bash Game的必胜策略：先手取n%(max+1)数量，必胜。若其为0，则必败可任取
int main(void)
{
    scanf("%d %d", &n, &max_take);
    do
    {
        int r = n % (max_take + 1);
        n -= r != 0 ? r : 1;
        printf("%d\n", r);
        fflush(stdout);
        if (n == 0)
        {

            return 0;
        }
        int m;
        scanf("%d", &m);
        n -= m;
        if (n == 0)
        {
            return 0;
        }
    } while (1);
    return 0;
}