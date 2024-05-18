CFILES = so_long.c check_map.c utils.c get_next_line.c get_next_line_utils.c
OFILES = $(CFILES:.c=.o)
CC = cc 
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

NAME = so_long 

all : $(NAME)

$(NAME) : $(OFILES) so_long.h
		$(CC) $(CFLAGS) $(OFILES) -o $(NAME)
%.o : %.c
	$(CC) $(CFLAGS) -c $<  -o $@

clean: 
	rm -rf $(OFILES)

fclean: clean
	rm -rf $(NAME)