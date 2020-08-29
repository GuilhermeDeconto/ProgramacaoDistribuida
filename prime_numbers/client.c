#include <stdio.h>
#include "primenumber.h"

/* função que chama a RPC add_1 */ 
int primenumber(CLIENT *clnt, int val) {
	int *result;

	/* chama a função remota */
	result = primenumber_1(&val, clnt);
	
	if (result == NULL) {
		printf ("Problemas ao chamar a função remota\n");
		
		return -1.0;
	}

	return (*result);
}

int main(int argc, char *argv[])
{
	CLIENT *clnt;
	int pi, val;

	if (argc != 3) {
		fprintf(stderr,"Uso:\n%s <nome_do_servidor> <numero>\n\n",argv[0]);
		
		return 1;
	}
	
	/* cria uma struct CLIENT que referencia uma interface RPC */
	clnt = clnt_create(argv[1], PRIMENUMBERPROG, PRIMENUMBERVERS, "udp");
	
	/* verifica se a referência foi criada */ 
	if (clnt == (CLIENT *)NULL) {
		clnt_pcreateerror(argv[1]);
		
		return 1;
	}
	
	/* executa os procedimentos remotos */
	val = atoi(argv[2]);
	pi = primenumber(clnt, val);

	if (pi)
		printf("Não é primo!\n");
	else
		printf("Primo!\n");
	
	return 0;
}
