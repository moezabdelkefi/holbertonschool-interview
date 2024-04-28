#include <stdlib.h>
#include <string.h>

int *find_substring(char const *s, char const **words, int nb_words, int *n) {
    int len, slen, i, j, k, found, start;
    int *result, *map, *tmp;

    *n = 0;
    len = strlen(words[0]);
    slen = strlen(s);
    result = malloc(slen * sizeof(int));
    map = malloc(nb_words * sizeof(int));
    tmp = malloc(nb_words * sizeof(int));

    for (i = 0; i < nb_words; i++) {
        for (j = i + 1; j < nb_words; j++) {
            if (strcmp(words[i], words[j]) == 0)
                map[i]++;
        }
    }

    for (i = 0; i <= slen - nb_words * len; i++) {
        memcpy(tmp, map, nb_words * sizeof(int));
        for (j = 0; j < nb_words; j++) {
            found = 0;
            for (k = 0; k < nb_words; k++) {
                start = i + j * len;
                if (tmp[k] > 0 && strncmp(s + start, words[k], len) == 0) {
                    found = 1;
                    tmp[k]--;
                    break;
                }
            }
            if (found == 0)
                break;
        }
        if (j == nb_words)
            result[(*n)++] = i;
    }

    free(map);
    free(tmp);
    return result;
}