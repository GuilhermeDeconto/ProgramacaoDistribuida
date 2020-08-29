all:
	rpcgen nbytes_nwords.x
	gcc server.c nbytes_nwords_svc.c -o server -lnsl
	gcc client.c nbytes_nwords_clnt.c -o client -lnsl

clean:
	rm -f client server nbytes_nwords_svc.c nbytes_nwords_clnt.c nbytes_nwords_xdr.c nbytes_nwords.h
