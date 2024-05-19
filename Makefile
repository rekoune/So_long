CFILES = so_long.c check_map.c check_map_utils.c list_utils.c utils.c get_next_line.c get_next_line_utils.c
OFILES = $(CFILES:.c=.o)
CC = cc 
CFLAGS = -Wall -Wextra -Werror 
FC = -fsanitize=address -g

NAME = so_long 

all : $(NAME)

$(NAME) : $(OFILES) so_long.h
		$(CC) $(CFLAGS) $(FC) $(OFILES) -o $(NAME)
%.o : %.c
	$(CC) $(CFLAGS) $(FC) -c $<  -o $@

clean: 
	rm -rf $(OFILES)

fclean: clean
	rm -rf $(NAME)