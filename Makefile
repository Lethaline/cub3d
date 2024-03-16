# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lethaline <lethaline@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/07 23:14:32 by lolemmen          #+#    #+#              #
#    Updated: 2024/03/15 23:12:54 by lolemmen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:
.PHONY: NAME re all fclean clean

NAME = cub3d

# Compilation

RM = rm -rf
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g

# Directories

SRCSDIR = srcs
INCSDIR = includes
OBJSDIR = objs
TESTDIR = filetest

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
	  cub3d.h \

SRC = \
	  main.c \
	  checks/ft_checks.c \
	  debug/ft_debug.c \
	  debug/ft_debug_cub.c \
	  error/ft_print_error.c \
	  free/ft_exit_program.c \
	  free/ft_free_map_lines.c \
	  free/ft_free_ptr.c \
	  free/ft_free_tab.c \
	  init/ft_init_color.c \
	  init/ft_init_cub.c \
	  init/ft_init_file.c \
	  init/ft_init_map.c \
	  new/ft_color_new.c \
	  new/ft_cub_new.c \
	  new/ft_file_new.c \
	  new/ft_map_new.c \
	  parsing/ft_check_map.c \
	  parsing/ft_check_scene.c \
	  parsing/ft_handle_map.c \
	  parsing/ft_handle_scene.c \
	  parsing/ft_lst_to_tab.c \
	  parsing/ft_parsing.c \
	  utils/ft_access.c \
	  utils/ft_atoi.c \
	  utils/ft_bzero.c \
	  utils/ft_calloc.c \
	  utils/ft_has_delimitor.c \
	  utils/ft_map_add_back.c \
	  utils/ft_map_size.c \
	  utils/ft_memset.c \
	  utils/ft_split.c \
	  utils/ft_strcpy.c \
	  utils/ft_strdup.c \
	  utils/ft_strjoin.c \
	  utils/ft_strlen.c \
	  utils/ft_strncmp.c \
	  utils/ft_tablen.c \
	  utils/get_next_line.c \

TEST = \
	   badcharmap.cub \
	   badcoordf1.cub \
	   badcoordf2.cub \
	   badcoordf3.cub \
	   badcoordf4.cub \
	   badcoordf5.cub \
	   badcoordf6.cub \
	   badcoordf7.cub \
	   badcoordf8.cub \
	   badinputea1.cub \
	   badinputea2.cub \
	   badinputea3.cub \
	   badinputno1.cub \
	   badinputno2.cub \
	   badinputno3.cub \
	   badinputso1.cub \
	   badinputso2.cub \
	   badinputso3.cub \
	   badinputwe1.cub \
	   badinputwe2.cub \
	   badinputwe3.cub \
	   badname \
	   badname2.cuby \
	   badname3.cu \
	   duplicatec.cub \
	   duplicateea.cub \
	   duplicatef.cub \
	   duplicateno.cub \
	   duplicateso.cub \
	   duplicatewe.cub \
	   correct.cub \
	   newlineinmap.cub \

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

TESTFILES = $(addprefix $(TESTDIR)/, $(TEST))

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

test: $(NAME) $(TESTFILES)
	for test in $(TESTFILES) ; do \
		echo '$(LOG_CYAN)' $$test '$(LOG_NOCOLOR)' ; \
		./cub3d $$test ; \
	done
