NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEPS = ft_printf.h

SRC = ft_putnbr.c ft_printf_hex.c ft_printf_ptr.c ft_printf_unsi.c ft_printf.c ft_printfunctions.c\

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)


all: $(NAME)

clean:
	rm -f *.o;

fclean: clean
	rm -f *.a;

re: fclean $(NAME)