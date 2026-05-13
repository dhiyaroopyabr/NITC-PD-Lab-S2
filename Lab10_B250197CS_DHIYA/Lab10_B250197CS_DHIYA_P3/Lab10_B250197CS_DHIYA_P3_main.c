#include <stdio.h>
#include "Lab10_B250197CS_DHIYA_P3.h"

int main()
{
    char s[100000];
    scanf("%s",s);
    int i = 1;
    node root = build(s,&i);
    postorder(root);
    return 0;
}