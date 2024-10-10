# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: migupere <migupere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/01 18:01:36 by crocha-s          #+#    #+#              #
#    Updated: 2024/10/10 14:30:14 by migupere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nome do programa
NAME = cub3d

# Compilador e flags
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror

# Diretórios
SRC_DIR = src
INCLUDE_DIR = include
UTILS_DIR = utils
LIBFT_DIR = lib/libft
MLX_DIR = lib/mlx

# Arquivos de origem (SRC)
SRC_FILES = $(SRC_DIR)/main.c \
			$(SRC_DIR)/check_and_parse.c \
			$(SRC_DIR)/check_tex_path.c \
			$(SRC_DIR)/parse_map_matrix.c \
			$(SRC_DIR)/convert_data_map.c \
			$(SRC_DIR)/flood_fill.c  \
			$(SRC_DIR)/free.c \
			$(SRC_DIR)/keys.c \
			$(SRC_DIR)/graphics/draw_utils.c \
			$(SRC_DIR)/graphics/draw_walls.c \
			$(SRC_DIR)/graphics/init_mlx_text.c \
			$(SRC_DIR)/graphics/raycasting.c \
			$(SRC_DIR)/graphics/movement.c \
			$(SRC_DIR)/graphics/vector.c \
			$(SRC_DIR)/graphics/utils.c \
			

UTILS_FILES = $(UTILS_DIR)/print_err.c

# Arquivos de bibliotecas
LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a  # Alterado para o arquivo correto da lib MLX

# Todos os arquivos fontes
ALL_SRC = $(SRC_FILES) $(UTILS_FILES)

# Gerar os nomes dos arquivos .o a partir dos .c
OBJ_FILES = $(ALL_SRC:.c=.o)

# Instrução principal para compilar o projeto
all: $(NAME)

# Regra de compilação do executável
$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -I$(MLX_DIR) $(OBJ_FILES) $(LIBFT) -L$(MLX_DIR) -lmlx -L/usr/X11/lib -lX11 -lXext -lm -o $(NAME)

# Regra para compilar arquivos .c em .o
%.o: %.c $(INCLUDE_DIR)/cub3d.h
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Limpeza dos arquivos objetos (.o)
clean:
	rm -f $(OBJ_FILES)

# Limpeza completa, removendo também o executável
fclean: clean
	rm -f $(NAME)

# Recompilar tudo
re: fclean all

# Dependências para garantir a correta compilação
$(UTILS_DIR)/print_err.o: $(UTILS_DIR)/print_err.c $(INCLUDE_DIR)/cub3d.h
$(SRC_DIR)/main2.o: $(SRC_DIR)/main2.c $(INCLUDE_DIR)/cub3d.h
