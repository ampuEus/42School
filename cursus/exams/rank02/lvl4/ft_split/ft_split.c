#include <stdlib.h>

char	is_delimiter(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

unsigned int	wordlen(char *str)
{
	unsigned int len = 0;

	while (str[len] && !is_delimiter(str[len]))
		len++;
	return (len);
}

char	*worddup(char *str)
{
	unsigned int	i = 0;
	unsigned int	len = wordlen(str);
	char			*word;

	word = malloc(sizeof(word) * (len + 1));
	if (!word)
		return (0);
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

void	fill_words(char **array, char *str)
{
	unsigned int	i = 0;
	unsigned int	word = 0;

	while (is_delimiter(str[i]))
		i++;
	while (str[i])
	{
		array[word] = worddup(str + i);
		word++;
		while (str[i] && !is_delimiter(str[i]))
			i++;
		while (is_delimiter(str[i]))
			i++;
	}
}

unsigned int	count_words(char *str)
{
	unsigned int	i = 0;
	unsigned int	words = 0;

	while (is_delimiter(str[i]))
		i++;
	while (str[i])
	{
		words++;
		while (str[i] && !is_delimiter(str[i]))
			i++;
		while (is_delimiter(str[i]))
			i++;
	}
	return (words);
}

char	**ft_split(char *str)
{
	unsigned int	words;
	char			**output;

	words = count_words(str);
	output = malloc((words + 1) * sizeof(*output));
	if (output)
		fill_words(output, str);
	return (output);
}
