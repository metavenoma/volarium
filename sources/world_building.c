#include "../includes/world.h"

int	terminate(char *error_msg, int exit_code, int fd)
{
	size_t	i;

	i = -1;
	if (error_msg)
	{
		while (++i < strlen(error_msg))
			write(fd, &error_msg[i], 1);
	}
	exit(exit_code);
}

void	terminate_world(t_world **world, int height)
{
	int	i;

	i = -1;
	while (++i < height)
	{
		if (!world[i])
			break ;
		free(world[i]);
	}
	free(world);
}

t_world	**init_world(t_world **world, int x, int y)
{
	int	i;
	int	j;
	i = -1;
	while (++i < y)
	{
		j = -1;
		while (++j < x)
		{
			world[i][j].x = i;
			world[i][j].y = j;
			world[i][j].id = 0;
			world[i][j].full = FALSE;
			world[i][j].width = x;
			world[i][j].height = y;
		}
	}
	return (world);
}

t_world	**create_world(int x, int y)
{
	t_world	**world;
	int	i;

	world = (t_world **)malloc(sizeof(t_world) * y);
	if (!world)
		return (NULL);
	i = -1;
	while (++i < x)
	{
		world[i] = (t_world *)malloc(sizeof(t_world) * x);
		if (!world[i])
		{
			terminate_world(world, y);
			return (NULL);
		}
	}
	world = init_world(world, x, y);
	return (world);
}

int	main(int argc, char **argv)
{
	t_world	**world;

	if (argc != 3)
		return (1);
	for (size_t i = 0; i < strlen(argv[1]); i++) {
		if (argv[1][i] < '0' || argv[1][i] > '9')
			terminate("Args must be two integers with Width and Height values", 2, 2);
	}
	for (size_t i = 0; i < strlen(argv[2]); i++) {
		if (argv[1][i] < '0' || argv[2][i] > '9')
			terminate("Args must be two integers with Width and Height values", 2, 2);
	}
	int x = atoi(argv[1]);
	int y = atoi(argv[2]);
	world = create_world(x, y);
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			printf("x: %i | y: %i\n", j, i);
		}
	}
	terminate_world(world, y);
	return (0);
}
