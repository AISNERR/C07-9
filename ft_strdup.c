#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*dup;

	dup = 0;
	i = 0;
	if (src == 0)
		return (0);
	len = ft_strlen(src);
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == 0)
		return (0);
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	main(void)
{
	int		i;
	char	*src;
	char	*dup;

	i = 0;
	src = "Hello";
	dup = ft_strdup(src);
	while (dup[i])
	{
		printf("%c", dup[i]);
		i++;
	}
	free(dup);
	dup = 0;
	return (0);
}
