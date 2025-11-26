#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFSIZE 1024

/**
 * close_fd - closes a file descriptor
 * @fd: file descriptor
 */
void close_fd(int fd)
{
if (close(fd) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
exit(100);
}
}

/**
 * open_from - opens source file for reading
 * @path: source path
 *
 * Return: file descriptor
 */
int open_from(char *path)
{
int fd;

fd = open(path, O_RDONLY);
if (fd == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", path);
exit(98);
}
return (fd);
}

/**
 * open_to - opens destination file for writing
 * @path: destination path
 *
 * Return: file descriptor
 */
int open_to(char *path)
{
int fd;

fd = open(path, O_CREAT | O_WRONLY | O_TRUNC, 0664);
if (fd == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", path);
exit(99);
}
return (fd);
}

/**
 * copy_loop - copies from fd_from to fd_to
 * @fd_from: source descriptor
 * @fd_to: destination descriptor
 * @name_from: source name
 * @name_to: destination name
 */
void copy_loop(int fd_from, int fd_to, char *name_from, char *name_to)
{
ssize_t r, w, total;
char buffer[BUFSIZE];

while ((r = read(fd_from, buffer, BUFSIZE)) > 0)
{
total = 0;
while (total < r)
{
w = write(fd_to, buffer + total, r - total);
if (w == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", name_to);
close_fd(fd_from);
close_fd(fd_to);
exit(99);
}
total += w;
}
}
if (r == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", name_from);
close_fd(fd_from);
close_fd(fd_to);
exit(98);
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

if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}
fd_from = open_from(argv[1]);
fd_to = open_to(argv[2]);
copy_loop(fd_from, fd_to, argv[1], argv[2]);
close_fd(fd_from);
close_fd(fd_to);
return (0);
}
