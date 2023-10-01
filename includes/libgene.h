#ifndef LIBGENE_H
#define LIBGENE_H

# include "stdlib.h"
# include "stdio.h"
# include "time.h"

typedef struct s_organism
{
	int	energy;
	int	health;
	int	hunger;
	int	**DNA;
}	t_organism;

#endif

// DNA

int	**DNA_rand(time_t SEED);
void	DNA_free(int **DNA);
