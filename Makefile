NAME = so_long

CC = gcc

CFLAGS   = -Wall -Wextra -Werror

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

RM = rm -f

SRC = 	mandatory/file_check.c\
		mandatory/fill_map.c\
		mandatory/map_check.c\
		mandatory/map.c\
		mandatory/moves.c\
		mandatory/so_long.c\
		mandatory/utils.c\
		mandatory/valid_path.c\
		mandatory/win_check.c\
		gnl/get_next_line.c\
		gnl/get_next_line_utils.c\

SRC_B = bon/animation_bonus.c\
		bon/coin_ani_bonus.c\
		bon/ene_ani_bonus.c\
		bon/file_check_bonus.c\
		bon/fill_map_bonus.c\
		bon/ft_itoa_bonus.c\
		bon/map_bonus.c\
		bon/map_check_bonus.c\
		bon/moves_bonus.c\
		bon/so_long_bonus.c\
		bon/utils_bonus.c\
		bon/valid_path_bonus.c\
		bon/win_check_bonus.c\
		bon/get_next_line.c\
		bon/get_next_line_utils.c\
		bon/creat_list_bonus.c\

PRINTF = printf/

$(NAME) :
	make -C printf
	@$(CC) $(CFLAGS) $(MLXFLAGS) $(SRC) printf/libftprintf.a -o $(NAME)

bonus: 
	make -C printf
	@$(CC) $(CFLAGS) $(MLXFLAGS) $(SRC_B) printf/libftprintf.a  -o $(NAME)_bonus
all : $(NAME)

clean :
	make clean -C printf
	rm -f *.o

fclean : clean
	make fclean -C printf
	rm -f ${NAME}
	rm -f ${NAME}_bonus

re : fclean $(NAME)

.PHONY: all clean fclean re bonus so_long so_long_bonus