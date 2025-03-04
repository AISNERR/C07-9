void	ft_putchar(char c);

void	ft_print_words_tables(char **tab)
{
	int	index;
	int	i;

	index = 0;
	while (tab[index])
	{
		i = 0;
		while (tab[index][i])
		{
			ft_putchar(tab[index][i]);
			++i;
		}
		ft_putchar('\n');
		index++;
	}
}