#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

/**
 * append_text_to_file - Append text to the end of a file.
 * @filename: The name of the file to which text is appended.
 * @text_content: The text content to append to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content) {
    int fd, res, len;

    if (filename == NULL)
        return -1;

    fd = open(filename, O_WRONLY | O_APPEND);
    if (fd == -1)
        return -1;

    if (text_content != NULL) {
        len = 0;
        while (text_content[len] != '\0')
            len++;

        res = write(fd, text_content, len);
        if (res == -1) {
            close(fd);
            return -1;
        }
    }

    close(fd);
    return 1;
}
