NAME = push_swap

SRC_FILES = init.c input.c moves.c main.c \
	push.c reverse_rotate.c rotate.c \
	swap.c utils.c \
	stack.c stack2.c sort.c \

CC = cc
CFLAGS = -Wall -Wextra -Werror -I include -I libft

RM = rm -f

GREEN = \033[0;32m
NC = \033[0m

SRC_DIR = src
OBJ_DIR = obj

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

OBJ_FILES = $(SRC_FILES:.c=.o)

SRCS = $(addprefix $(SRC_DIR)/,$(SRC_FILES))
OBJS = $(addprefix $(OBJ_DIR)/,$(OBJ_FILES))

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) :	$(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)
	@echo "$(GREEN)✅ Compiled successfully.$(NC)"

clean:
	@$(RM) $(OBJS)
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "$(GREEN)🧹 Cleaned up successfully.$(NC)"

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(GREEN)✨ Removed executables successfully.$(NC)"

re: fclean all

.PHONY: all clean fclean re