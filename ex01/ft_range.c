#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int *tab;

	if (min >= max)
	{
		tab = NULL;
		return (tab);
	}
	if (!(tab = malloc(sizeof(int) * (max - min))))
		return (NULL);
	while (max >= min)
	{
		tab[max - min - 1] = max - 1;
		max--;
	}
	return (tab);
}