#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE 256

int flag = 1;

int getword(char *word)
{
    int i = 0;
    char ch;
    ch = getchar();
    while ((ch != '\n') && (ch != '\t') && (ch != ' '))
    {
        if ((int)ch == EOF)
        {
            flag = 0;
            break;
        }
        *(word + i) = ch;
        i++;
        ch = getchar();
        if((int)ch< 32) ch = getchar();
    }
    *(word + i) = '\0';
    return i;
}

int getline2(char line[])
{
    int i = 0;
    char ch;
    ch = getchar();
    while (ch != '\n')
    {
        if ((int)ch == EOF)
        {
            flag = 0;
            break;
        }
        *(line + i) = ch;
        i++;
        ch = getchar();
    }
    return i;
}
int substring(const char *str1, const char *str2)
{
    char *p = strstr(str1, str2);
    if (p != NULL)
        return 1;
    return 0;
}
void printRightLines(const char *w)
{
    char line2[LINE];
    int a;
    while (flag)
    {
        getline2(line2);
        a = substring(line2, w);
        if (a == 1)
        {
            puts(line2);
        }
        bzero(line2, LINE);
    }
}

int similar(const char *p1, char *p2, int p2_len)
{
    size_t s1 = strlen(p1);
    if ((s1 > p2_len) || (p2_len > s1 + 1))
        return 0;
    if (s1 == p2_len)
    {
        if (strcmp(p1, p2) == 0)
            return 1;
        return 0;
    }
    int mone = 0, j = 0;
    for (size_t i = 0; i < p2_len; i++)
    {
        if (*(p1 + j) == *(p2 + i))
        {
            mone++;
            j++;
        }
    }
    if (mone == s1)
        return 1;
    return 0;
}

void printRightWords(const char *w)
{
    int w_le = 0, a;
    char word[LINE];
    while (flag)
    {
        w_le = getword(word);
        a = similar(w, word, w_le);
        if (a == 1)
            puts(word);
        bzero(word, LINE);
    }
}

int main()
{
    char line[LINE];
    int mone = 0, p_length = 0;
    char *word, option;
    while (flag)
    {
        if (mone == 2)
            break;
        getline2(line);
        mone++;
        if (mone == 1)
        {
            for (size_t i = 0; i < LINE; i++)
            {
                if (*(line + i) != ' ')
                    p_length++;
                else
                    break;
            }
            word = (char *)malloc((size_t)p_length + 1);
            for (size_t i = 0; i < p_length; i++)
                *(word + i) = *(line + i);
            *(word + p_length) = '\0';
            option = *(line+p_length+1);
        }
        bzero(line, LINE);
    }
    if (option == 'a')
    {
        printRightLines(word);
    }
    if (option == 'b')
    {
        printRightWords(word);
    }
    free(word);
    return 0;
}
