# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivotints <ivotints@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/23 13:58:55 by ivotints          #+#    #+#              #
#    Updated: 2024/02/26 17:53:26 by ivotints         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#source
SRCS_DIR	= ./srcs/
SRCS		= 01check_extension.c 02create_map.c 03check_map.c 04check_map.c \
			  05init_player.c 06collect_coins.c 07move_msg.c 04flood_fill.c
OBJS		= ${addprefix ${SRCS_DIR}, ${SRCS:.c=.o}}

#get_next_line
GNL_DIR		= ./get_next_line/
GNL			= get_next_line.c get_next_line_utils.c
GNL_OBJS	= ${addprefix ${GNL_DIR}, ${GNL:.c=.o}}

#libft
LIBFT_DIR	= libft
LIBFT_PATH	= ${LIBFT_DIR}/libft.a

#minilibx
MLX_DIR		= mlx
MLX_PATH	= ${MLX_DIR}/libmlx.a

#compiler
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
MFLAGS	= -ldl -lmlx -L${MLX_DIR} -lm -lXext -lX11 -Imlx ${MLX_PATH}
IFLAGS	= -I ./includes
LFLAGS	= -L ${LIBFT_DIR} -lft

#other
NAME	= so_long
RM		= rm -f

#bonus
BONUS		= so_long_bonus
BONUS_DIR	= ./bonus/
BONUS_SRCS	= #################################################
B_OBJS		= ${addprefix ${BONUS_DIR}, ${BONUS_SRCS:.c=.o}}

#define color codes
RESET	= \033[0m
RED		= \033[31m
GREEN	= \033[32m
YELLOW	= \033[33m
BLUE	= \033[34m
MAGENTA	= \033[35m
CYAN	= \033[36m
WHITE	= \033[37m

all:	${NAME}

$(NAME): $(OBJS) $(GNL_OBJS)
	@make -C ${MLX_DIR}
	@cd $(LIBFT_DIR) && $(MAKE)
	@echo "$(YELLOW)Compiling $@ $(RED)"
	@$(CC) $(CFLAGS) $(OBJS) $(GNL_OBJS) $(SRCS_DIR)main.c $(IFLAGS) $(LFLAGS) -o $(NAME) $(MFLAGS)
	@echo "$(GREEN)[OK COMPILED]$(RESET)"

$(BONUS): $(OBJS) $(B_OBJS)
	@make -C ${MLX_DIR}
	@cd $(LIBFT_DIR) && $(MAKE)
	@echo "$(MAGENTA)Compiling $@ $(RED)
	@$(CC) $(CFLAGS) $(OBJS) $(B_OBJS) $(GNL_OBJS) $(BONUS_DIR)main_bonus.c $(IFLAGS) -o $(BONUS) $(MFLAGS)
	@echo "$(GREEN)[OK COMPILED]$(RESET)"

clean:
		@echo "$(MAGENTA)[Clean]$(RESET)"
		@${RM} ${OBJS}
		@${RM} ${B_OBJS}
		@make -C ${LIBFT_DIR} -f Makefile clean

fclean: clean
		@echo "$(MAGENTA)[FClean]$(RESET)"
		@${RM} ${OBJS} ${NAME}
		@${RM} ${B_OBJS} ${BONUS}

re:		fclean all

.PHONY: all clean fclean re
