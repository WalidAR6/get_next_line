#include<stdio.h>
int get_index(char	*str)
{
    int i;

    i = 0;
	if (!str)
		return (0);
	while (*str != 'o')
    {
		str++;
        i++;
    }
	return(i);
}
int main()
{
    char str[] = "hello world";
    printf("%d",get_index(str));
}