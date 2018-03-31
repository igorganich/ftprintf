NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRCS2 = src/ft_printf.o \
           src/parsers.o \
           src/utils/for_func_wid_spec.o \
           src/utils/for_get_len_nbr.o \
           src/utils/for_get_unsigned.o \
           src/utils/for_nbrlen.o \
           src/utils/for_numberandstr.o \
           src/handlers/cor_func.o \
           src/handlers/for_bin.o \
           src/handlers/for_charswritten.o \
           src/handlers/for_hex_big.o \
           src/handlers/for_hex_small.o \
           src/handlers/for_int.o \
           src/handlers/for_null.o \
           src/handlers/for_pers.o \
           src/handlers/for_string.o \
           src/handlers/for_wchar.o \
           src/handlers/for_all_unsigned.o \
           src/handlers/for_char.o \
           src/handlers/for_float.o \
           src/handlers/for_long.o \
           src/handlers/for_octal.o \
           src/handlers/for_pointer.o \
           src/handlers/for_unsigned.o \
           src/handlers/for_wstring.o 

SRCSLIB =	libft/ft_putstr.o \
                libft/ft_memset.o \
                libft/ft_strchr.o \
		libft/ft_strlen.o \
		libft/ft_putnstr_fd.o \
		libft/ft_bzero.o \
                libft/ft_putchar_fd.o \
                libft/ft_isdigit.o \
                libft/ft_tolower.o \
                libft/ft_putnwstr.o \
                libft/ft_memalloc.o \
                libft/ft_max_of_two.o \
                libft/ft_putchar.o 

SRCS = src/ft_printf.c \
	   src/parsers.c \
	   src/utils/for_func_wid_spec.c \
	   src/utils/for_get_len_nbr.c \
	   src/utils/for_get_unsigned.c \
	   src/utils/for_nbrlen.c \
	   src/utils/for_numberandstr.c \
	   src/handlers/cor_func.c \
	   src/handlers/for_bin.c \
	   src/handlers/for_charswritten.c \
	   src/handlers/for_hex_big.c \
	   src/handlers/for_hex_small.c \
	   src/handlers/for_int.c \
	   src/handlers/for_null.c \
	   src/handlers/for_pers.c \
	   src/handlers/for_string.c \
	   src/handlers/for_wchar.c \
	   src/handlers/for_all_unsigned.c \
	   src/handlers/for_char.c \
	   src/handlers/for_float.c \
	   src/handlers/for_long.c \
	   src/handlers/for_octal.c \
	   src/handlers/for_pointer.c \
	   src/handlers/for_unsigned.c \
	   src/handlers/for_wstring.c

OBJ=$(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
#	make -C libft/
#	gcc $(FLAGS) $(NAME) $(SRCS)  -I /bin/ -L./libft -lft
	make -C libft/
	gcc -c $(FLAGS) $(SRCS)
# $(SRCSLIB) -I /bin/ -L./libft -lft
	ar rc libftprintf.a $(SRCS2) $(SRCSLIB)
	ranlib libftprintf.a
	echo "done" libftprintf.a

clean:
	make -C libft/ clean
	/bin/rm -f $(SRCS2)
	/bin/rm -f *.o

fclean: clean
	rm -f libft/libft.a
	/bin/rm -f $(NAME)


re: fclean all

.PHONY: all clean fclean re norm
