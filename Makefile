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
CFLAGS	= -Wall -Wextra -g -w -lpthread -std=c99
SRC		= $(shell ls sources/src | grep -E ".+\.c")
ODIR	:= sources/obj
OBJ		:= $(addprefix $(ODIR)/,$(SRC:%.c=%.o))
INC		= sources/includes
LIB		= sources/libft.a
EX		= RT

all: $(LIB) $(EX)

$(EX): $(OBJ)
	@make -C sources/minilibx/
	@echo "$(RED)  libmlx.a$(GRN) Successfully Created.$(NO_COLOR)"
	@$(CC) $(CFLAGS) -I $(INC) -I sources/minilibx -o $(EX) $(OBJ) -L sources -lft -L sources/minilibx -lmlx -framework OpenGL -framework AppKit
	@echo "$(RED)  ./RT$(GRN) Successfully Created.$(NO_COLOR)"

$(ODIR)/%.o:sources/src/%.c | $(ODIR)
	@$(CC) -c $(CFLAGS) -I $(INC) -I sources/minilibx -o $@  $<

$(ODIR):
	@mkdir $(ODIR)

$(LIB):
	@make -C sources/libft/

clean:
	@rm -f sources/*.o
	@rm -rf sources/obj
	@make -C sources/libft/ clean
	@make -C sources/minilibx/ clean
	@echo "$(B_RED)  Cleaned$(NO_COLOR)"

fclean: clean
	@rm -f $(EX)
	@make -C sources/libft/ fclean
	@echo "$(B_RED)  fclean-ed.$(NO_COLOR)"

re: fclean all

.PHONY: clean fclean all re

