/*
** EPITECH PROJECT, 2026
** user
** File description:
** user
*/

#include "../include/my.h"
#include "../include/top.h"

static char *found_good_line(char **str, char *uid, int *i)
{
    char **tmp;
    char *user;

    if (str[*i] == NULL)
        return NULL;
    tmp = my_str_to_word_array_delim(str[*i], ':');
    if (tmp[2] != NULL && my_strcmp(tmp[2], uid)) {
        user = malloc(sizeof(char) * (my_strlen(tmp[0]) + 1));
        my_strcpy(user, tmp[0]);
        user[my_strlen(tmp[0])] = '\0';
        free_all(tmp);
        return user;
    }
    free_all(tmp);
    *i += 1;
    return found_good_line(str, uid, i);
}

char *user_return(char *uid)
{
    char **str = read_file("/etc/passwd");
    char *nb = uid;
    char *user;
    int i = 0;

    if (my_strcmp(uid, "4294967295")){
        free_all(str);
        free(nb);
        return "root";
    }
    user = found_good_line(str, nb, &i);
    free(nb);
    free_all(str);
    return user;
}

char *user_process(char *pid)
{
    int fd;
    ssize_t bytes;
    char *uid_str;
    char path[50] = "/proc/";

    my_strcat(path, pid);
    my_strcat(path, "/loginuid");
    fd = open(path, O_RDONLY);
    if (fd < 0)
        return NULL;
    uid_str = malloc(100);
    if (!uid_str) {
        close(fd);
        return NULL;
    }
    bytes = read(fd, uid_str, 99);
    close(fd);
    uid_str[bytes] = '\0';
    return user_return(uid_str);
}
