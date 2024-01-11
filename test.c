#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;
	if (argc != 2)
		return (2);
	parse(&data, argv[1]);
	for (int i = 0; data.map[i]; i++)
		printf("%s", data.map[i]);
	validity(&data);
	printf("Floor color:: %s\n", data.f_color);
}
