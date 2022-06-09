NAME = minishell

LIB_PATH = ./includes/libft/

LIB_NAME = ./includes/libft/libft.a

CC = cc

# gcc -fsanitize=thread флаг для теста потока

CFLAGS = -Wall -Wextra -Werror

RFLAGS = -lreadline -ltermcap -g -L/Users/mmago/.brew/Cellar/readline/8.1.2/lib/ -I/Users/mmago/.brew/Cellar/readline/8.1.2/include

RM = rm -f

#>>>>>>color>>>>>>>

_CYAN	=	\e[0;36m
_END	=	\e[33m

#>>>>>>mes>>>>>>>

READY	=	Minishell is ready
#READYB	=	Checker is ready
SWEPT	=	Directory was cleaned

FILES = src/main.c	src/build_comand.c	src/envp_parser.c	src/b_unset.c	src/envp_to_list.c	src/utils_envp.c
					
OBJS = $(FILES:%.c=%.o)

$(NAME): $(OBJS) $(LIB_NAME)
	$(CC) $(CFLAGS) $(LIB_NAME) $(OBJS) $(RFLAGS) -o $(NAME)
	@printf "${_CYAN}${READY}${_END}\n"

all: $(NAME)

${LIB_NAME}: libft;

libft:
	${MAKE} -C ${LIB_PATH} all

clean:
	$(RM) $(OBJS)
	${MAKE} -C ${LIB_PATH} clean

fclean: clean
	$(RM) $(NAME)
	${MAKE} -C ${LIB_PATH} fclean
	@printf "${_CYAN}${SWEPT}${_END}\n"

.PHONY:all clean fclean re