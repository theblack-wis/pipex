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

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)

push:
	git add .
	git commit -m "push"
	git push

re: fclean all

.PHONY: all clean fclean push re 