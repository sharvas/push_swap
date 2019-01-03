
#include "libft/libft.h"
#include <stdio.h>

void	ft_condense_instructions(char *instructions)
{
	char	*str;
	int		n;
	char	*verbose;
	char	*tmp;

	str = instructions;
	while ((verbose = ft_strstr(str, "ra\nrb\n")))
	{
		tmp = str;
		n = 0;

		while(tmp != verbose)
		{
			tmp++;
			n++;
		}
		str = ft_strndup(str, n);//free
		str = ft_strjoinfree_s1(str, "rr\n");
		str = ft_strjoinfree_s1(str, instructions + n + 6);
		instructions = str;
	}
//	all->instructions = str;
	ft_putstr(str);
}

int		main(void)
{
	char	*str;
//	str = "ra\nrb\n";
//	str = "ra\nrb\nra\nrb\n";
//	str = "ra\nrb\npa\npb\n";
//	str = "pa\npb\nra\nrb\npa\npb\n";
	str = "pb\npb\npb\nra\npb\nra\nrb\npb\npb\nra\nrb\npb\npb\nra\npb\n\n";
//	str = "pb\npb\npb\nra\npb\nra\nrb\n";
//	str = "ra\nrb\npb\nra\npb\n";
	ft_putstr(str);
	ft_putstr("\n\n");
	ft_condense_instructions(str);
	// ft_putstr(str);
}
