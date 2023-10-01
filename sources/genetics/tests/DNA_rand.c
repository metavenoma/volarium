#include "libgene.h"

int	main(void)
{
	int	**DNA = DNA_rand(time(NULL));
	int	y;
	int	x;

	y = -1;
	while (++y < 16)
	{
		x = -1;
		while (++x < 5)
			printf("%-5i", DNA[y][x]);
		printf("\n");
	}
	DNA_free(DNA);
	return (1);
}
