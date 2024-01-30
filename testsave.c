/*

#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	fd = open("text.txt", O_RDONLY);
	int	i = 1;
	char	*str;

	while (i < 5)
	{
		str = get_next_line(fd);
		printf("%d : %s", i, str);
		if (str == NULL)
			printf("\n");
		free(str);
		i++;
	}
	return (0);
}*/
