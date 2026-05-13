#include <stdio.h>
#include "Lab10_B250197CS_DHIYA_P6.h"


int main() {
    char s[100000];
    scanf("%s", s);

    int i = 0;
    node root = buildTree(s, &i);

    printf("Left View: ");
    int lc = leftView(root);
    printf("\n");

    printf("Right View: ");
    int rc = rightView(root);
    printf("\n");

    printf("Top View (left to right): ");
    int tc = topView(root);
    printf("\n");

    printf("Left Count: %d\n", lc);
    printf("Right Count: %d\n", rc);
    printf("Top Count: %d\n", tc);

    return 0;
}