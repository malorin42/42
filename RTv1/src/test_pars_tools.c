#include "../rtv1.h"

static int	search_next_nbr(t_buff line, int i)
{
	while (line.data[i] != '\0' && line.data[i] != '\n' &&
		ft_isdigit(line.data[i]) == 0)
		i++;
	if (ft_isdigit(line.data[i]) == 0)
		i = -1;
	return (i);
}

t_double3	pick_values(t_buff line, int nbr)
{
	t_double3	values;
	
	values.x = 0;
	values.y = 0;
	values.z = 0;
	ft_parse_not(&line, "{");
	line.i++;
	values.x = ft_parse_double(&line);
	if (nbr == 3)
	{
		ft_parse_not(&line, "-0123456789");
		values.y = ft_parse_double(&line);
		ft_parse_not(&line, "-0123456789");
		values.z = ft_parse_double(&line);
	}
	return (values);
}

void		check_pars_nbr_value(t_buff line, int nbr)
{
	int		i;

	i = 0;
	while (line.data[i] != '{' && line.data[i] != '\0')
		i++;
	if (line.data[i] != '{')
		ft_error("Error : Bracket Problem.\n");
	i++;
	while (line.data[i] != '\0')
	{
		if (ft_isdigit(line.data[i]) == 1)
		{
			while (ft_isdigit(line.data[i]) == 1)
				i++;
			if (line.data[i] != '.' && line.data[i] != '}')
				ft_error("Error : Problem in Bracket.");
			else
				i++;
			while (ft_isdigit(line.data[i]) == 1)
				i++;
			if (ft_isspace(line.data[i]) == 1 || line.data[i] == '}')
				nbr--;
			else
				ft_error("Error : Problem in Bracket.\n");
		}
		i++;
	}
	if (nbr > 0 || nbr < 0)
		ft_error("Error : Wrong Numbers of Values in a Line.\n");
}
