NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = 	core/pipex.c \
		tools/ft_split.c \
		tools/ft_strdup.c \
		tools/ft_strjoin.c \
		tools/ft_strlen.c \
		tools/ft_strstr.c \
		tools/pipex_tools.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
del: fclean

push:
	git add .
	git commit -m "push mandatory part with sad face again :("
	git push

re: fclean all

.PHONY: all clean fclean del tester push  re 