SRC_SERVER	= server.c server_struct.c \
			  server_string.c server_error.c

SRC_CLIENT	= client.c client_bits.c \
			  client_end.c


all:	libft.a obj_dir server client

libft.a:
	@make -C ./libft

server: obj/server/server.o obj/server/server_struct.o obj/server/server_string.o obj/server/server_error.o
		clang -Wall -Werror -Wextra obj/server/server.o obj/server/server_struct.o obj/server/server_string.o obj/server/server_error.o -L./libft -lft -o $@

client: obj/client/client.o obj/client/client_bits.o obj/client/client_end.o
		clang -Wall -Werror -Wextra -g obj/client/client.o obj/client/client_bits.o obj/client/client_end.o -L./libft -lft -o $@

obj_dir:
	@mkdir -p obj
	@mkdir -p obj/server
	@mkdir -p obj/client

./obj/client/%.o : ./src/client/%.c
	clang -Wall -Werror -Wextra  -g $< -c -I includes -o $@

./obj/server/%.o : ./src/server/%.c
	clang -Wall -Werror -Wextra  $< -c -I includes -o $@

clean:	
	@make clean -C libft
	@rm -rf ./obj

fclean:		clean
	@make fclean -C libft
	@rm -f server client

re:			fclean all

.PHONY: all clean fclean re