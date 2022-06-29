NAME = minishell

CC = gcc

export CFLAGS = -Wextra -Werror -Wall
LDFLAGS = -Llibft -lreadline -L$(HOME)/.brew/Cellar/readline/8.1.2/lib

AR = ar -rc

SRCS_DIR = ./src
OBJS_DIR = ./objs
INC_DIRS = -Ilibft -I$(HOME)/.brew/Cellar/readline/8.1.2/include
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS =  main.c \
        main_utils.c \
        utils_quote.c \
        chunck.c \
        init_data.c \
        utils_chunck.c \
        chunck_bis.c \
        init_cmd.c \
        chunk_quote.c \
        exec_cmd.c \
        dollar.c \
        execve.c \
        signal.c \
        dollar_utils.c \
        check_builtins.c \
        builtin_cd.c \
        builtin_cd_utils.c \
        builtin_env.c \
        builtin_echo.c \
        builtin_unset.c \
        builtin_pwd.c \
        builtin_exit.c \
        builtin_export.c \
        builtin_export_utils.c \
        free.c \
        check_in.c \
        stdin_out.c \
        utils_redir.c \
        exec_redir.c \
        check_file_out.c \
        error_redir.c \
        exec_cmd_utils.c \
        check_cmd.c \

OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

vpath %.c $(SRCS_DIR)

RM = rm -f

.PHONY: all re clean fclean debug

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(INC_DIRS) -o $(NAME) $(OBJS) $(LIBFT) $(LDFLAGS)

$(LIBFT) :
	$(MAKE) -C $(LIBFT_DIR)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o : %.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INC_DIRS) -o $@ -c $^

debug: CFLAGS += -g3 -fsanitize=address -fno-omit-frame-pointer
debug: $(LIBFT) $(OBJS) $(NAME)

valgrind: CFLAGS += -g3
valgrind: $(LIBFT) $(OBJS) $(NAME)

clean :
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) -r $(OBJS_DIR)

fclean : clean
	$(RM) $(NAME)

re : fclean all