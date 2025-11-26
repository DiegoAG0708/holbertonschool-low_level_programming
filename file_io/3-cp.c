#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFSIZE 1024

/**
 * safe_close - closes a file descriptor
 * @fd: file descriptor
 *
 * Return: void
 */
static void safe_close(int fd)
{
if (close(fd) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
exit(100);
}
}

/**
 * main - copies content of one file to another
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
int fd_from, fd_to;
ssize_t r, w, total;
char buffer[BUFSIZE];

if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}
fd_from = open(argv[1], O_RDONLY);
if (fd_from == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
exit(98);
}
fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
if (fd_to == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
safe_close(fd_from);
exit(99);
}
while ((r = read(fd_from, buffer, BUFSIZE)) > 0)
{
total = 0;
while (total < r)
{
w = write(fd_to, buffer + total, r - total);
if (w == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
safe_close(fd_from);
safe_close(fd_to);
exit(99);
}
total += w;
}
}
if (r == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
safe_close(fd_from);
safe_close(fd_to);
exit(98);
}
safe_close(fd_from);
safe_close(fd_to);
return (0);
}
