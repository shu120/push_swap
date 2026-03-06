# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shukondo <shukondo@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/17 21:32:06 by shukondo          #+#    #+#              #
#    Updated: 2026/03/07 02:07:58 by shukondo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = main.c \
	   operations/swap.c \
	   operations/push.c \
	   operations/rotate.c \
	   operations/reverse_rotate.c \
	   parsing/validate.c \
	   parsing/duplicate.c \
	   parsing/parse_input.c \
	   parsing/error.c \
	   sorting/is_sorted.c \
	   sorting/small_sort.c \
	   sorting/idx_compress.c \
	   sorting/radix_sort.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

test100: $(NAME)
	@ARG="$$(jot 100 1 100 | sort -R | paste -sd ' ' -)"; \
	echo "$$ARG"; \
	./$(NAME) $$ARG | wc -l

test500: $(NAME)
	@ARG="$$(jot 500 1 500 | sort -R | paste -sd ' ' -)"; \
	echo "$$ARG"; \
	./$(NAME) $$ARG | wc -l

check100: $(NAME)
	@ARG="$$(jot 100 1 100 | sort -R | paste -sd ' ' -)"; \
	echo "$$ARG"; \
	./$(NAME) $$ARG | ./checker_Mac $$ARG

check500: $(NAME)
	@ARG="$$(jot 500 1 500 | sort -R | paste -sd ' ' -)"; \
	echo "$$ARG"; \
	./$(NAME) $$ARG | ./checker_Mac $$ARG

.PHONY: all clean fclean re test100 test500 check100 check500
