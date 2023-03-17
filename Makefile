NAME = fractol
BONUS_NAME = fractol_bonus
FLAGS = -Wall -Werror -Wextra -Ofast -g -fsanitize=address
MLX_FLAGS = -framework OpenGL -framework AppKit -g -fsanitize=address

FRACTOLSRCS = 	./src/main.c \
				./src/hook.c \
				./src/color.c \
				./src/mandelbrot.c \
				./src/utils.c \
				./src/color_pallette.c \
				./src/color_pallette2.c \
				./src/julia.c \
				./src/tricorn.c \
				./src/zoom.c \
				./src/move.c \
				./src/init.c \
				./src/error.c \
				./src/input.c \

OBJS	= $(FRACTOLSRCS:.c=.o)

INCL	= ./include/fractol.h ./include/keycodes.h

LIBFT_DIR = ./libft
LIBFT = ./libft/libft.a

MLX_DIR = ./mlx
MLX = ./mlx/libmlx.a

all: $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJS)
	cc $(MLX_FLAGS) -o $(NAME) $(OBJS) $(MLX) $(LIBFT)

%.o: %.c $(INCL)
	cc -c $(FLAGS) $< -o ${<:.c=.o}

$(LIBFT):
	+make -C $(LIBFT_DIR)

$(MLX):
	+make -C $(MLX_DIR)

clean:
	rm -f $(OBJS)
	+make -C $(LIBFT_DIR) clean
	+make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	+make -C $(LIBFT_DIR) fclean
	+make -C $(MLX_DIR) clean

re: fclean all

coffee:
	@clear
	@echo ""
	@echo "                   ("
	@echo "	                     )     ("
	@echo "               ___...(-------)-....___"
	@echo '           .-""       )    (          ""-.'
	@echo "      .-''''|-._             )         _.-|"
	@echo '     /  .--.|   `""---...........---""`   |'
	@echo "    /  /    |                             |"
	@echo "    |  |    |          :::      ::::::::  |"
	@echo "     \  \   |        :+:      :+:    :+:  |"
	@echo "      '\ '\ |      +:+ +:+         +:+    |"
	@echo "        '\ '|    +#+  +:+       +#+       |"
	@echo "        _/ /\  +#+#+#+#+#+   +#+          /"
	@echo "       (__/  \      #+#    #+#           /"
	@echo '    _..---""` \    ###   ########.fr    /`""---.._'
	@echo " .-'           \                       /          '-."
	@echo ":               '-.__             __.-'              :"
	@echo ':                  ) ""---...---"" (                :'
	@echo "\'._                '"--...___...--"'              _.'"
	@echo '   \""--..__                              __..--""/'
	@echo "     '._     """----.....______.....----"""         _.'"
	@echo '         ""--..,,_____            _____,,..--"""'''
	@echo '                      """------"""'
	@sleep 0.5
	@clear
	@echo ""
	@echo "                 ("
	@echo "	                  )      ("
	@echo "               ___..(.------)--....___"
	@echo '           .-""       )   (           ""-.'
	@echo "      .-''''|-._      (       )        _.-|"
	@echo '     /  .--.|   `""---...........---""`   |'
	@echo "    /  /    |                             |"
	@echo "    |  |    |          :::      ::::::::  |"
	@echo "     \  \   |        :+:      :+:    :+:  |"
	@echo "      '\ '\ |      +:+ +:+         +:+    |"
	@echo "        '\ '|    +#+  +:+       +#+       |"
	@echo "        _/ /\  +#+#+#+#+#+   +#+          /"
	@echo "       (__/  \      #+#    #+#           /"
	@echo '    _..---""` \    ###   ########.fr    /`""---.._'
	@echo " .-'           \                       /          '-."
	@echo ":               '-.__             __.-'              :"
	@echo ':                  ) ""---...---"" (                :'
	@echo "\'._                '"--...___...--"'              _.'"
	@echo '   \""--..__                              __..--""/'
	@echo "     '._     """----.....______.....----"""         _.'"
	@echo '         ""--..,,_____            _____,,..--"""'''
	@echo '                      """------"""'
	@sleep 0.5
	@clear
	@echo ""
	@echo "               ("
	@echo "	                  )     ("
	@echo "               ___..(.------)--....___"
	@echo '           .-""      )    (           ""-.'
	@echo "      .-''''|-._      (       )        _.-|"
	@echo '     /  .--.|   `""---...........---""`   |'
	@echo "    /  /    |                             |"
	@echo "    |  |    |          :::      ::::::::  |"
	@echo "     \  \   |        :+:      :+:    :+:  |"
	@echo "      '\ '\ |      +:+ +:+         +:+    |"
	@echo "        '\ '|    +#+  +:+       +#+       |"
	@echo "        _/ /\  +#+#+#+#+#+   +#+          /"
	@echo "       (__/  \      #+#    #+#           /"
	@echo '    _..---""` \    ###   ########.fr    /`""---.._'
	@echo " .-'           \                       /          '-."
	@echo ":               '-.__             __.-'              :"
	@echo ':                  ) ""---...---"" (                :'
	@echo "\'._                '"--...___...--"'              _.'"
	@echo '   \""--..__                              __..--""/'
	@echo "     '._     """----.....______.....----"""         _.'"
	@echo '         ""--..,,_____            _____,,..--"""'''
	@echo '                      """------"""'
	@sleep 0.5
	@clear
	@echo ""
	@echo "             (         ) "
	@echo "	              )        ("
	@echo "               ___)...----)----....___"
	@echo '           .-""      )    (           ""-.'
	@echo "      .-''''|-._      (       )        _.-|"
	@echo '     /  .--.|   `""---...........---""`   |'
	@echo "    /  /    |                             |"
	@echo "    |  |    |          :::      ::::::::  |"
	@echo "     \  \   |        :+:      :+:    :+:  |"
	@echo "      '\ '\ |      +:+ +:+         +:+    |"
	@echo "        '\ '|    +#+  +:+       +#+       |"
	@echo "        _/ /\  +#+#+#+#+#+   +#+          /"
	@echo "       (__/  \      #+#    #+#           /"
	@echo '    _..---""` \    ###   ########.fr    /`""---.._'
	@echo " .-'           \                       /          '-."
	@echo ":               '-.__             __.-'              :"
	@echo ':                  ) ""---...---"" (                :'
	@echo "\'._                '"--...___...--"'              _.'"
	@echo '   \""--..__                              __..--""/'
	@echo "     '._     """----.....______.....----"""         _.'"
	@echo '         ""--..,,_____            _____,,..--"""'''
	@echo '                      """------"""'
	@sleep 0.5
	@clear
	@echo ""
	@echo "               ("
	@echo "	                  )     ("
	@echo "               ___..(.------)--....___"
	@echo '           .-""      )    (           ""-.'
	@echo "      .-''''|-._      (       )        _.-|"
	@echo '     /  .--.|   `""---...........---""`   |'
	@echo "    /  /    |                             |"
	@echo "    |  |    |          :::      ::::::::  |"
	@echo "     \  \   |        :+:      :+:    :+:  |"
	@echo "      '\ '\ |      +:+ +:+         +:+    |"
	@echo "        '\ '|    +#+  +:+       +#+       |"
	@echo "        _/ /\  +#+#+#+#+#+   +#+          /"
	@echo "       (__/  \      #+#    #+#           /"
	@echo '    _..---""` \    ###   ########.fr    /`""---.._'
	@echo " .-'           \                       /          '-."
	@echo ":               '-.__             __.-'              :"
	@echo ':                  ) ""---...---"" (                :'
	@echo "\'._                '"--...___...--"'              _.'"
	@echo '   \""--..__                              __..--""/'
	@echo "     '._     """----.....______.....----"""         _.'"
	@echo '         ""--..,,_____            _____,,..--"""'''
	@echo '                      """------"""'
	@sleep 0.5
	@clear
	@echo ""
	@echo "                 ("
	@echo "	                  )      ("
	@echo "               ___..(.------)--....___"
	@echo '           .-""       )   (           ""-.'
	@echo "      .-''''|-._      (       )        _.-|"
	@echo '     /  .--.|   `""---...........---""`   |'
	@echo "    /  /    |                             |"
	@echo "    |  |    |          :::      ::::::::  |"
	@echo "     \  \   |        :+:      :+:    :+:  |"
	@echo "      '\ '\ |      +:+ +:+         +:+    |"
	@echo "        '\ '|    +#+  +:+       +#+       |"
	@echo "        _/ /\  +#+#+#+#+#+   +#+          /"
	@echo "       (__/  \      #+#    #+#           /"
	@echo '    _..---""` \    ###   ########.fr    /`""---.._'
	@echo " .-'           \                       /          '-."
	@echo ":               '-.__             __.-'              :"
	@echo ':                  ) ""---...---"" (                :'
	@echo "\'._                '"--...___...--"'              _.'"
	@echo '   \""--..__                              __..--""/'
	@echo "     '._     """----.....______.....----"""         _.'"
	@echo '         ""--..,,_____            _____,,..--"""'''
	@echo '                      """------"""'

.PHONY: all clean fclean re coffee
