CC = cc
CFLAGS = -Wall -Wextra -g
SRC = ./src/*.c
OBJ = ./obj/*.o

all:
			$(MAKE) all -C ./ft_printf
			cd ./obj/ ; $(CC) $(CFLAGS) -c ../$(SRC)
			$(CC) $(CFLAGS) $(OBJ) ./ft_printf/libftprintf.a -o program.out -g
			
clean:	
			$(MAKE) clean -C ./ft_printf
			rm -f ./obj/*.o

fclean:	clean
			$(MAKE) fclean -C ./ft_printf
			rm -f program.out

re:	fclean all

.PHONY:	all clean fclean re