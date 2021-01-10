#ifndef CLA_H	
# define CLA_H
# include "libft/types.h"

void	*ft_cla_init(int ac, char **av);
void	ft_cla_parse(void *cla);
void	ft_cla_str_var(void *cla, char **var, const char *key, const char *dflt);
void	ft_cla_bool_var(void *cla, bool *var, const char *key, const bool *dflt);
void	ft_cla_int_var(void *cla, long long int *var, const char *key
			, long long int dflt);
void	ft_cla_pos_var(void *cla, char **var, int index, const char *dflt);

#endif
