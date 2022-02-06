NAME = minitalk
SERVER = server
CLIENT = client
LIBFT = libft.a

OBJ_DIR = obj
LIBFT_DIR = ./libft
OBJ_DIR_S = obj/server/
OBJ_DIR_C = obj/client/
SRC_DIR_S = src/server/
SRC_DIR_C = src/client/
HEADERS_C = includes/client_minitalk.h
HEADERS_S = includes/server_minitalk.h

CC = clang
CFLAGS = -Wall -Werror -Wextra -g
RM = rm -rf

LFLAGS = -lft
IFLAGS = -Iincludes

OBJ_SERVER	= $(OBJ_DIR_S)server.o $(OBJ_DIR_S)server_struct.o \
			  $(OBJ_DIR_S)server_string.o $(OBJ_DIR_S)server_error.o

OBJ_CLIENT	= $(OBJ_DIR_C)client.o $(OBJ_DIR_C)client_bits.o \
			  $(OBJ_DIR_C)client_end.o


all:	$(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(SERVER) $(CLIENT)

bonus: all

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(SERVER): $(OBJ_SERVER)
		$(CC) $(FLAGS) $(OBJ_SERVER) -L$(LIBFT_DIR) $(LFLAGS) -o $@

$(CLIENT): $(OBJ_CLIENT)
		$(CC) $(FLAGS) $(OBJ_CLIENT) -L$(LIBFT_DIR) $(LFLAGS) -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR_S)
	@mkdir -p $(OBJ_DIR_C)

$(OBJ_DIR_C)%.o : $(SRC_DIR_C)%.c $(HEADERS_S)
	$(CC) $(FLAGS) $< -c $(IFLAGS) -o $@

$(OBJ_DIR_S)%.o : $(SRC_DIR_S)%.c $(HEADERS_S)
	$(CC) $(FLAGS) $< -c $(IFLAGS) -o $@

clean:	
	@make clean -C $(LIBFT_DIR)
	$(RM) $(OBJ_DIR)

fclean:		clean
	@make fclean -C $(LIBFT_DIR)
	$(RM) $(SERVER) $(CLIENT)

re:			fclean all

.PHONY: all clean fclean re