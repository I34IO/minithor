NAME = libft.a

SRCS = ft_atoi.c\
	   ft_atol.c\
       ft_itoa.c\
       ft_split.c\
       ft_bzero.c\
       ft_calloc.c\
       ft_strlen.c\
       ft_memset.c\
       ft_memcpy.c\
       ft_memchr.c\
       ft_memcmp.c\
       ft_strchr.c\
       ft_strdup.c\
       ft_substr.c\
	   ft_strcmp.c\
       ft_strspn.c\
       ft_memmove.c\
       ft_isalpha.c\
       ft_isdigit.c\
       ft_isascii.c\
       ft_isalnum.c\
       ft_isprint.c\
       ft_toupper.c\
       ft_tolower.c\
       ft_strrchr.c\
       ft_strncmp.c\
       ft_strnstr.c\
       ft_strjoin.c\
       ft_strtrim.c\
       ft_strmapi.c\
       ft_strlcpy.c\
       ft_strlcat.c\
       ft_striteri.c\
       ft_putstr_fd.c\
       ft_putnbr_fd.c\
       ft_putchar_fd.c\
       ft_putendl_fd.c\
	   ft_count_line_split.c\

OBJS =          ${SRCS:.c=.o}

CFLAGS =        -Wall -Wextra -Werror

all:            ${NAME}

$(NAME):
	@$(CC) $(CFLAGS) -c $(SRCS)
	@ar -rc $(NAME) $(OBJS)
	@echo "Compiled $(NAME) & .o."


.c.o:
	cc ${CF} -c $^ -include ${HEADER}

clean:
	@rm -f $(OBJS_BONUS) $(OBJS) 
	@echo "Deleted .o files."

fclean: clean
	@rm -f $(NAME)
	@echo "Deleted $(NAME)."

re:             fclean all

.PHONY:         all clean fclean re