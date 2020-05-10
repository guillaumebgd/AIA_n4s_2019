##
## EPITECH PROJECT, 2019
## Makefile Need4Stek
## File description:
## Compiles c files with libs into the ai program
##

MAIN		=	src/main.c

SRC			=	src/command_input.c					\
				src/is_track_cleared.c				\
				src/execute_simulation.c			\
				src/optimized_car_forward.c			\
				src/handle_direction.c				\

SRCTESTS	=	tests/test_is_track_cleared.c		\

SRCLIBTESTS =	tests/test_my_get_double.c			\

VPATH		=	/usr/local/lib/

NAME		=	ai

CFLAGS		=	-Wall -Wextra

CPPFLAGS	=	-I./include/

LDFLAGS		=	-L./lib/

LDLIBS		+=	-lmy

all:	$(NAME)

$(NAME):
	$(MAKE) -sC lib/my
	$(CC) -o $@ $(MAIN) $(SRC) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

debug:
	$(MAKE) -sC lib/my
	$(CC) -g -o $@ $(SRC) $(MAIN) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

tests_run:
	$(MAKE) -sC lib/my
	$(CC) -o $@ $(SRC) $(SRCLIBTESTS) $(SRCTESTS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) -lcriterion --coverage
	./$@
	$(RM) $@

coverage:
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches

clean:
	$(RM) tests_run
	$(RM) *.gcda *.gcno
	$(RM) vgcore.*

fclean:	clean
	$(RM) $(NAME)
	$(RM) debug
	$(MAKE) fclean -sC lib/my

re:	fclean all

.NOTPARALLEL:
.PHONY: all debug tests_run coverage clean fclean re