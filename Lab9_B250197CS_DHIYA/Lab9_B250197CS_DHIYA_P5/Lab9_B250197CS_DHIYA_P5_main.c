#include "Lab9_B250197CS_DHIYA_P5.h"

int main()
{
    struct list s[600];

    int N;
    int f = -1;
    int r = -1;

    scanf("%d",&N);

    char str[100];

    while (1)
    {
        scanf("%s",str);

        if (strcmp(str,"Insert")==0)
        {
            int id;
            char name[51];
            char dep[51];

            scanf("%d %s %s",&id,name,dep);

            Insert(s,&f,&r,N,id,name,dep);
        }
        else if (strcmp(str,"Delete")==0)
        {
            Delete(s,&f,&r,N);
        }
        else if (strcmp(str,"Display_F")==0)
        {
            Display_F(s,f,r,N);
        }
        else if (strcmp(str,"Display_R")==0)
        {
            Display_R(s,f,r,N);
        }
        else if (strcmp(str,"Exit")==0)
        {
            break;
        }
    }

    return 0;
}