/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbougrin <nbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:42:49 by nbougrin          #+#    #+#             */
/*   Updated: 2024/12/11 15:23:21 by nbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

static char	*ft_read_new_line(int fd, char *new_line)
{
	char	*buffer;
	int		size_buff;
	char	*tmp;

	size_buff = 1;
	buffer = malloc(((size_t)BUFFER_SIZE + 1));
	if (!buffer)
		return (free(new_line), NULL);
	while (!ft_strchr(new_line, '\n') && size_buff != 0)
	{
		size_buff = read(fd, buffer, BUFFER_SIZE);
		if (size_buff < 0)
			return (free(buffer),free(new_line), NULL);
		buffer[size_buff] = '\0';
		tmp = new_line;
		new_line = ft_strjoin(new_line, buffer);
		free(tmp);
	}
	free(buffer);
	return (new_line);
}

static char	*ft_write_new_line(char *new_line)
{
	size_t	i;
	char	*line;

	i = 0;
	if (!new_line || !(*new_line)) // ****cheban lik****
		return (NULL);
	while (new_line[i] != '\n' && new_line[i] != '\0')
		i++;
	if (new_line[i] == '\n')
		i++;
	line = ft_substr(new_line, 0, i);
	if (!line)
		return (free(new_line),NULL);
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
		return (free(new_line), NULL);
	j = i;
	while (new_line[j] != '\0')
		j++;
	new = ft_substr(new_line, i, j - i);
	if (!new)
		return (free(new_line), NULL);
	free (new_line);
	new_line = NULL;
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*new_line;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483647)
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

void f()
{
    system("leaks a.out");
}
int main ()
{
// atexit(f);
char *buff;
    int fd = open ("t.txt", O_CREAT | O_RDWR,0666);
    char *str = get_next_line(fd);
    write(fd, "hello", 6);
	free(str);
	fd = open ("t.txt", O_CREAT | O_RDWR,0666);
	str = get_next_line(fd);
    printf("%s\n", str);
free(str);
}


// #include <fcntl.h>
// #include <unistd.h>
// #include <stdio.h>
// #include <stdlib.h>

// // Assuming the get_next_line function is defined elsewhere

// int main() {
// 	// atexit(f);
//     int fd = open("t.txt", O_RDONLY);  // Open the file for reading
//     if (fd < 0) {
//         perror("Failed to open file");
//         return 1;
//     }

//     char *line;
//     while ((line = get_next_line(fd)) != NULL) {  // Continue until EOF
//         printf("%s", line);  // Print the line (get_next_line already includes newline)
//         free(line);  // Don't forget to free the memory allocated by get_next_line
//     }
// atexit(f);
//     close(fd);  // Close the file descriptor
//     return 0;
// }































































































































// int main ()
// {
// char *buff;
//     int fd = open ("t.txt", O_CREAT | O_RDWR,0777);
//     // fd = open ("t.txt", O_CREAT | O_RDWR,0777);
//     // char *str = get_next_line(fd);
//     write(fd, "hello ", 6);
//     fd = open ("t.txt", O_CREAT | O_RDWR,0777);
// 	ssize_t i = read(fd, buff,5);
// 	// free(str);
// 	// fd = open ("t.txt", O_CREAT | O_RDWR,0777);
// 	// str = get_next_line(fd);
// 	// buff[i] = '\0';
//     // printf("%c\n", buff[i]);
//     printf("%s\n", buff);
// // free(str);
// // }
// #include <unistd.h>
// #include <fcntl.h>
// #include <stdio.h>
// #include <stdlib.h>

// int main() {
//     int fd = open("t.txt", O_CREAT | O_RDWR, 0666);
// //     write(fd, "hello ", 6);

// //     char buff[6];  // Buffer to read up to 5 characters + null terminator
// //    fd = open("t.txt", O_CREAT | O_RDWR, 0666);
// //     ssize_t i = read(fd, buff, 10);
//     // buff[i] = '\0';
//     // printf("%c\n", buff[i]);
// char *r = get_next_line(fd);
// 	printf("%s\n", r);
// 	printf("%s\n", r+1);
    
	
    
//     close(fd);
//     return 0;
// }
