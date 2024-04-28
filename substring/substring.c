#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int is_valid_substr(char const *s, char const **words, int nb_words, int word_len, int start) {
    int *seen = calloc(nb_words, sizeof(int));
    int words_found = 0;

    for (int i = 0; i < nb_words; i++) {
        char *word = (char *)malloc((word_len + 1) * sizeof(char));
        strncpy(word, s + start + i * word_len, word_len);
        word[word_len] = '\0';

        for (int j = 0; j < nb_words; j++) {
            if (!seen[j] && strcmp(word, words[j]) == 0) {
                seen[j] = 1;
                words_found++;
                break;
            }
        }
        free(word);
    }

    free(seen);
    return words_found == nb_words;
}

int *find_substring(char const *s, char const **words, int nb_words, int *n) {
    if (!s || !words || nb_words <= 0) {
        *n = 0;
        return NULL;
    }

    int word_len = strlen(words[0]);
    int str_len = strlen(s);
    int substr_count = 0;
    int *indices = NULL;

    for (int i = 0; i <= str_len - nb_words * word_len; i++) {
        if (is_valid_substr(s, words, nb_words, word_len, i)) {
            substr_count++;
            indices = realloc(indices, substr_count * sizeof(int));
            indices[substr_count - 1] = i;
        }
    }

    *n = substr_count;
    return indices;
}
