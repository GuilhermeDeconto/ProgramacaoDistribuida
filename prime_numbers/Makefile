all:
	rpcgen primenumber.x
	gcc server.c primenumber_svc.c -o server -lnsl
	gcc client.c primenumber_clnt.c -o client -lnsl

clean:
	rm -f client server primenumber_svc.c primenumber_clnt.c primenumber_xdr.c primenumber.h
