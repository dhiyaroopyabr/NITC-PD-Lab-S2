#include <stdio.h>
#include "Lab10_B250197CS_DHIYA_P2.h"

int main()
{
    char s[1000000];
    scanf("%s",s);
    int x, k;
    scanf("%d",&x);
    scanf("%d",&k);
    int i = 0;
    node root = build(s,&i);
    node target = search(root,x);
    if (target)
    display(target,k);
    return 0;
}