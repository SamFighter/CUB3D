# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bcausseq <bcausseq@42angouleme.fr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/17 01:17:51 by bcausseq          #+#    #+#              #
#    Updated: 2026/01/13 17:37:22 by bcausseq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC 			= cc

CFLAGS		= -Wall -Wextra -Werror -g
#CFLAGS		= -Wall -Wextra -Werror=vla -g -O0 -fno-builtin -mno-omit-leaf-frame-pointer -fno-omit-frame-pointer -fsanitize=address,pointer-compare,pointer-subtract,leak,undefined,shift,shift-exponent,shift-base,integer-divide-by-zero,unreachable,vla-bound,null,signed-integer-overflow,bounds,alignment,float-divide-by-zero,float-cast-overflow,nonnull-attribute,returns-nonnull-attribute,bool,enum,pointer-overflow,builtin -fsanitize-address-use-after-scope

NAME		= cub

LIBFT		= ./libft

LIBFT_LIB	= $(LIBFT)/libft.a

HEADER		= includes

MLX_PATH	= ./MLX
MLX_INC		= $(MLX_PATH)/includes
MLX			= $(MLX_PATH)/libmlx.so

SRCS		= srcs/display/drawing.c\
			srcs/display/drawing_utils.c\
			srcs/display/load_textures.c\
			srcs/init/init_colors.c\
			srcs/init/init_data.c\
			srcs/init/init_textures.c\
			srcs/gameplay/keys.c\
			main.c\
			srcs/display/mlx.c\
			srcs/gameplay/movements.c\
			srcs/parse/parse_color.c\
			srcs/parse/parse_error.c\
			srcs/parse/parse_file.c\
			srcs/parse/parse_map.c\
			srcs/parse/parse_texture.c\
			srcs/parse/parse_utils.c\
			srcs/gameplay/player.c\
			srcs/display/rays.c

OBJ_DIR		= build

OBJ			= $(SRCS:.c=.o)

OBJ			:= $(addprefix $(OBJ_DIR)/manda/,$(OBJ))

# Colors
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
PURPLE = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m
BOLD = \033[1m
RESET = \033[0m

all:					$(NAME)

$(MLX_PATH):
	@if [ ! -d "$(MLX_PATH)" ]; then \
		git clone https://github.com/Seekrs/MacroLibX $(MLX_PATH); \
	fi

$(NAME):				$(OBJ) | $(MLX_PATH)
	@make --no-print-directory -C $(LIBFT)
	@make --no-print-directory -C $(MLX_PATH) -j
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBFT_LIB) $(MLX) -lSDL2 -lm

$(OBJ_DIR)/manda/%.o:	%.c | $(MLX_PATH)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I$(LIBFT) -I$(HEADER) -I$(MLX_INC) -c $< -o $@

clean:
	@echo "$(YELLOW)🧹 Cleaning object files...$(RESET)"
	@make --no-print-directory -C $(LIBFT) clean
	@make --no-print-directory -C $(MLX_PATH) clean
	@rm -f $(OBJ)
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN)✨ Clean completed!$(RESET)"

fclean:					clean
	@echo "$(YELLOW)🗑️  Full clean in progress...$(RESET)"
	@make --no-print-directory -C $(LIBFT) fclean
	#@make --no-print-directory -C $(MLX_PATH) fclean
	@rm -f $(NAME)
	@echo "$(GREEN)💀 Everything purged from Hell!$(RESET)"

re:						fclean all

.PHONY: all clean fclean re
