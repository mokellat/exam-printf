#include <stdlib.h>
#include <unistd.h>

int        ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

int main()
{
	int i;
	int j;
	char **argv;

	argv[0] = "ali";
	argv[1] = "ali";
	i = 0;
	j = 0;
	while(j < ft_strlen(argv[0]))
	{
		if(argv[0][j] == argv[1][i])
		{
			write(1, &argv[0][j], 1);
			j++;
			i = 0;
			break;
		}
		else
			i++;
	}
}
