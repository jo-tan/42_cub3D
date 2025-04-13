NAME		= libft.a

SRCS		= ft_isspace.c \
			ft_isdigit.c \
			ft_itoa.c \
			ft_atoi.c \
			ft_strlen.c \
			ft_strchr.c \
			ft_strncmp.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_strdup.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_memcpy.c \
			ft_strndup.c \
			ft_strjoin.c \
			ft_split.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_dlst_init.c \
			ft_dlst_lstsize.c \
			ft_dlst_addlast.c \
			ft_dlst_deleteone.c \
			ft_dlst_tolastone.c \
			ft_dlst_freelst.c \
			ft_dlst_printlst.c \
			get_next_line_utils.c \
			get_next_line.c

OBJS		= ${SRCS:.c=.o}

B_OBJS		= ${B_SRCS:.c=.o}

CC			= cc
RM			= rm -f
AR			= ar rc
RN			= ranlib

CFLAGS		= -Wall -Wextra -Werror

.c.o:
			@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:		$(NAME)

$(NAME):	${OBJS}
			@${AR} ${NAME} ${OBJS}
			@${RN} ${NAME}

clean:
			@${RM} ${OBJS} ${B_OBJS}

fclean:		clean
			@${RM} $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus
