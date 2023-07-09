NAME        = libftprintf.a
INCLUDE     = .
LIBFT       = libft
CC          = gcc
CFLAGS      = -Wall -Werror -Wextra -I$(INCLUDE) -I$(LIBFT)
RM          = rm -f
AR          = ar rcs

SRC_FILES   = ft_printf.c ft_printf_utils.c ft_print_ptr.c ft_print_unsigned.c ft_print_hex.c

SRC         = $(SRC_FILES)
OBJ         = $(SRC:.c=.o)

###

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBFT)
	@cp $(LIBFT)/libft.a $(NAME)
	@$(AR) $(NAME) $(OBJ)
	@echo "libftprintf.a compiled!"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@$(MAKE) clean -C $(LIBFT)
	@echo "Object files cleaned!"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)/libft.a
	@echo "Executable files cleaned!"

re: fclean all
	@echo "Cleaned and rebuilt everything for libftprintf!"

.PHONY: all clean fclean re
