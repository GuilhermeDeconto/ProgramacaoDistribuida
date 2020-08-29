#include <stdio.h>
#include <string.h>
#include "nbytes_nwords.h"
static int valor;
int * nbytes_1_svc(char **val, struct svc_req *rqstp)
{

    valor = strlen(*val);

	return &valor;
}
