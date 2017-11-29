CFLAGS = -Wall -Wextra -Werror -I./includes
CC = gcc

NAME = libftprintf.a
LIB = libft
DEP = ft_bzero.c ft_isdigit.c ft_memalloc.c ft_putnbrbase.c \
	  ft_putstr.c ft_putchar.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_putwchar.c ft_putnbr.c ft_strdup.c \
		ft_atoi.c ft_minmax.c ft_memset.c ft_itoa_base.c \
	  ft_strchr.c ft_strlen.c ft_tolower.c ft_wstrlen.c

SRC = ft_printf.c utils.c parser.c handler.c \
	  handle_str.c handle_wstr.c handle_number.c handle_spec.c \
	  ft_printu.c ft_nbrlen.c

SRCDIR = src
OUTDIR = out

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
DEPOBJ = $(addprefix $(LIB)/, $(DEP:.c=.o))
OBJ = $(addprefix $(OUTDIR)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): mkeout $(OBJ)
	@(cd $(LIB) && $(MAKE))
	@ar rc $(NAME) $(OBJ) $(DEPOBJ)
	@ranlib $(NAME)

$(OUTDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) -o $@ -c $? $(CFLAGS) -I./libft

mkeout:
	@mkdir -p $(OUTDIR)

clean:
	@(cd $(LIB) && $(MAKE) $@)
	@rm -f $(OBJ)
	@rm -rf $(OUTDIR)

fclean: clean
	@(cd $(LIB) && $(MAKE) $@)
	@rm -f $(NAME)

.PHONY: clean fclean re

re: fclean all
