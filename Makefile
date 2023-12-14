NAME          = push_swap
INCLUDES      = include/
HEADER        = -I $(INCLUDES)
SRC_DIR       = src/
CMD_DIR       = commands/
OBJ_DIR       = obj/

LIBFT_DIR     = libft/
LIBFT         = $(LIBFT_DIR)libft.a

CC            = gcc
CFLAGS        = -Wall -Wextra -Werror

SRC_FILES     = main stack_init stack_utils sort_three sort_stack init_a_to_b init_b_to_a error_handler
CMD_FILES     = push rotate rev_rotate
SRC_FILES    += $(addprefix $(CMD_DIR), $(CMD_FILES))

SRC           = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ           = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJ_CACHE     = .cache_exists

#####

all:			$(LIBFT) $(NAME)

$(LIBFT):
					@make -C $(LIBFT_DIR)

$(NAME):		$(OBJ)
					$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
					@echo "push_swap compiled!"


$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJ_CACHE)
					@echo "Compiling $<"
					@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(OBJ_CACHE):
					@mkdir -p $(OBJ_DIR)

clean:
					@rm -rf $(OBJ_DIR)
					@echo "push_swap object files cleaned!"

fclean:			clean
					@rm -f $(NAME)
					@echo "push_swap executable files cleaned!"

re:				fclean all
					@echo "Cleaned and rebuilt everything for push_swap!"

.PHONY:			all clean fclean re
