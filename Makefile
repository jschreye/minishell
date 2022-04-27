# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grubin <grubin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 13:48:52 by grubin            #+#    #+#              #
#    Updated: 2022/04/25 16:09:52 by grubin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc -I $HOME/.brew/Cellar/readline/8.1.2/include
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

AR = ar -rc

SRCS_DIR = ./src \

OBJS_DIR = ./objs
INC_DIR = .
LIBFT_DIR = ./libft
LIBFT = libft.a


SRCS = 	main.c \
		access_path.c \
		utils_quote.c \
		prompt_quote.c \
		chunck.c \
		init_malloc.c \
		utils_chunck.c \
		chunck_bis.c \


OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

vpath %.c $(SRCS_DIR)

RM = rm -f

all : $(NAME)


$(NAME) : $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) -lreadline -o $@ $^ -L$(LIBFT_DIR) -lft

$(OBJS_DIR) :
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o : %.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -o $@ -I $(INC_DIR) -I$(LIBFT_DIR) -c $^

clean :
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(RM) -r $(OBJS_DIR)

fclean : clean
	@$(RM) $(NAME)

re : fclean all