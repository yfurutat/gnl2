SRCS	=	get_next_line.c	\
			get_next_line_utils.c

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror -D BUFFER_SIZE=9999
# CFLAGS	=	-Wall -Wextra -Werror -D BUFFER_SIZE=10000000

NAME	=	get_next_line.a

RM		=	rm -f
AR		=	ar -rcs
OUT		=	a.out
MAIN	=	main.c

$(NAME)	:	$(OBJS)
			$(AR) $(NAME) $(OBJS)

all		:	$(NAME)
out		:	all
			$(CC) $(CFLAGS) $(NAME) $(MAIN) ; time ./$(OUT)

clean	:	
			$(RM) $(OBJS)


fclean	:	clean
			$(RM) $(NAME)

oclean	:	fclean
			$(RM) $(OUT)

re		:	fclean all
ore		:	fclean out

norm	:	
			@norminette get_next_line.h $(SRCS)
normd	:
			@norminette -R CheckDefine get_next_line.h $(SRCS)
normf	:
			@norminette -R CheckForbiddenSourceHeader get_next_line.h $(SRCS)
commit	:	fclean
			git add .
			git commit -m "commit through Makefile"
			git log

.PHONY	:	all out clean fclean oclean re