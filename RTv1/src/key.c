#include "../rtv1.h"

static int		key_main_menu(int keycode, t_env *env)
{
	if (keycode == KEY_ESC)
		exit(0);
	if (keycode == KEY_DOWN && env->control->ctm_1 < 2)
		env->control->ctm_1++;
	if (keycode == KEY_UP && env->control->ctm_1 > 0)
		env->control->ctm_1--;
	if (keycode == KEY_ENTER && env->control->ctm_1 != 2)
	{
		env->control->menu = env->control->ctm_1 + 1;
		env->control->ctm_1 = 0;
	}
	if (keycode == KEY_ENTER && env->control->ctm_1 == 2)
		env->render = 1;
	return (0);
}

static int		key_new_obj(int keycode, t_env *env)
{
	if (keycode == KEY_ESC)
	{
		env->control->menu = 0;
		env->control->ctm_1 = 0;
	}
	if (keycode == KEY_DOWN && env->control->ctm_1 < 2)
		env->control->ctm_1++;
	if (keycode == KEY_UP && env->control->ctm_1 > 0)
		env->control->ctm_1--;
	if (keycode == KEY_ENTER)
	{
		env->control->menu = 20;
		env->control->name_obj = search_type_obj(env->control->ctm_1);
		init_new_obj(env);
		env->control->ctm_1 = 0;
	}
	return (0);
}

int				key_hook(int keycode, t_env *env)
{
	if (env->control->menu == 0 || env->control->menu == 3)
		key_main_menu(keycode, env);
	else if(env->control->menu == 1)
		key_obj_menu(keycode, env);
	else if (env->control->menu == 2)
		key_new_obj(keycode, env);
	else if (env->control->menu == 10)
		key_obj_in(keycode, env);
	else if (env->control->menu == 20)
		key_new_obj_in(keycode, env);
	//ft_putnbr(keycode);
	//ft_putendl("");
	return (0);
}