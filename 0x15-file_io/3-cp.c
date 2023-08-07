#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * main - Copy the content of a file to another file.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 *
 * Return: 0 on success, or exit with appropriate error codes.
 */
int main(int argc, char **argv) {
    int fd_from, fd_to, res;
    char buffer[1024];
    ssize_t bytes_read, bytes_written;

    if (argc != 3) {
        dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
        exit(97);
    }

    fd_from = open(argv[1], O_RDONLY);
    if (fd_from == -1) {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
        exit(98);
    }

    fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
    if (fd_to == -1) {
        dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
        close(fd_from);
        exit(99);
    }

    while ((bytes_read = read(fd_from, buffer, sizeof(buffer))) > 0) {
        bytes_written = write(fd_to, buffer, bytes_read);
        if (bytes_written == -1 || bytes_written != bytes_read) {
            dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
            close(fd_from);
            close(fd_to);
            exit(99);
        }
    }

    if (bytes_read == -1) {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
        close(fd_from);
        close(fd_to);
        exit(98);
    }

    res = close(fd_from);
    if (res == -1) {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
        exit(100);
    }

    res = close(fd_to);
    if (res == -1) {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
        exit(100);
    }

    return 0;
}
