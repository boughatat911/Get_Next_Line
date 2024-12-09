/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:42:49 by nbougrin          #+#    #+#             */
/*   Updated: 2024/12/09 17:46:22 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

static char	*ft_read_new_line(int fd, char *new_line)
{
	char	*buffer;
	int		size_buff;
	char	*tmp;

	buffer = malloc(((size_t)BUFFER_SIZE + 1));
	if (!buffer)
		return (free(new_line), NULL);
	size_buff = 1;
	while (!ft_strchr(new_line, '\n') && size_buff != 0)
	{
		size_buff = read(fd, buffer, BUFFER_SIZE);
		if (size_buff < 0)
		{
			free(new_line);
			new_line = NULL;
			return (free(buffer), buffer = NULL, NULL);
		}
		buffer[size_buff] = '\0';
		// tmp = new_line;
		new_line = ft_strjoin(new_line, buffer);
		// free(tmp);
	}
	free(buffer);
	buffer = NULL;
	return (new_line);
}

static char	*ft_write_new_line(char *new_line)
{
	size_t	i;
	char	*line;

	i = 0;
	if (!new_line || !(*new_line))
		return (NULL);
	while (new_line[i] != '\n' && new_line[i] != '\0')
		i++;
	if (new_line[i] == '\n')
		i++;
	line = ft_substr(new_line, 0, i);
	if (!line)
		return (free(new_line), new_line = NULL, NULL);
	return (line);
}

static char	*ft_get_new_line(char *new_line)
{
	char	*new;
	size_t	i;
	size_t	j;

	i = 0;
	if (!new_line)
		return (NULL);
	while (new_line[i] != '\n' && new_line[i] != '\0')
		i++;
	if (new_line[i] == '\n')
		i++;
	if (new_line[i] == '\0')
		return (free(new_line), new_line = NULL, NULL);
	j = i;
	while (new_line[j] != '\0')
		j++;
	new = ft_substr(new_line, i, j - i);
	if (!new)
		return (free(new_line), new_line = NULL, NULL);
	free (new_line);
	new_line = NULL;
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*new_line;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > __INT_MAX__)
		return (NULL);
	new_line = ft_read_new_line(fd, new_line);
	if (!new_line)
		return (NULL);
	line = ft_write_new_line(new_line);
	if (!line)
		return (free(new_line), new_line = NULL, NULL);
	new_line = ft_get_new_line(new_line);
	return (line);
}
#include <libc.h>
void f()
{
    system("leaks a.out");
}
int main ()
{
atexit(f);
    int fd = open ("t.txt", O_CREAT | O_RDWR);
    char *str = get_next_line(fd);
	read(fd, str,50);
    write(fd, "hello", 5);
    printf("%s\n", str);
free(str);
}
// int main()
// {
//     int fd = open("text.txt", O_RDWR);
// 	char ;
//     read(fd, buffer,50);
//     write(fd, "12", 2);
// }