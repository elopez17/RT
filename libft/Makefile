# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elopez <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/18 23:40:47 by elopez            #+#    #+#              #
#    Updated: 2017/11/12 19:33:46 by eLopez           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NO_COLOR= \x1b[0m
B_GRY	= \x1b[30;01m
B_RED	= \x1b[31;01m
B_GRN	= \x1b[32;01m
B_YEL	= \x1b[33;01m
B_BLU	= \x1b[34;01m
B_PURP	= \x1b[35;01m
B_TURQ	= \x1b[36;01m
B_WHT	= \x1b[37;01m
GRY		= \x1b[30m
RED		= \x1b[31m
GRN		= \x1b[32m
YEL		= \x1b[33m
BLU		= \x1b[34m
PURP	= \x1b[35m
TURQ	= \x1b[36m
WHT		= \x1b[37m

NAME		= ../libft.a
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g
FILES		= $(shell ls | grep -E ".+\.c")
ODIR		:= obj
OBJ			:= $(addprefix $(ODIR)/,$(FILES:%.c=%.o))

all: $(NAME)

$(NAME): $(OBJ) 
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(GRN)[Library Compilation was Successful!]$(NO_COLOR)"

$(ODIR)/%.o:%.c | $(ODIR)
	@$(CC) $(CFLAGS) -I ../includes -o $@ -c $<

$(ODIR):
	@mkdir $(ODIR)

clean:
	@rm -rf $(ODIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
