#include "../rtv1.h"

static void			check_cone_obj3(t_env *env, t_buff line, int i)
{
	t_double3	values;

	if (i == 4)
	{
		if (ft_strstr(line.data, "ior") != NULL)
		{
			check_pars_nbr_value(line, 1);
			values = pick_values(line, 1);
			add_cone_value(env, &values, i);
		}
		else
			ft_error("Error : Wrong Value Name.\n");
	}
	else if (i == 5)
	{
		if (ft_strstr(line.data, "Material") != NULL)
		{
			check_pars_nbr_value(line, 1);
			values = pick_values(line, 1);
			add_cone_value(env, &values, i);
		}
		else
			ft_error("Error : Wrong Value Name.\n");
	}
}

static void			check_cone_obj2(t_env *env, t_buff line, int i)
{
	t_double3	values;

	if (i == 2)
	{
		if (ft_strstr(line.data, "Aperture") != NULL)
		{
			check_pars_nbr_value(line, 1);
			values = pick_values(line, 1);
			add_cone_value(env, &values, i);
		}
		else
			ft_error("Error : Wrong Value Name.\n");
	}
	else if (i == 3)
	{
		if (ft_strstr(line.data, "Color") != NULL)
		{
			check_pars_nbr_value(line, 3);
			values = pick_values(line, 3);
			add_cone_value(env, &values, i);
		}
		else
			ft_error("Error : Wrong Value Name.\n");
	}
	check_cone_obj3(env, line, i);
}

void				check_cone_obj(t_env *env, t_buff line, int i)
{
	t_double3	values;

	if (i == 0)
	{
		if (ft_strstr(line.data, "Pos") != NULL)
		{
			check_pars_nbr_value(line, 3);
			values = pick_values(line, 3);
			add_cone_value(env, &values, i);
		}
		else
			ft_error("Error : Wrong Value Name.\n");
	}
	else if (i == 1)
	{
		if (ft_strstr(line.data, "Normal") != NULL)
		{
			check_pars_nbr_value(line, 3);
			values = pick_values(line, 3);
			add_cone_value(env, &values, i);
		}
		else
			ft_error("Error : Wrong Value Name.\n");
	}
	check_cone_obj2(env, line, i);
}
