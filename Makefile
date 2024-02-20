# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msacaliu <msacaliu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/18 14:48:18 by msacaliu          #+#    #+#              #
#    Updated: 2024/02/20 14:19:20 by msacaliu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
CLIENT = client
SERVER = server
FT_PRINTF = /home/msacaliu/42_projects/libftprintf
INCLUDES = -I$(FT_PRINTF)/includes
FT_PRINTF_LIBS = -L$(FT_PRINTF) -lftprintf

%:	%.c
	cc ${FLAGS} $< -o $@ $(INCLUDES) $(FT_PRINTF_LIBS)
    
all: ${CLIENT} ${SERVER}

clean:
	rm -rf *.o
    
fclean : clean
	rm -rf ${CLIENT} ${SERVER}

re: fclean all
