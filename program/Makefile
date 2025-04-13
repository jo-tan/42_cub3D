# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jo-tan <jo-tan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/22 11:10:05 by jo-tan            #+#    #+#              #
#    Updated: 2024/04/13 21:13:05 by jo-tan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= cub3D

CC			= cc
CF			= -Wall -Wextra -Werror -g3 -MMD
INC			= -I ./inc -I $(LIBFT_DIR) -I /usr/local/include
LIB			= -L ./libft -lft -L /usr/local/lib -lmlx -lX11 -lXext -lbsd -lm
LIBFT		= libft/libft.a
LIBFT_DIR	= libft

S_FILES		= src/main.c \
				src/parse_init.c \
				src/parse_cub.c \
				src/parse_check_end.c \
				src/parse_path.c \
				src/parse_rgb.c \
				src/parse_rgb2.c \
				src/parse_check_front.c \
				src/parse_update_map_data.c \
				src/parse_valid_map.c \
				src/parse_valid_path.c \
				src/parse_check_map.c \
				src/parse_txt.c \
				src/parse_tab_to_space.c \
				src/parse_report_err.c \
				src/parse_free.c \
				src/game.c \
				src/game_init.c \
				src/game_color.c \
				src/game_raycast.c \
				src/game_loop.c \
				src/game_move.c \
				src/game_close.c \
				src/game_rot.c
S_DIR		= src
O_DIR		= obj
O_FILES		= $(patsubst $(S_DIR)/%.c,$(O_DIR)/%.o,$(S_FILES))
D_FILES		= $(patsubst $(S_DIR)/%.c,$(O_DIR)/%.d,$(S_FILES))

RM			= rm -rf

all:		$(LIBFT) $(NAME)

$(NAME):	$(O_FILES)
	@$(CC) $(CF) $(INC) -o $@ $^ $(LIB)
	@echo " [ ok ] | cub3D is ready!"

-include $(D_FILES)

$(O_DIR)/%.o: $(S_DIR)/%.c
	@echo "Compiling $<"
	@mkdir -p $(O_DIR) $(D_DIR)
	@$(CC) $(CF) $(INC) -c $< -o $@

$(LIBFT):
	@make --no-print-directory -C $(LIBFT_DIR)
	@echo "libft is ready."

clean:
	@$(RM) $(O_DIR)
	@make --no-print-directory -C libft fclean
	@echo "Objects and dependend files removed."

fclean:	clean
	@$(RM) $(NAME)
	@make --no-print-directory -C libft fclean
	@echo "Binary files removed."

re:		fclean all

.PHONY:	all clean fclean re