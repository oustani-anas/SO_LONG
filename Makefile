
NAME		=	so_long
NAMEB		=	so_long_bonus
CC			=	cc
SRCS		=	sources/so_long.c \
				sources/game.c \
				sources/map.c \
				sources/message.c \
				sources/free_map.c \
				sources/movements.c \
				sources/keys.c \
				sources/check_map.c \

SRCB 		= 	bonus/so_long_bonus.c \
				bonus/game_bonus.c \
				bonus/map_bonus.c \
				bonus/message_bonus.c \
				bonus/free_map_bonus.c \
				bonus/movements_bonus.c \
				bonus/keys_bonus.c \
				bonus/check_map_bonus.c \
				bonus/enemy_move_bonus.c \
				bonus/animation_bonus.c \

LIBFT		=	libft/libft.a
PRINTF		=	ft_printf/libftprintf.a
CFLAGS		=	-Wall -Wextra -Werror
MLXFLAGS	=	-lmlx -framework OpenGL -framework AppKit
RM			=	rm -f
OBJS		=	$(SRCS:%.c=%.o)
OBJB 		=   $(SRCB:%.c=%.o)

HEADER1     = libft.h
HEADER2		= ft_printf.h

all:		$(NAME)

$(NAME):	$(OBJS) so_long.h 
			make -C libft 	
			make -C ft_printf	
			$(CC) $(OBJS) $(LIBFT) $(PRINTF) $(MLXFLAGS) $(CFLAGS) -o $(NAME)

bonus :     $(OBJB) so_long_bonus.h
			make -C libft 
			make -C ft_printf
			$(CC) $(OBJB) $(LIBFT) $(PRINTF) $(MLXFLAGS) $(CFLAGS) -o $(NAMEB)
			

clean:
			$(RM) $(OBJS) $(OBJB)

fclean:		clean
			$(RM) $(NAME) $(NAMEB)
			$(RM) *.out
			make fclean -C libft/
			make fclean -C ft_printf/

re:			fclean all
