#include <stdio.h>
struct fisher
{
    int id;
    char name[100];
    float total_catch;
};
int main()
{
    int n;
    scanf("%d",&n);
    struct fisher f[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&f[i].id);
        scanf("%s",f[i].name);
        scanf("%f",&f[i].total_catch);
        if (f[i].total_catch<0)
        {
            printf("Invalid Input");
            return 0;
        }
    }
    for (int i = 0; i < n-1; i++)
    {
        int max = i;
        for (int j = i+1; j < n; j++)
        {
            if (f[j].total_catch>f[max].total_catch)
            {
                max = j;
            }
        }
        struct fisher temp = f[i];
        f[i] = f[max];
        f[max] = temp;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d %s %.1f\n",f[i].id,f[i].name,f[i].total_catch);
    }
    return 0;
}