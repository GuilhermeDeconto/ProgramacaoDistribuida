/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _PRIMENUMBER_H_RPCGEN
#define _PRIMENUMBER_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


#define PRIMENUMBERPROG 0x20000000
#define PRIMENUMBERVERS 1

#if defined(__STDC__) || defined(__cplusplus)
#define PRIMENUMBER 1
extern  int * primenumber_1(int *, CLIENT *);
extern  int * primenumber_1_svc(int *, struct svc_req *);
extern int primenumberprog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define PRIMENUMBER 1
extern  int * primenumber_1();
extern  int * primenumber_1_svc();
extern int primenumberprog_1_freeresult ();
#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_PRIMENUMBER_H_RPCGEN */
