# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: louislaparre <louislaparre@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/21 12:41:57 by lolaparr          #+#    #+#              #
#    Updated: 2023/04/19 18:16:25 by louislaparr      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := libft.a
SRC_DIR     := src
BUILD_DIR   := .build
SRCS		:= 	\
			bool/ft_isalpha.c \
			bool/ft_isascii.c \
			bool/ft_isdigit.c \
			bool/ft_isalnum.c \
			ctypes/ft_tolower.c \
			ctypes/ft_toupper.c \
			stdlib/ft_atoi.c \
			stdlib/ft_calloc.c \
			stdlib/ft_strdup.c \
			strings/ft_strlen.c \
			strings/ft_bzero.c \
			strings/ft_memchr.c \
			strings/ft_memcmp.c \
			strings/ft_memset.c \
			strings/ft_memmove.c \
			strings/ft_strchr.c \
			strings/ft_strlcat.c \
			strings/ft_split.c \
			strings/ft_strjoin.c \
			strings/ft_striteri.c \
			strings/ft_strdup.c \
			strings/ft_strncmp.c \
			lst/ft_lstadd_back.c \
			lst/ft_lstadd_front.c \
			lst/ft_lstclear.c \
			lst/ft_lstdelone.c \
			lst/ft_lstiter.c \
			lst/ft_lstlast.c \
			lst/ft_lstmap.c \
			lst/ft_lstnew.c \
			lst/ft_lstsize.c \
			get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c \
			ft_printf/ft_printf.c \
			ft_printf/ft_printf_utils.c \
			ft_printf/ft_print_ptr.c \
			ft_printf/ft_put_nbr.c

SRCS		:= $(SRCS:%=$(SRC_DIR)/%)
OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS		:= $(OBJS:.o=.d)

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -fPIC -g3
CPPFLAGS	:= -MMD -MP -I include
AR			:= ar
ARFLAGS		:= -r -c -s
RM			:= rm -f
MAKEFLAGS	+= --no-print-directory
DIR_DUP		= mkdir -p $(@D)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	$(info CREATED $@)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	$(info CREATED $@)

-include $(DEPS)

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: clean fclean re
.SILENT:
