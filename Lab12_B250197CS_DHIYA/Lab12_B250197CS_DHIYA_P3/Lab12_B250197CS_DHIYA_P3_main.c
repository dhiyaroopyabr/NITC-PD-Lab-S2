#include "Lab12_B250197CS_DHIYA_P3.h"
#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    ll no;
    char name[51];
    node root = NULL;
    char type[10];
    while (1)
    {
        scanf("%99s",str);
        if (strcmp(str,"INSERT")==0)
        {
            scanf("%lld",&no);
            scanf(" %50[^\n]",name);
            root = insert(root,no,name);
        }
        else if (strcmp(str,"MAXIMUM")==0)
        {
            node max = maximum(root);
            if (max!=NULL)
            {
                printf("%lld %s\n",max->no,max->name);
            }
            else
            {
                printf("-1\n");
            }
        }
        else if (strcmp(str,"MINIMUM")==0)
        {
            node min = minimum(root);
            if (min!=NULL)
            {
                printf("%lld %s\n",min->no,min->name);
            }
            else
            {
                printf("-1\n");
            }
        }
        else if (strcmp(str,"PREDECESSOR")==0)
        {
            scanf("%lld %s",&no,type);
            node pred = NULL;
            if (strcmp(type,"Ino")==0)
            {
                pred = predecessor(root,no);
            }
            else if (strcmp(type,"Pre")==0)
            {
                node prev = NULL;
                pred = preorderPred(root,no,&prev);
            }
            else if (strcmp(type,"Post")==0)
            {
                node prev = NULL;
                pred = postorderPred(root,no,&prev);
            }
            if (pred != NULL)
                printf("%lld %s\n", pred->no, pred->name);
            else
                printf("-1\n");
        }
        else if (strcmp(str,"SUCCESSOR")==0)
        {
            scanf("%lld %s",&no,type);
            node succ = NULL;
            if (strcmp(type,"Ino")==0)
            {
                succ = successor(root,no);
            }
            else if (strcmp(type,"Pre")==0)
            {
                int found = 0;
                succ = preorderSucc(root,no,&found);
            }
            else if (strcmp(type,"Post")==0)
            {
                int found = 0;
                succ = postorderSucc(root,no,&found);
            }
            if (succ != NULL)
                printf("%lld %s\n", succ->no, succ->name);
            else
                printf("-1\n");
        }
        else if (strcmp(str,"EXIT")==0)
        {
            break;
        }
    }
}