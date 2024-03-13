# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/07 23:14:32 by lolemmen          #+#    #+#              #
#    Updated: 2024/03/13 15:53:24 by lolemmen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:
.PHONY: NAME re all fclean clean

NAME = cub3d

# Compilation

RM = rm -rf
CC = gcc
CFLAGS = -Wall -Werror -Wextra

# Directories

SRCSDIR = srcs
INCSDIR = includes
OBJSDIR = objs

OS = $(shell uname)
ifeq ($(OS), Linux)
	OSDIR := minilibx/minilinux
else
	OSDIR := minilibx/minimac
	LINKS := -framework OpenGL -framework AppKit
endif
MLXDIR = $(OSDIR)

# Sources

INC = \

SRC = \

# **************************************************************************** #

# Special Chars

LOG_CLEAR = \033[2K
LOG_UP = \033[A
LOG_NOCOLOR = \033[0m
LOG_BLACK = \033[1;30m
LOG_RED = \033[1;31m
LOG_GREEN = \033[1;32m
LOG_YELLOW = \033[1;33m
LOG_BLUE = \033[1;34m
LOG_VIOLET = \033[1;35m
LOG_CYAN = \033[1;36m
LOG_WHITE = \033[1;37m

# **************************************************************************** #

SRCS = $(addprefix $(SRCSDIR)/, $(SRC))
OBJS = $(addprefix $(OBJSDIR)/, $(addsuffix .o, $(basename $(SRC))))
OBJS_DIR = $(sort $(dir $(OBJS)))

INCS_DIR = $(addsuffix /, $(INCSDIR))
INCS = $(addprefix -I , $(INCS_DIR))

MLX_INC = -I $(MLXDIR)
MLX_LIB = $(addprefix $(MLXDIR)/,libmlx.a)
MLX_LINK = -L $(MLXDIR) -l mlx $(LINKS)

all : $(NAME) $(MLX_LIB)

$(NAME) : mlx $(OBJS)
	echo "$(LOG_CLEAR)$(NAME)... $(LOG_CYAN)assembling... $(LOG_NOCOLOR)$(LOG_UP)"
	$(CC) $(OBJS) $(MLX_LINK) -lm -o $(NAME)
	echo "$(LOG_CLEAR)$(NAME)... $(LOG_GREEN)compiled $(LOG_GREEN)✓$(LOG_NOCOLOR)"

mlx :
	@make -C $(MLXDIR)

clean :
	$(RM) $(OBJS_DIR)
	$(RM) $(OBJSDIR)
	make -C $(MLXDIR) clean

re : fclean all

fclean : clean
	$(RM) $(NAME)

$(OBJSDIR)/%.o: $(SRCSDIR)/%.c
	mkdir -p $(OBJSDIR) $(OBJS_DIR)
	echo "$(LOG_CLEAR)$(NAME)... $(LOG_YELLOW)$<$(LOG_NOCOLOR)$(LOG_UP)"
	$(CC) -c -o $@ $< $(MLX_INC) $(INCS) $(FLAGS)
