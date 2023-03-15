SRCS = \
	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
	ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
	ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c\
	ft_putendl_fd.c ft_putint_fd.c ft_putuint_fd.c ft_putstr_fd.c \
	ft_split.c \
	ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
	ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
	ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
	ft_putnbrbase_fd.c ft_putptraddr_fd.c ft_printf.c ft_get_next_line.c \
	ft_realloc.c

BSRCS = \
	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
	ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)

NAME = libft.a
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

bonus: $(OBJS) $(BOBJS)
	ar -rcs $(NAME) $(OBJS) $(BOBJS)
	
$(OBJS): $(SRCS)
	cc $(FLAGS) -c $(SRCS)

$(BOBJS): $(BSRCS)
	cc $(FLAGS) -c $(BSRCS)

clean:
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	rm -f $(NAME)

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