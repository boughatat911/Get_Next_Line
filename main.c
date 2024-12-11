#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
// void f()
// {
//     system("leaks a.out");
// }
// int main ()
// {
// // atexit(f);
// char *buff;
//     int fd = open ("t.txt", O_CREAT | O_RDWR,0666);
//     char *str = get_next_line(fd);
//     write(fd, "hello", 6);
// 	free(str);
// 	fd = open ("t.txt", O_CREAT | O_RDWR,0666);
// 	str = get_next_line(fd);
//     printf("%s\n", str);
// free(str);
// }

// // Assuming the get_next_line function is defined elsewhere
// int main() {
// 	// atexit(f);
//     int fd = open("t.txt", O_CREAT|O_RDWR,0777);  // Open the file for reading
//     if (fd < 0) {
//         perror("Failed to open file");
//         return 1;
//     }
//     char *line;
//     while ((line = get_next_line(fd)))  {  // Continue until EOF
//         printf("%s", line);  // Print the line (get_next_line already includes newline)
//         free(line);  // Don't forget to free the memory allocated by get_next_line
//     }
//     close(fd);  // Close the file descriptor
//     return 0;
// }
