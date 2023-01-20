SRCS_	=	get_next_line	\
			get_next_line_utils

SRCS	=	$(addsuffix .c, $(SRCS_))

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror -D BUFFER_SIZE=9999
# CFLAGS	=	-Wall -Wextra -Werror -D BUFFER_SIZE=10000000

NAME	=	get_next_line.a

RM		=	rm -f
AR		=	ar -rcs
OUT		=	a.out
MAIN	=	main.c
HFILE	=	get_next_line.h

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
ore		:	oclean out

norm	:	
			@norminette $(HFILE) $(SRCS)
normd	:
			@norminette -R CheckDefine $(HFILE) $(SRCS)
normf	:
			@norminette -R CheckForbiddenSourceHeader $(HFILE) $(SRCS)
norma	:	norm normd normf

commit	:	fclean
			git add $(SRCS) $(HFILE)
			git commit -m "commit through Makefile"
			git log

.PHONY	:	all out clean fclean oclean re