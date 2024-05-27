CFILES = mandatory/so_long.c  mandatory/check_map.c  mandatory/check_map_utils.c  mandatory/list_utils.c\
		mandatory/utils.c  mandatory/utils_2.c  mandatory/move_player.c  mandatory/move_player_utils.c\
		mandatory/get_next_line.c  mandatory/get_next_line_utils.c
BFILES = bonus/so_long_bonus.c bonus/check_map_bonus.c bonus/check_map_utils_bonus.c bonus/list_utils_bonus.c\
		bonus/utils_bonus.c bonus/utils_2_bonus.c bonus/move_player_bonus.c bonus/move_player_utils_bonus.c\
		bonus/get_next_line_bonus.c bonus/get_next_line_utils_bonus.c bonus/animation.c

BOFILES = $(BFILES:.c=.o)
OFILES = $(CFILES:.c=.o)

CC = cc 
CFLAGS = -Wall -Wextra -Werror -Wunreachable-code -Ofast

LIBMLX = ~/MLX42
LIBS = $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

NAME = so_long 
BNAME = so_long_bonus

all : libmlx $(NAME)

bonus: libmlx $(BNAME)

$(NAME) : $(OFILES) mandatory/so_long.h
		$(CC) $(CFLAGS)  $(OFILES) $(LIBS)  -o $(NAME)

$(BNAME) : $(BOFILES) bonus/so_long_bonus.h
		$(CC) $(CFLAGS)  $(BOFILES) $(LIBS)  -o $(BNAME)

libmlx : 
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o : %.c
	$(CC) $(CFLAGS)  -c $<  -o $@

clean: 
	rm -rf $(OFILES)
	rm -rf $(BOFILES)
	@rm -rf $(LIBMLX)/build

fclean: clean
	rm -rf $(NAME) $(BNAME)

re: fclean all