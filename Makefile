# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtan <findmarcg@gmail.com>                    +#+  +:+       +#+      #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/27 21:40:00 by mtan              #+#    #+#              #
#    Updated: 2017/12/27 22:40:00 by mtan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rubics
FILE = main
SRCS = $(patsubst %, %.cpp, $(FILE))
BINS = $(patsubst %, %.o, $(FILE))
FLAGS = -std=c++14

.PHONY: all compile clean fclean

all: $(NAME)

compile:
	clang++ $(FLAGS) -c $(SRCS)

$(NAME): compile
	clang++ -o $(NAME) $(FLAGS) $(BINS)


clean:
	/bin/rm -f $(BINS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
