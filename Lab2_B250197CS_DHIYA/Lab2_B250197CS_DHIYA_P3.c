#include <stdio.h>
#include <string.h>
int search(char *s, char c)
{
    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        if (s[i]==c)
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    char s[100];
    scanf("%s",s);
    char c;
    scanf(" %c",&c);
    if (search(s,c))
    printf("YES\n");
    else
    printf("NO\n");
}