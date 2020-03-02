#include <stdlib.h>
#include <unistd.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

int main(int argc, char  **argv)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(j < ft_strlen(argv[1]))
	{
		if(argv[1][j] == argv[2][i])
		{
			write(1, &argv[1][j], 1);
			j++;
			i = 0;
			break;
		}
		else
			i++;
	}
}

