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

int nwords(CLIENT *clnt, char *val) {
	int *result;

	/* chama a função remota */
	result = nwords_1(&val, clnt);

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
	
	/* cria uma struct CLIENT que referencia uma interface RPC */
	clnt = clnt_create(argv[1], NBYTESNWORDSPROG, NBYTESNWORDSVERS, "udp");
	
	/* verifica se a referência foi criada */ 
	if (clnt == (CLIENT *)NULL) {
		clnt_pcreateerror(argv[1]);
		
		return 1;
	}
	
	/* executa os procedimentos remotos */
	

	int j = 0;
    char *cmdstring;
	cmdstring = malloc(200);
    cmdstring[0] = '\0';

    for (j=2; j<argc; j++) {
        strcat(cmdstring, argv[j]);
        if (argc > j+1)
            strcat(cmdstring, " ");
    }

    printf("cmdstring: %s\n", cmdstring);
	pi = nbytes(clnt, cmdstring);
	int words = nwords(clnt, cmdstring);

	printf("\nA string possui %i bytes\n", pi);
	printf("A string tem %i palavras\n", words);
	
	return 0;
}
