#include <stdio.h>
#include <string.h>
#include "primenumber.h"
static int valor;
int * primenumber_1_svc(int *val, struct svc_req *rqstp)
{
	valor = 0;
	static int um = 1;
	int i;
	if (*val == 1){return &um;}
	for (i = 2; i <= *val/2; i++){
		if(*val % i == 0){
			valor ++;
			break;
		}
	}
	return &valor;
}
