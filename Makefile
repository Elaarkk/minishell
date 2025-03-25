#CONFIG

NAME = minishell
CC = cc
DEPFLAGS = -MP -MD
RM = rm -rf

#FILES

INC = ./includes/

SRCS = ./sources/main.c ./sources/utils.c ./tokenization/token.c ./sources/error.c ./tokenization/syntax_check.c

OBJDIR = ./obj

OBJS = $(addprefix $(OBJDIR)/,$(patsubst %.c,%.o,$(SRCS)))

DEP = $(OBJ:.o=.d)

#FLAGS

FLAGS = -lreadline -Wall -Wextra -I$(INC) -g3

### RAJOUTER WERROR

#COMMANDS

all : $(NAME)

$(OBJDIR)/%.o : %.c
	mkdir -p $(@D)
	$(CC) $(FLAGS) $(DEPFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(NAME) created!$(DEFAULT)"

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJDIR)
	@echo "$(YELLOW)object files deleted.$(DEFAULT)"

fclean : clean
	$(RM) $(NAME)
	@echo "$(RED)all files deleted.$(DEFAULT)"

re : fclean all

.PHONY:
		fdf all clean fclean bonus re

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m
