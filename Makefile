NAME          = push_swap
INCLUDES      = include/
HEADER        = -I $(INCLUDES)
SRC_DIR       = src/
OBJ_DIR       = obj/

LIBFT_DIR     = libft/
LIBFT         = $(LIBFT_DIR)libft.a

CC            = gcc
CFLAGS        = -Wall -Wextra -Werror

SRC_FILES     = 

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
