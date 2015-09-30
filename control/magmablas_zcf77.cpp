/*******************************************************************************
 *  This file is AUTOMATICALLY GENERATED by:
 *  ../tools/fortran_wrappers.pl ../include/magmablas_zc.i
 *  Do not edit.
 ******************************************************************************/

#include <stdint.h>  // for uintptr_t

#include "magma.h"
#include "magma_mangling.h"

/*
 * typedef comming from fortran.h file provided in CUDADIR/src directory
 * it will probably change with future release of CUDA when they use 64 bit addresses
 */
typedef size_t devptr_t;

#ifdef PGI_FORTRAN
    #define magma_idevptr(ptr_) ((int*)               (ptr_))
    #define magma_zdevptr(ptr_) ((magmaDoubleComplex*)(ptr_))
    #define magma_cdevptr(ptr_) ((magmaFloatComplex*) (ptr_))
    #define magma_ddevptr(ptr_) ((double*)            (ptr_))
    #define magma_sdevptr(ptr_) ((float*)             (ptr_))
#else
    #define magma_idevptr(ptr_) ((int*)               (uintptr_t)(*(ptr_)))
    #define magma_zdevptr(ptr_) ((magmaDoubleComplex*)(uintptr_t)(*(ptr_)))
    #define magma_cdevptr(ptr_) ((magmaFloatComplex*) (uintptr_t)(*(ptr_)))
    #define magma_ddevptr(ptr_) ((double*)            (uintptr_t)(*(ptr_)))
    #define magma_sdevptr(ptr_) ((float*)             (uintptr_t)(*(ptr_)))
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define magmablasf_zcaxpycp FORTRAN_NAME( magmablasf_zcaxpycp, MAGMABLASF_ZCAXPYCP )
void magmablasf_zcaxpycp(
    magma_int_t *m,
    devptr_t *r,
    devptr_t *x,
    devptr_t *b,
    devptr_t *w )
{
    magmablas_zcaxpycp(
        *m,
        magma_cdevptr(r),
        magma_zdevptr(x),
        magma_zdevptr(b),
        magma_zdevptr(w) );
}

#define magmablasf_zclaswp FORTRAN_NAME( magmablasf_zclaswp, MAGMABLASF_ZCLASWP )
void magmablasf_zclaswp(
    magma_int_t *n,
    devptr_t *A, magma_int_t *lda,
    devptr_t *SA, magma_int_t *m,
    magma_int_t *ipiv, magma_int_t *incx )
{
    magmablas_zclaswp(
        *n,
        magma_zdevptr(A), *lda,
        magma_cdevptr(SA), *m,
        ipiv, *incx );
}

#define magmablasf_zlag2c FORTRAN_NAME( magmablasf_zlag2c, MAGMABLASF_ZLAG2C )
void magmablasf_zlag2c(
    magma_int_t *m, magma_int_t *n,
    devptr_t *A, magma_int_t *lda,
    devptr_t *SA, magma_int_t *ldsa,
    magma_int_t *info )
{
    magmablas_zlag2c(
        *m, *n,
        magma_zdevptr(A), *lda,
        magma_cdevptr(SA), *ldsa,
        info );
}

#define magmablasf_clag2z FORTRAN_NAME( magmablasf_clag2z, MAGMABLASF_CLAG2Z )
void magmablasf_clag2z(
    magma_int_t *m, magma_int_t *n,
    devptr_t *SA, magma_int_t *ldsa,
    devptr_t *A, magma_int_t *lda,
    magma_int_t *info )
{
    magmablas_clag2z(
        *m, *n,
        magma_cdevptr(SA), *ldsa,
        magma_zdevptr(A), *lda,
        info );
}

#define magmablasf_zlat2c FORTRAN_NAME( magmablasf_zlat2c, MAGMABLASF_ZLAT2C )
void magmablasf_zlat2c(
    const char* uplo, magma_int_t *n,
    devptr_t *A, magma_int_t *lda,
    devptr_t *SA, magma_int_t *ldsa,
    magma_int_t *info )
{
    magmablas_zlat2c(
        magma_uplo_const(*uplo), *n,
        magma_zdevptr(A), *lda,
        magma_cdevptr(SA), *ldsa,
        info );
}

#define magmablasf_clat2z FORTRAN_NAME( magmablasf_clat2z, MAGMABLASF_CLAT2Z )
void magmablasf_clat2z(
    const char* uplo, magma_int_t *n,
    devptr_t *SA, magma_int_t *ldsa,
    devptr_t *A, magma_int_t *lda,
    magma_int_t *info )
{
    magmablas_clat2z(
        magma_uplo_const(*uplo), *n,
        magma_cdevptr(SA), *ldsa,
        magma_zdevptr(A), *lda,
        info );
}


#ifdef __cplusplus
}
#endif
