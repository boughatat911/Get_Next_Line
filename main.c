#include "get_next_line.h"

#include "get_next_line_bonus.h"
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
// int main()
// {
//     int fd;
//     char *buff;

//     fd = open("vb.txt",O_RDWR);
//     // buff = get_next_line(fd);
//     while ((buff = get_next_line(fd))!= NULL)
//     {
//     printf("%s",buff);
//         /* code */
//     }
//     close(fd);
//     printf("\n");
//     fd = open("t.txt",O_RDWR);
//     // buff = get_next_line(fd);
//     while ((buff = get_next_line(fd))!= NULL)
//     {
//     printf("%s",buff);
//         /* code */
//     }

    
// }

int main(void)
{
    // int fd;
    char *line;

    // Open a file for testing
    int fd = open("vb.txt", O_RDONLY);  // Change "test.txt" to the path of your test file

   line = get_next_line_bonus(fd);
    
        printf("%s", line);
        free(line);  // Don't forget to free each line!
   
    printf("\n");
    fd = open("t.txt", O_RDONLY);  // Change "test.txt" to the path of your test file

    // Read and print lines from the file
   line = get_next_line_bonus(fd);

        printf("%s", line);
        free(line);  // Don't forget to free each line!
    //  fd = open("vb.txt", O_RDONLY);  // Change "test.txt" to the path of your test file

   line = get_next_line(fd);
    
        printf("%s", line);

    close(fd);  // Close the file after reading
    return 0;
}