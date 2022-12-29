NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = 	main/core/pipex.c \
		main/tools/ft_split.c \
		main/tools/ft_strdup.c \
		main/tools/ft_strjoin.c \
		main/tools/ft_strlen.c \
		main/tools/ft_strstr.c \
		main/tools/pipex_tools.c

BONUS_S = bonus/core/pipex_bonus.c \
		  bonus/tools/pipex_bonus_tools.c bonus/tools/pipex_heredoc.c \
		  bonus/gnl/get_next_line_utils.c bonus/gnl/get_next_line.c \
		  main/tools/ft_split.c \
		  main/tools/ft_strjoin.c \
		  main/tools/ft_strstr.c \
		  main/tools/pipex_tools.c \

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_S:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) 
	$(CC) $(CFLAGS) $(OBJ)  -o $(NAME)

bonus: $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ)  -o $(NAME)

clean: 
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

push:
	git add .
	git commit -m "push"
	git push

re: fclean all

.PHONY: all clean fclean push re 