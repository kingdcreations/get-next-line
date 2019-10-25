/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tmarcon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/22 16:21:11 by tmarcon      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/25 11:49:43 by tmarcon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

int	ft_strlen(const char *s)
{
	int i;

	i = 0;
	if (s == NULL)
		return(0);
	while(s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len;
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(res = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	size_t		stlen;
	char		*res;

	if (!s)
		return (NULL);
	stlen = ft_strlen(s);
	if (start > stlen)
		return (strdup(""));
	if (stlen < len)
		len = stlen;
	if (!(res = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

static void repairer(char **oline, char **last)
{
	int i;
	int j;
	char *line;

		*last = strchr(*last + 1, '\n');
		if (*last)
		{
				printf("/!\\ Missing: \"%s\"\n", *last + 1);
		}

	i = 0;
	j = 0;
	line = *oline;
	while(line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		line = ft_substr(line, 0, i);

	*oline = line;
}

int get_next_line(int fd, char **line)
{
	int ret;
	static char *last;
	static char buf[BUFFER_SIZE + 1];

	*line = strdup("");
	last = strchr(buf, '\n');
	if (last)
	{
		*line = strdup((last + 1));
	}
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		*line = ft_strjoin(*line, buf);
		if (strchr(buf, '\n'))
		{
			repairer(line, &last);
			return(1);
		}
	}
	return(0);
}
