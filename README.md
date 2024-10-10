# cub3d

gcc -g src/main.c include/cub3d.h lib/libft/libft.a lib/mlx/mlx.h utils/print_err.c src/free.c -o cub ; valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./cub maps/maps/teste.cub 