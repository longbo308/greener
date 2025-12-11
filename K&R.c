#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000
#define MAXLEN 1000

int getline(char *s, int lim);
char *lineptr[MAXLINES];

void str_cpy(char *s, char *t) {
    while ((*s = *t) != '\0') {
        s++;
        t++;
    }
}

void strcpy2(char *s, char *t) {
    while ((*s++ = *t++))
        ;
}

int strcmp1(char *s, char *t) {
    while (*s++ == *t++)
        ;
    return *(s - 1) - *(t - 1);
}

int strend(char *s, char *t) {
    while (*s++)
        ;
    return s == t ? 1 : 0;
}

int readlines(char *lineptr[], int maxlines) {
    int len, nlines;
    char *p, line[MAXLEN];
    nlines = 0;

    while ((len = getline(line, MAXLEN)) > 0) {
        if (nlines >= maxlines)
            return -1;

        /* 去掉末尾的换行（如果有）并计算需要的空间 */
        if (len > 0 && line[len - 1] == '\n')
            line[len - 1] = '\0';

        size_t need = strlen(line) + 1;
        p = malloc(need);
        if (p == NULL)
            return -1;

        strcpy(p, line);
        lineptr[nlines++] = p;
    }
    return nlines;
}

int getline(char *s, int lim) {
    int c;
    int line = 0;
    while ((c = getchar()) != EOF && c != '\n' && line < lim - 1) {
        *s++ = (char)c;
        line++;
    }
    if (c == '\n') {
        *s++ = (char)c;
        line++;
    }
    *s = '\0';
    return line;
}

void writelines(char *lineptr[], int nlines) {
    int i;
    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}

void qsort1(char *v[], int left, int right) {
    int i, last;
    void swap(char *v[], int i, int j);
    if (left >= right)
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort1(v, left, last - 1);
    qsort1(v, last + 1, right);
}

void swap(char *v[], int i, int j) {
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int main() {
    int nlines;
    int i;

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort1(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);

        /* 释放分配的行内存 */
        for (i = 0; i < nlines; ++i)
            free(lineptr[i]);

        return 0;
    } else {
        printf("error: input too big to sort or allocation failed\n");
        return 1;
    }
}