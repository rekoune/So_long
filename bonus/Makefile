CFILES = so_long_bonus.c check_map_bonus.c check_map_utils_bonus.c list_utils_bonus.c utils_bonus.c move_player_bonus.c move_player_utils_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c
OFILES = $(CFILES:.c=.o)
CC = cc 
CFLAGS = -Wall -Wextra -Werror -Wunreachable-code -Ofast
FC = -fsanitize=address -gf
LIBMLX = ~/MLX42
LIBS = $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
NAME = so_long 



all : libmlx $(NAME)

$(NAME) : $(OFILES) so_long_bonus.h
		$(CC) $(CFLAGS)  $(OFILES) $(LIBS)  -o $(NAME)
libmlx : 
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4
%.o : %.c
	$(CC) $(CFLAGS)  -c $<  -o $@

clean: 
	rm -rf $(OFILES)
	@rm -rf $(LIBMLX)/build

fclean: clean
	rm -rf $(NAME)
