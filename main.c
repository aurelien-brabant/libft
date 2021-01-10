#include "libft/cla.h"
#include "libft/io.h"

int main(int ac, char **av)
{
	void		*cla;
	long long	nb = 2;
	char		*cringeWord;
	char		*pos2;
	bool		fork = 4;

	cla = ft_cla_init(ac, av);
	ft_cla_int_var(cla, &nb, "nb", 42);
	ft_cla_str_var(cla, &cringeWord, "cringe", "default cringer");
	ft_cla_bool_var(cla, &fork, "fork", false);
	ft_cla_pos_var(cla, &pos2, 1, NULL);
	//ft_cla_parse(cla);

	ft_printf("Pos 2: %s\n", pos2);
	ft_printf("%d\n", nb);
	ft_printf("%s\n", cringeWord);
	ft_printf("%d\n", fork);
}
