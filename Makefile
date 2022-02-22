# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarle-m <acarle-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/05 00:14:21 by acarle-m          #+#    #+#              #
#    Updated: 2022/02/22 14:09:08 by acarle-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=	libftprintf.a

CC			=	gcc

FLAGS		=	-Wall -Wextra -Werror

OBJSDIR		=	objs/

BUILDDIR	=	build/

SRCSDIR		=	srcs/

LIB			=	libft/build/libft.a

OBJS		=	$(SRCS:$(SRCSDIR)%.c=$(OBJSDIR)%.o)

SRCS		=	$(wildcard $(SRCSDIR)*.c)

HEADER		=	-I include -I libft/build

all			:	$(NAME)

$(NAME)		:	$(OBJS)
				make -C libft
				ar rcs $(NAME) $(OBJS) $(LIB)

$(OBJS)		:	$(OBJSDIR)%.o : $(SRCSDIR)%.c
				mkdir -p $(OBJSDIR)
				$(CC) $(FLAGS) ${HEADER} -c $< -o $@

clean		:
				make clean -C libft
				rm -rf $(OBJSDIR)

fclean		:	clean
				make fclean -C libft
				rm -rf $(NAME)

re			:	fclean all

.PHONY		:	all re clean fclean

NAME		=	$(BUILDDIR)libft.a

CC			=	gcc

FLAGS		=	-Wall -Wextra -Werror

OBJSDIR		=	objs/

BUILDDIR	=	build/

SRCSDIR		=	src/

OBJS		=	$(SRCS:$(SRCSDIR)%.c=$(OBJSDIR)%.o)

SRCS		=	$(wildcard $(SRCSDIR)*.c)

HEADER		=	-I include -I libft

all			:	$(NAME)

$(NAME)		:	$(OBJS)
				mkdir -p $(BUILDDIR)
				ar rcs $(NAME) $(OBJS)

$(OBJS)		:	$(OBJSDIR)%.o : $(SRCSDIR)%.c
				mkdir -p $(OBJSDIR)
				$(CC) $(FLAGS) ${HEADER} -c $< -o $@

clean		:
				rm -rf $(OBJSDIR)

fclean		:	clean
				rm -rf $(BUILDDIR)

re			:	fclean all

.PHONY		:	all re clean fclean