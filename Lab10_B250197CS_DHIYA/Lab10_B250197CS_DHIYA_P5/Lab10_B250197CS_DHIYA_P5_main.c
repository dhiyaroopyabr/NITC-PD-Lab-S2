#include <stdio.h>
#include <string.h>
#include "Lab10_B250197CS_DHIYA_P5.h"

int main()
{
    char ch;
    while (1)
    {
        scanf(" %c",&ch);
        if (ch=='a')
        {
            char s[1000];
            scanf("%s",s);
            int i = 0;
            node root = buildTree(s,&i);
            printf("Postfix Expression: ");
            postorder(root);
            printf("\n");
        }
        else if (ch=='b')
        {
            char s[1000];
            scanf("%s",s);
            printf("Postfix Evaluation Result: %d\n", evalPostfix(s));
        }
        else if (ch=='c')
        {
            char s[1000];
            scanf("%s",s);
            printf("Prefix Evaluation Result: %d\n", evalPrefix(s));
        }
        else if (ch=='e')
        {
            char in[1000], post[1000];
            scanf("%s %s",in,post);
            int i = strlen(post)-1;
            node root = buildFromInPost(in,post,0,strlen(in)-1,&i);
            printf("Prefix Expression: ");
            preorder(root);
            printf("\n");
        }
        else if (ch=='f')
        {
            char in[1000], pre[1000];
            scanf("%s %s",in,pre);
            int i = 0;
            node root = buildFromInPre(in,pre,0,strlen(in)-1,&i);
            printf("Postfix Expression: ");
            postorder(root);
            printf("\n");
        }
        else if (ch=='g')
        {
            break;
        }
    }
    return 0;
}