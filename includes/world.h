#ifndef WORLD_H
# define WORLD_H

# define TRUE 1
# define FALSE 0

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef struct	s_world
{
	int		x;
	int		y;
	int		id;
	int		full;
	int		width;
	int		height;
}	t_world;

#endif
