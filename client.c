#include <stdio.h>
#include "nbytes_nwords.h"

/* função que chama a RPC add_1 */ 
int nbytes(CLIENT *clnt, char *val) {
	int *result;

	/* chama a função remota */
	result = nbytes_1(&val, clnt);

	if (result == NULL) {
		printf ("Problemas ao chamar a função remota\n");
		
		return -1.0;
	}

	return (*result);
}

int main(int argc, char *argv[])
{
	CLIENT *clnt;
	int pi;

	if (argc != 3) {
		fprintf(stderr,"Uso:\n%s <nome_do_servidor> <numero>\n\n",argv[0]);
		
		return 1;
	}
	
	/* cria uma struct CLIENT que referencia uma interface RPC */
	clnt = clnt_create(argv[1], NBYTESNWORDSPROG, NBYTESNWORDSVERS, "udp");
	
	/* verifica se a referência foi criada */ 
	if (clnt == (CLIENT *)NULL) {
		clnt_pcreateerror(argv[1]);
		
		return 1;
	}
	
	/* executa os procedimentos remotos */
	pi = nbytes(clnt, argv[2]);

	printf("%i", pi);
	
	return 0;
}
