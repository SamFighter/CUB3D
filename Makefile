N_NAME		= cub3d

# **************************************************************************** #
#								    										   #
#				=======>		INGREDIENTS			<=======		   		   #
#																			   #
# **************************************************************************** #

LIBFT 		= ./libft/libft.a


MANDATORY	= 		main.c 									\
					srcs/init/init_colors.c					\
					srcs/init/init_data.c					\
					srcs/init/init_mlx.c					\
					srcs/init/init_player.c					\
					srcs/init/init_screen.c					\
					srcs/init/init_textures.c				\
					srcs/parsing/parse_color.c				\
					srcs/parsing/parse_error.c				\
					srcs/parsing/parse_file.c				\
					srcs/parsing/parse_texture.c			\
					srcs/parsing/parse_map.c				\
					srcs/parsing/parse_utils.c				\

N_OBJS		=	$(MANDATORY:%.c=.build/%.o)
DEPS		=	$(N_OBJS:%.o=%.d)

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g
CPPFLAGS	=	-MP	-MMD -Iheaders									\
				-Ilibft/headers										\
				-Ilibft

LDFLAGS		=	-Llibft -lft

# **************************************************************************** #
#								    										   #
#			    	=======>		TOOLS			<=======		   		   #
#																			   #
# **************************************************************************** #

MAKEFLAGS	+=	--silent --no-print-directory

# **************************************************************************** #
#								    										   #
#			    	=======>		RECIPES			<=======		   		   #
#																			   #
# **************************************************************************** #

all:	$(N_NAME)

$(N_NAME): $(LIBFT) $(N_OBJS)
		$(CC) $(CFLAGS) $(N_OBJS) $(LDFLAGS) -o $(N_NAME)
		@printf "$(L__PUR)CREATED$(OFF) $(LB_CYA)OBJS$(_RESET) $(L__CYA)in ~/.build$(OFF)\n"
		@printf "$(L__PUR)CREATED$(OFF) $(L__CYA)$(N_NAME)$(OFF)\n"

$(LIBFT):
		$(MAKE) -C libft

lre:
		@printf "$(LB_PUR)RE-MAKING LIBFT$(OFF)\n"
		$(MAKE) -C libft re

.build/%.o: %.c
		mkdir -p $(@D)
		$(CC) $(CFLAGS) -c $(CPPFLAGS) $< -o $@

-include $(DEPS)

lclean:
		@printf "$(LB_PUR)EXTERMINATE:$(OFF)\n"
		$(MAKE) -C libft clean
		@printf "$(L__CYA)	~/libft/.build$(OFF)\n"

clean:
		@printf "$(LB_PUR)EXTERMINATE:$(OFF)\n"
		$(MAKE) -C libft clean
		@printf "$(L__CYA)	~/libft/.build$(OFF)\n"
		@printf "$(L__CYA)	~/.build$(OFF)\n"
		rm -rf .build

fclean:
		@printf "$(LB_PUR)EXTERMINATE:$(OFF)\n"
		@printf "$(L__CYA)	~/libft/.build$(OFF)\n"
		$(MAKE) -C libft fclean
		@printf "$(L__CYA)	~/.build$(OFF)\n"
		@printf "$(L__CYA)	~/$(N_NAME)$(OFF)\n"
		rm -rf $(N_NAME)

re:
		@printf "$(_B_RED)RE-STARTED FROM SCRATCH$(OFF)$(_RESET)\n"
		$(MAKE) fclean
		$(MAKE) all

.PHONY: all clean fclean re lre
