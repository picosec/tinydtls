#ifndef _CONFIG_H_
#define _CONFIG_H_

#include "contiki.h"
#include "contiki-lib.h"
#include "contiki-net.h"

#define WITH_CONTIKI 1

#define DEBUG DEBUG_NONE
#define HAVE_STRNLEN 1
#define HAVE_SNPRINTF 1
#define HAVE_VPRINTF 1

#define NDEBUG

#ifdef DTLS_CONF_CONN_TIMEOUT
#define DTLS_CONN_TIMEOUT DTLS_CONF_CONN_TIMEOUT
#else
#define DTLS_CONN_TIMEOUT 10
#endif

#ifndef DTLS_PEER_MAX
/** The maximum number DTLS peers (i.e. sessions). */
#  define DTLS_PEER_MAX 1
#endif

#ifndef DTLS_CIPHER_CONTEXT_MAX
/** The maximum number of cipher contexts that can be used in parallel. */
#  define DTLS_CIPHER_CONTEXT_MAX (2 * DTLS_PEER_MAX)
#endif

#ifndef DTLS_HASH_MAX
/** The maximum number of hash functions that can be used in parallel. */
#  define DTLS_HASH_MAX (3 * DTLS_PEER_MAX)
#endif

/** The maximum buffer size to hold DTLS messages */
#define DTLS_MAX_BUF 100

#include "contiki-conf.h"

#if CONTIKI_TARGET_REDBEE_ECONOTAG
/* Redbee econotags get a special treatment here: endianness is set explicitly */ 

/* #define BYTE_ORDER UIP_LITTLE_ENDIAN */

#undef HAVE_ASSERT_H
#define assert(x)
#define HAVE_UNISTD_H
#endif /* CONTIKI_TARGET_REDBEE_ECONOTAG */

#ifdef CONTIKI_TARGET_MBXXX
/* ST Microelectronics */ 

#define BYTE_ORDER 1234
#endif /* CONTIKI_TARGET_MBXXX */

#ifdef CONTIKI_TARGET_MINIMAL_NET
#undef HAVE_ASSERT_H
#define assert(x)
#define HAVE_VPRINTF
#endif /* CONTIKI_TARGET_MINIMAL_NET */

#if defined(TMOTE_SKY)
/* Need to set the byte order for TMote Sky explicitely */

#define BYTE_ORDER UIP_LITTLE_ENDIAN

typedef int ssize_t;
#undef HAVE_ASSERT_H
#endif /* defined(TMOTE_SKY) */

#ifndef BYTE_ORDER
# ifdef UIP_BYTE_ORDER
#  define BYTE_ORDER UIP_BYTE_ORDER
# else
#  error "UIP_BYTE_ORDER not defined"
# endif /* UIP_BYTE_ORDER */
#endif /* BYTE_ORDER */

#endif /* _CONFIG_H_ */

