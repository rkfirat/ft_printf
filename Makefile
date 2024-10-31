NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c     prt_hexa.c      prt_int.c       prt_ptr.c       prt_str.c       prt_uint.c
OBJS = ft_printf.o     prt_hexa.o      prt_int.o       prt_ptr.o       prt_str.o       prt_uint.o


AR = ar rcs
RM = rm -f

all: $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	$(AR) $(NAME) $(OBJS)

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

re: fclean all