#include <stdio.h>
#include <string.h>
#include "nbytes_nwords.h"
#include <ctype.h>
static int valor;
static int count;
int * nbytes_1_svc(char **val, struct svc_req *rqstp)
{

    valor = strlen(*val);

	return &valor;
}


int * nwords_1_svc(char **val, struct svc_req *rqstp)
{
    int charCount = strlen(*val);
    char *a ;
    a = malloc(charCount);

    int i;

    strcpy(a, *val);

    int cont_palavras = 1;
    for ( i = 0; i < charCount; i++) {
        int space = isspace(a[i]);
        if (space) {
            cont_palavras++;
        }
    }
    count = cont_palavras;
    return &count;
}
