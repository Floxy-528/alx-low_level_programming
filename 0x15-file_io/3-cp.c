#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

#define BUFFER_SIZE 1024

/**
 * print_error - prints an error message and exits with an error code
 * @err: error code
 * @msg: error message
 */
void print_error(int err, char *msg) {
    dprintf(STDERR_FILENO, "Error: %s: %s\n", msg, strerror(err));
    exit(err);
}

/**
 * main - copies content of one file to another
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, various error codes on failure
 */
int main(int argc, char *argv[]) {
    int fd_from, fd_to, read_chars, write_chars;
    char buffer[BUFFER_SIZE];
    struct stat st;

    if (argc != 3) {
        dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
        exit(97);
    }

    fd_from = open(argv[1], O_RDONLY);
    if (fd_from == -1) {
        print_error(98, argv[1]);
    }

    if (fstat(fd_from, &st) == -1) {
        print_error(98, argv[1]);
    }

    fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd_to == -1) {
        print_error(99, argv[2]);
    }

    while ((read_chars = read(fd_from, buffer, BUFFER_SIZE)) > 0) {
        write_chars = write(fd_to, buffer, read_chars);
        if (write_chars == -1 || write_chars != read_chars) {
            print_error(99, argv[2]);
        }
    }

    if (read_chars == -1) {
        print_error(98, argv[1]);
    }

    if (close(fd_from) == -1) {
        print_error(100, argv[1]);
    }
    if (close(fd_to) == -1) {
        print_error(100, argv[2]);
    }

    return 0;
}
