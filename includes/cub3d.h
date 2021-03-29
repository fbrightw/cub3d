#ifndef cUB3D_H
# define cUB3D_H
# include <mlx.h>
# include <stdio.h>
# include <math.h>
# include "libft.h"
# define scale 32
# define step_pl 0.3

typedef struct				s_wall_texture
{
	void			*img;
	void			*data;
	int				bpp;
	int				line_len;
	int				endian;
	int				width;
	int				height;
	char			*path;
	int				spr_count;
}							t_wall_texture;

typedef struct				s_sprites
{
	void			*img;
	void			*data;
	int				bpp;
	int				line_len;
	int				end;
	int				width;
	int				height;
	char			*path;
	double			x;
	double			y;
	double			dist;
	int				fl_hor;
}							t_sprites;

typedef struct			s_img
{
	void			*img;
	void			*data;
	int				bpp;
	int				l_len;
	int				end;
}						t_img;

typedef struct			s_win
{
	int				w;
	int				h;
	int				i;
}						t_win;

typedef struct				s_hero
{
	double			x;
	double			y;
	int				posx;
	int				posy;
	char			dir;
	double			fov;
	double			main_degree;
}							t_hero;

typedef struct				s_ray
{
	int				hitx_x;
	int				hitx_y;
	int				hity_x;
	int				hity_y;
	double			distx;
	double			disty;
	double			distx_x;
	double			distx_y;
	double			disty_x;
	double			disty_y;
	int				color;
	double			rad;
}							t_ray;


typedef struct					s_mlx
{
	t_img			img;
	t_hero			hero;
	t_win			window;
	t_ray			ray;
	t_wall_texture	**text;
	t_sprites		**spr;
	t_list			*lists;
	char			**argv;
	int				argc;
	int				mem_to_text;
	int				mem_to_spr;
	double			rad;
	double			h_off;
	int				i;
	int				fl;
	void			*ptr;
	void			*win;
	int				size;
	int				spr_count;
	int				dist_to_proj;
	int				height_3d;
	double			texture_x;
	char			**map;
	int				begin_map;
	int				q_lines;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*s;
	char 			**f;
	char			**c;
}								t_mlx;

int					main(int argc, char **argv);
void				zeros_to_var_in_mlx(t_mlx *mlx);
int					find_textures(t_mlx *mlx, char *line);
void				ft_assigning_zeroes(int *index, int *ch, t_mlx *mlx);
char				*spaces_or_end(t_mlx *mlx, char *line);
int					ft_strchr_mod(char *str, char *s, int *index, int *ch);
int					strchr_mod(char *str, char *s, int *index, int *ch);
void				check_window(t_mlx *mlx, char **textures);
int					fill_certain_texture(t_mlx *mlx, char *line, char fl_of_side[3]);
int					ft_additional(t_mlx *mlx, char *line, int *index, int *ch);
void				check_textures(t_mlx *mlx, char *line, char *fl_of_side);
int					init_texts(t_mlx *mlx, char *line, char *fl_of_side);
void				check_floor_ceil(t_mlx *mlx, char **line);
void				count_spr(t_mlx *mlx, int j, int *count);
void				find_spr(t_mlx *mlx, int *count);
void				validation(t_mlx *mlx, int j);
void				floodfill(t_mlx *mlx, char **array, int x, int y);
int					check_odd_in_str(t_mlx *mlx, char *line, char *right, int *ch);
void				check_for_odd_ch(t_mlx *mlx, char *line);
int					check_for_odd_ch_in_res(t_mlx *mlx, char **textures);
void				count_comma(t_mlx *mlx, char *line);
int					check_before_exit(t_mlx *mlx, char *line, int index, int ch);
void				ft_start(t_mlx *mlx, int argc, char **argv);
void				ft_texturees(t_mlx *mlx);
void				ft_raycasting(t_mlx *mlx, int color);
void				xpm_to_spr(t_mlx *mlx);
void				ft_ns(t_mlx *mlx, int slice_numb, double *distances, char side);
void				ft_ew(t_mlx *mlx, int slice_numb, double *distances, char side);
void				first_hit_hor(t_mlx *mlx, double *dist_x, double *dist_y, double tang);
void				ft_seg_sit(t_mlx *mlx, double *dist_x, double *dist_y);
void				first_hit_vert(t_mlx *mlx, double *dist_x, double *dist_y, double tang);
void				find_dist(t_mlx *mlx, double *dist_x, double *dist_y, int fl);
void				drawing_3d(t_mlx *mlx, int slice_n, int fl, int i_text);
void				sprites(t_mlx *mlx, double *distances);
int					find_exact_spr(t_mlx *mlx);
void				sort_sprites(t_mlx *mlx);
void				drawing_sprites(t_mlx *mlx, double *distances, int i);
int					fill_texts(t_mlx *mlx, char *line, int *ch);
int					ft_floor_ceil(t_mlx *mlx, char *line, int *index, int *ch);
int					ceiling(t_mlx *mlx, char *line);
void				set_mem_for_spr(t_mlx *mlx, int *count);
int					create_trgb(int t, int r, int g, int b);
void				find_exact_ch(char *s, char *str, int *fl, int *ch);
int					ft_wasd(t_mlx *mlx, char ch, double new_x, double new_y);
void				left_right(t_mlx *mlx, int keycode);
int					ft_assigning(t_mlx *mlx, double new_x, double new_y, char ch);
int					close_window(t_mlx *mlx);
void				ft_draw_map(t_mlx *mlx);
void				set_mem_to_text(t_mlx *mlx);
void				my_mlx_pixel_put(t_mlx *mlx,int x, int y, int color);
void				screenshot(t_mlx *mlx);
int					open_images(t_mlx *mlx, char *line);
void				mlx_get_screen_size(int *width, int *height);
int					write_errors(t_mlx *mlx, int fl);
int					check_line(t_mlx *mlx, char *line);
void				change(t_mlx *mlx, int i, int j);
void				free_map(t_mlx *mlx);
void				free_text_spr(t_mlx *mlx, char ch);
void				free_floor_ceil(t_mlx *mlx);

#endif