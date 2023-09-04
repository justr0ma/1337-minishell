SRCS =	*.c parssing/*.c parssing/src/*.c execution/tools/*.c execution/builtins/*.c

CC = @cc

readA = -L ~/.brew/opt/readline/lib -I ~/.brew/opt/readline/include -lreadline

readH = -L /Users/halaqoh/Desktop/homebrew/opt/readline/lib -I /Users/halaqoh/Desktop/homebrew/opt/readline/include -lreadline

CFLAGS = -Wall -Wextra -Werror $(readA)

RM = @rm -rf

AR = @ar -rc

NAME = minishell

LIB = libft/libft.a

sani = -fsanitize=address -g 
sanitize = $(sani)   && echo "\x1b[36m \n\t$(sani):\x1b[32m Used 💥\n"

all : $(NAME)

$(NAME) : ${SRCS}
	@cd libft && make
	${CC} ${CFLAGS} $(LIB) $(SRCS) -o $(NAME)
	@echo "\x1b[32m \x1b[1m ✅\tMandatory Compele\n\t\x1b[0mPrograme -\x1b[33m ($(NAME))\n\x1b[0m"

clean :
	@cd libft && make clean
	@echo "\x1b[31m \x1b[1m ✅\tDelete [libft/*.o] \x1b[32mSuccess\n\x1b[0m"

fclean : clean
	@cd libft && make fclean
	${RM} ${NAME}
	@echo "\x1b[31m \x1b[1m ✅\tDelete [$(NAME)] \x1b[32mSuccess\n\x1b[0m"

re : fclean all

#make