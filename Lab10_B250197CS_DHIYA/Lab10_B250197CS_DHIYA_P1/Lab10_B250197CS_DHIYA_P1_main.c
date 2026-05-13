#include "Lab10_B250197CS_DHIYA_P1.h"

int main()
{
    int n;
    scanf("%d",&n);
    int count = 0;
    while (n--)
    {
        char exp[MAX];
        scanf("%s",exp);
        if (isBalanced(exp))
        count++;
    }
    printf("%d\n",count);
    return 0;
}