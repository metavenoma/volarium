#include "libgene.h"

int	**DNA_rand(time_t SEED)
{
	int	**new_DNA;
	int	y;
	int	x;

	new_DNA = (int **)calloc(16, sizeof(int *));
	if (!new_DNA)
		return (NULL);
	y = -1;
	srand(SEED);
	while (++y < 16)
	{
		new_DNA[y] = (int *)calloc(5, sizeof(int));
		if (!new_DNA[y])
		{
			DNA_free(new_DNA);
			return (NULL);
		}
		x = -1;
		while (++x < 5)
		{
			new_DNA[y][x] = rand() % 16; 
		}
	}
	return (new_DNA);
}

void	DNA_free(int **DNA)
{
	int	y;

	if (!DNA)
		return ;
	y = -1;
	while (++y < 16)
	{
		if (!DNA[y])
			break;
		free(DNA[y]);
	}
	free(DNA);
}

