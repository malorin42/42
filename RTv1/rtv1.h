#ifndef RTV1_H
# define RTV1_H

# include "libft/libft.h"
//# include <mlx.h>
# include "minilibx/mlx.h"
# include <math.h>
# include <stdio.h>

# define WIDTH 1200
# define HEIGHT 800
# define FOV 30
# define DEPTH_MAX 5

	 // Key pour Linux 
//# define KEY_ESC 65307

	// Key pour Mac 
# define KEY_ESC 53

# define PI 3.14159265

# define DIFFUSE_GLOSSY 0
# define REFLECTION 1
# define REFLECTION_AND_REFRACTION 2

# define BIAS 0.0001

typedef struct	s_double2
{
	double		x;
	double		y;
}				t_double2;

typedef struct	s_double3
{
	double		x;
	double		y;
	double		z;
}				t_double3;

typedef struct	s_surface
{
	double		distance;
	t_double3	p_hit;
	t_double3	n_hit;
	t_double3	color;
	double		ior;
	int			material;
}				t_surface;

typedef struct	s_light
{
	t_double3	pos;
	t_double3	color;
}				t_light;

typedef struct	s_plane
{
	t_double3	pos;
	t_double3	normal;
	t_double3	color;
	double		ior;
	int			material;
}				t_plane;

typedef struct	s_cone
{
	t_double3	pos;
	t_double3	normal;
	t_double3	color;
	double		ior;
	double 		aperture;
	int			material;
}				t_cone;

typedef struct	s_cylinder
{
	t_double3	pos;
	t_double3	normal;
	t_double3	color;
	double		ior;
	double 		radius;
	int			material;
}				t_cylinder;

typedef struct	s_sphere
{
	t_double3	pos;
	double		radius;
	t_double3	color;
	double		ior;
	int			material;
}				t_sphere;

typedef struct	s_objects
{
	t_array		*spheres;
	t_array		*planes;
	t_array		*cylinder;
	t_array		*cone;
	t_array		*lights;
}				t_objects;

typedef struct	s_vector
{
	t_double3	pos;
	t_double3	dir;
}				t_vector;

typedef struct	s_env
{
	void		*mlx;
	void		*win_scene;
	t_image		*img;
	t_objects	*objects;
	t_vector	camera;
	int 		i_sphere;
	int 		i_plane;
	int 		i_cylinder;
	int 		i_cone;
	int 		i_light;
	int			render;
}				t_env;

int				loop_hook(t_env *env);
int				key_hook(int keycode, t_env *env);

t_double3		pick_values(t_buff line, int nbr);
void			check_pars_nbr_value(t_buff line, int nbr);

void			add_sphere_value(t_env *env, t_double3 *values, int i);
void			add_plane_value(t_env *env, t_double3 *values, int i);
void			add_cylinder_value(t_env *env, t_double3 *values, int i);
void			add_cone_value(t_env *env, t_double3 *values, int i);
void			add_light_value(t_env *env, t_double3 *values, int i);

void			check_files(int fd, t_env *env);
void			check_sphere_obj(t_env *env, t_buff line, int i);
void			check_cylinder_obj(t_env *env, t_buff line, int i);
void			check_cone_obj(t_env *env, t_buff line, int i);
void			check_light_obj(t_env *env, t_buff line, int i);
void			check_camera_obj(t_env *env, t_buff line, int i);
void			check_plane_obj(t_env *env, t_buff line, int i);

void			init_light_obj(t_env *env);
void			init_object(t_env *env, char *obj);

void			ft_load_file(int fd, t_env *env);
void			render(t_env *env);
t_double3		raytracer(t_vector ray, t_objects *objects, int depth);
t_double3		reflect(t_double3 incidence, t_double3 normal);
t_double3		refract(t_double3 incidence, t_double3 normal, double ior);
void			fresnel(t_double3 incidence, t_double3 normal, double ior, double *kr);

t_surface		*intersect(t_vector ray, t_objects *objects);
void			get_nearest_sphere(t_vector ray, t_array *spheres, t_surface **surface);
void			get_nearest_plane(t_vector ray, t_array *planes, t_surface **surface);
void			get_nearest_cylinder(t_vector ray, t_array *cylinder, t_surface **surface);

void			color_pixel_image(t_color color, int pixel_start, t_image *image);
void			swap(double *t0, double *t1);
double			dot_product(t_double3 vec1, t_double3 vec2);
t_double3		normalize(t_double3 vec);
t_double3		find_point(t_double3 origin, t_double3 dir, double scalar);
t_double3		vec_minus_vec(t_double3 vec1, t_double3 vec2);
t_double3		vec_plus_vec(t_double3 vec1, t_double3 vec2);
t_double3		scale_vec(t_double3 vec, double scalar);
t_double3 		vec_scale_vec(t_double3 vec1, t_double3 vec2);
double			max_double(double a, double b);
double			min_double(double a, double b);

#endif