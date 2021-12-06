#include "main.h"

char *_strtok(char *str, char *delim)
{
    static char *token;
    char *res;
    static int position;
    int cont, i, j, flag = 0;
    
    if (str != NULL)
        token = str, position = 0;
    if (token == NULL || delim == NULL)
        return (NULL);
    if (position >= _strlen(token))
        return (NULL);
    cont = 0;
    for (i = position; token[i]; i++)
    {
        for (j = 0; delim[j]; j++)
        {
            if (token[i] == delim[j])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
            break;
        cont++;
    } 
    res = malloc(sizeof(char) * (cont + 1));
    if (!res)
        return (NULL);
    for (i = 0; i < cont; i++)
        res[i] = token[position + i];
    res[i] = '\0';
    position += cont + 1;
    return (res);
}
