# Common sources (shared between manda and bonus)
COMMON_SRCS	:=	common/parsing/parse_color.c \
				common/parsing/parse_error.c \
				common/parsing/parse_utils.c \
				common/parsing/parse_file.c \
				common/gameplay/player.c

# Mandatory sources
MANDA_SRCS	:=	manda/display/load_textures.c \
				manda/display/drawing_utils.c \
				manda/display/drawing.c \
				manda/display/rays.c \
				manda/display/mlx.c \
				manda/parsing/parse_texture.c \
				manda/parsing/parse_map.c \
				manda/gameplay/movements.c \
				manda/gameplay/keys.c \
				manda/init/init_data.c \
				manda/main.c

# Bonus sources
BONUS_SRCS	:=	bonus/display/rotate_handler.c \
				bonus/display/drawing_utils.c \
				bonus/display/load_textures.c \
				bonus/display/ft_bufcpy.c \
				bonus/display/drawing.c \
				bonus/display/rays.c \
				bonus/display/mlx.c \
				bonus/gameplay/handle_change.c \
				bonus/gameplay/keys_dwn.c \
				bonus/gameplay/keys_up.c \
				bonus/gameplay/movements.c \
				bonus/gameplay/mouse.c \
				bonus/gameplay/keys.c \
				bonus/menus/settings_keybind_hooks.c \
				bonus/menus/key_bind_display.c \
				bonus/menus/settings_keybind.c \
				bonus/menus/mouse_menu.c \
				bonus/menus/ft_fsog.c \
				bonus/menus/keybind.c \
				bonus/menus/menu.c \
				bonus/parsing/p_texture_bonus.c \
				bonus/parsing/p_door_bonus.c \
				bonus/parsing/p_map_bonus.c \
				bonus/init/i_data_bonus.c \
				bonus/main.c

# Final source list depending on target
ifeq ($(BONUS), 1)
	SRCS	:= $(COMMON_SRCS) $(BONUS_SRCS)
else
	SRCS	:= $(COMMON_SRCS) $(MANDA_SRCS)
endif
