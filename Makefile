CFILES = so_long.c check_map.c check_map_utils.c list_utils.c utils.c get_next_line.c get_next_line_utils.c
OFILES = $(CFILES:.c=.o)
CC = cc 
CFLAGS = -Wall -Wextra -Werror -Wunreachable-code -Ofast
FC = -fsanitize=address -g
LIBMLX = ~/MLX42
LIBS = $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
NAME = so_long 

HEADERS = -I ./include -I $(LIBMLX)/include

all : libmlx $(NAME)

$(NAME) : $(OFILES) so_long.h
		$(CC) $(CFLAGS)  $(OFILES) $(LIBS) $(HEADERS) -o $(NAME)
libmlx : 
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4
%.o : %.c
	$(CC) $(CFLAGS)  -c $<  -o $@ $(HEADERS) && printf "Compiling: $(notdir $<)"

clean: 
	rm -rf $(OFILES)
	@rm -rf $(LIBMLX)/build

fclean: clean
	rm -rf $(NAME)
