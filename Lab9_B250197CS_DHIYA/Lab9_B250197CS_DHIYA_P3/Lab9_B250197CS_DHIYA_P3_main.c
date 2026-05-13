#include "Lab9_B250197CS_DHIYA_P3.h"

int main()
{
    node head = NULL;
    int n;
    int top = -1;
    char s[100];
    scanf("%d",&n);
    while (1)
    {
        scanf("%s",s);

        if (strcmp(s,"Push")==0)
        {
            push(&head,&top,n);
        }
        else if (strcmp(s,"Pop")==0)
        {
            pop(&head,&top);
        }
        else if (strcmp(s,"Display")==0)
        {
            display(head);
        }
        else if (strcmp(s,"Exit")==0)
        {
            break;
        }
    }
    return 0;
}