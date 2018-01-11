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
CC		= gcc
CFLAGS	= -Wall -Wextra -g
SRC		= $(shell ls src | grep -E ".+\.c")
ODIR	:= obj
OBJ		:= $(addprefix $(ODIR)/,$(SRC:%.c=%.o))
INC		= includes
LIB		= libft.a
EX		= RT

all: $(LIB) $(EX)

$(EX): $(OBJ)
	@make -C minilibx/
	@echo "$(RED)  libmlx.a$(GRN) Successfully Created.$(NO_COLOR)"
	@$(CC) $(CFLAGS) -I $(INC) -I ./minilibx -o $(EX) $(OBJ) -L. -lft -L minilibx -lmlx -framework OpenGL -framework AppKit
	@echo "$(RED)  ./RT$(GRN) Successfully Created.$(NO_COLOR)"

$(ODIR)/%.o:src/%.c | $(ODIR)
	@$(CC) $(CFLAGS) -I $(INC) -I minilibx -o $@ -c $<

$(ODIR):
	@mkdir $(ODIR)

$(LIB):
	@make -C libft/

clean:
	@rm -f *.o
	@rm -rf obj
	@make -C libft/ clean
	@make -C minilibx/ clean
	@echo "$(B_RED)  Cleaned$(NO_COLOR)"

fclean: clean
	@rm -f $(EX)
	@make -C libft/ fclean
	@echo "$(B_RED)  fclean-ed.$(NO_COLOR)"

re: fclean all

.PHONY: clean fclean all re

