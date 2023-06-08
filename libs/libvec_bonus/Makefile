# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/31 20:30:05 by gychoi            #+#    #+#              #
#    Updated: 2023/06/08 22:03:32 by gychoi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -MMD -MP
ARFLAGS = crus
RM = rm -rf

SRCS = add_bonus.c \
	   color3__bonus.c \
	   cross_bonus.c \
	   dot_bonus.c \
	   elem_max_bonus.c \
	   elem_min_bonus.c \
	   elem_prod_bonus.c \
	   mag_bonus.c \
	   mag_sq_bonus.c \
	   norm_bonus.c \
	   point3__bonus.c \
	   scl_mul_bonus.c \
	   sub_bonus.c \
	   vec2__bonus.c \
	   vec3__bonus.c \

OBJS = $(SRCS:.c=.o)

DEPS = $(OBJS:.o=.d)

NAME = libvec_bonus.a

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

-include $(DEPS)

.PHONY: all clean fclean re

all: $(NAME)

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all
