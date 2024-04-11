#  |  |  ___ \    \  |         |
#  |  |     ) |  |\/ |   _  |  |  /   _ 
# ___ __|  __/   |   |  (   |    <    __/ 
#    _|  _____| _|  _| \__,_| _|\_\ \___|
#                              by jcluzet
################################################################################
#                                     CONFIG                                   #
################################################################################

NAME        := a.out
CC        := gcc
FLAGS    := -Wall -Wextra -Werror 
################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS        :=      fractal_init.c \
                          fractal_render.c \
                          main.c \
                          map_function.c \
                          math_utils.c \
                          minilibx-linux/mlx_clear_window.c \
                          minilibx-linux/mlx_destroy_display.c \
                          minilibx-linux/mlx_destroy_image.c \
                          minilibx-linux/mlx_destroy_window.c \
                          minilibx-linux/mlx_expose_hook.c \
                          minilibx-linux/mlx_ext_randr.c \
                          minilibx-linux/mlx_flush_event.c \
                          minilibx-linux/mlx_get_color_value.c \
                          minilibx-linux/mlx_get_data_addr.c \
                          minilibx-linux/mlx_hook.c \
                          minilibx-linux/mlx_init.c \
                          minilibx-linux/mlx_int_anti_resize_win.c \
                          minilibx-linux/mlx_int_do_nothing.c \
                          minilibx-linux/mlx_int_get_visual.c \
                          minilibx-linux/mlx_int_param_event.c \
                          minilibx-linux/mlx_int_set_win_event_mask.c \
                          minilibx-linux/mlx_int_str_to_wordtab.c \
                          minilibx-linux/mlx_int_wait_first_expose.c \
                          minilibx-linux/mlx_key_hook.c \
                          minilibx-linux/mlx_lib_xpm.c \
                          minilibx-linux/mlx_loop.c \
                          minilibx-linux/mlx_loop_hook.c \
                          minilibx-linux/mlx_mouse.c \
                          minilibx-linux/mlx_mouse_hook.c \
                          minilibx-linux/mlx_new_image.c \
                          minilibx-linux/mlx_new_window.c \
                          minilibx-linux/mlx_pixel_put.c \
                          minilibx-linux/mlx_put_image_to_window.c \
                          minilibx-linux/mlx_rgb.c \
                          minilibx-linux/mlx_screen_size.c \
                          minilibx-linux/mlx_set_font.c \
                          minilibx-linux/mlx_string_put.c \
                          minilibx-linux/mlx_xpm.c \
                          minilibx-linux/test/main.c \
                          minilibx-linux/test/new_win.c \
                          utils.c \
                          
OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

################################################################################
#                                  Makefile  objs                              #
################################################################################


CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f

${NAME}:	${OBJS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			${CC} ${FLAGS} -o ${NAME} ${OBJS}
			@echo "$(GREEN)$(NAME) created[0m ✔️"

all:		${NAME}

bonus:		all

clean:
			@ ${RM} *.o */*.o */*/*.o
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
			@ ${RM} ${NAME}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all

.PHONY:		all clean fclean re


