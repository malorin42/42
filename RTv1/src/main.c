#include "../rtv1.h"

int				key_hook(int keycode, t_env *env)
{
	if (keycode == KEY_ESC)
		exit(0);
	return (0);
}

int				loop_hook(t_env *env)
{
	if (env->render == 1)
	{
		render(env);
		mlx_put_image_to_window(env->mlx, env->win_scene, env->img->img, 0, 0);
		env->render = 0;
	}
	return (0);
}

static t_image	*ft_new_image(void *mlx)
{
	t_image		*img;

	if ((img = (t_image*)malloc(sizeof(t_image))) == NULL)
		ft_error("Error: malloc failed.\n");
	img->img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img->data = (unsigned char*)mlx_get_data_addr(img->img, &img->opp, 
		&img->l_size, &img->endian);
	img->opp = img->opp / 8;
	img->width = WIDTH;
	img->height = HEIGHT;
	return (img);
}

static t_env	*env_init()
{
	t_env		*env;
	
	if ((env = (t_env*)malloc(sizeof(t_env))) == NULL)
		ft_error("Error : malloc() failed.\n");
	if ((env->mlx = mlx_init()) == NULL)
		ft_error("Error : mlx_init() failed.\n");
	env->win_scene = mlx_new_window(env->mlx, WIDTH, HEIGHT, "RTv1");
	env->img = ft_new_image(env->mlx);
	if ((env->objects = (t_objects*)malloc(sizeof(t_objects))) == NULL)
		ft_error("Error : malloc() failed.\n");
	env->objects->spheres = ft_array_new();
	env->objects->planes = ft_array_new();
	env->objects->lights = ft_array_new();
	env->objects->cylinder = ft_array_new();
	env->objects->cone = ft_array_new();
	env->i_sphere = -1;
	env->i_plane = -1;
	env->i_cylinder = -1;
	env->i_cone = -1;
	env->i_light = -1;
	env->camera = (t_vector){(t_double3){0, 0, 0}, (t_double3){0, 0, -1}};
	env->render = 1;
	mlx_key_hook(env->win_scene, &key_hook, env);
	mlx_loop_hook(env->mlx, &loop_hook, env);
	return (env);
}

int 			wrong_files(char const *str)
{
	int 		i;
	int 		j;
	char		*scn;

	i = 0;
	scn = ".scn";
	while (str[i] != '\0' && str[i] != '.')
		i++;
	if (str[i] == '.')
	{
		j = 0;
		while (str[i] != '\0' && j <= 3)
		{
			if (str[i] != scn[j])
				return (0);
			i++;
			j++;
		}
	}
	else
		return (0);
	return (1);
}

int				main(int argc, char const **argv)
{
	t_env		*env;
	int			fd;
	t_sphere	*tmp;
	t_cylinder	*tmp_cy;
	t_plane		*tmp_p;
	t_cone		*tmp_c;
	t_light		*tmp_l;
	int 		i;

	if (argc != 2)
		ft_error("Error : Wrong numbers of Arguments.\n");
	if (wrong_files(argv[1]) != 1)
		ft_error("Error : File isn't a '.scn'\n");
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		ft_error("Error : File not found.\n");
	env = env_init();
	check_files(fd, env);
	i = 0;
	while (i < env->objects->spheres->length)
	{
		tmp = AG(t_sphere*, env->objects->spheres, i);
		i++;
		printf("pos->x = %f\npos->y %f\npos->z = %f\n", tmp->pos.x ,tmp->pos.y, tmp->pos.z);
	}
	close(fd);		
	mlx_loop(env->mlx);
	return (0);
}