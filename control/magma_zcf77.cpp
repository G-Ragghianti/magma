/*******************************************************************************
 *  This file is AUTOMATICALLY GENERATED by:
 *  ../tools/fortran_wrappers.pl ../include/magma_zc.i
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

#define magmaf_zcgesv_gpu FORTRAN_NAME( magmaf_zcgesv_gpu, MAGMAF_ZCGESV_GPU )
void magmaf_zcgesv_gpu(
    const char* trans, magma_int_t *n, magma_int_t *nrhs,
    devptr_t *dA, magma_int_t *ldda,
    magma_int_t *ipiv,
    devptr_t *dipiv,
    devptr_t *dB, magma_int_t *lddb,
    devptr_t *dX, magma_int_t *lddx,
    devptr_t *dworkd,
    devptr_t *dworks,
    magma_int_t *iter,
    magma_int_t *info )
{
    magma_zcgesv_gpu(
        magma_trans_const(*trans), *n, *nrhs,
        magma_zdevptr(dA), *ldda,
        ipiv,
        magma_idevptr(dipiv),
        magma_zdevptr(dB), *lddb,
        magma_zdevptr(dX), *lddx,
        magma_zdevptr(dworkd),
        magma_cdevptr(dworks),
        iter,
        info );
}

#define magmaf_zcgetrs_gpu FORTRAN_NAME( magmaf_zcgetrs_gpu, MAGMAF_ZCGETRS_GPU )
void magmaf_zcgetrs_gpu(
    const char* trans, magma_int_t *n, magma_int_t *nrhs,
    devptr_t *dA, magma_int_t *ldda,
    devptr_t *dipiv,
    devptr_t *dB, magma_int_t *lddb,
    devptr_t *dX, magma_int_t *lddx,
    devptr_t *dSX,
    magma_int_t *info )
{
    magma_zcgetrs_gpu(
        magma_trans_const(*trans), *n, *nrhs,
        magma_cdevptr(dA), *ldda,
        magma_idevptr(dipiv),
        magma_zdevptr(dB), *lddb,
        magma_zdevptr(dX), *lddx,
        magma_cdevptr(dSX),
        info );
}

#define magmaf_zcposv_gpu FORTRAN_NAME( magmaf_zcposv_gpu, MAGMAF_ZCPOSV_GPU )
void magmaf_zcposv_gpu(
    const char* uplo, magma_int_t *n, magma_int_t *nrhs,
    devptr_t *dA, magma_int_t *ldda,
    devptr_t *dB, magma_int_t *lddb,
    devptr_t *dX, magma_int_t *lddx,
    devptr_t *dworkd,
    devptr_t *dworks,
    magma_int_t *iter,
    magma_int_t *info )
{
    magma_zcposv_gpu(
        magma_uplo_const(*uplo), *n, *nrhs,
        magma_zdevptr(dA), *ldda,
        magma_zdevptr(dB), *lddb,
        magma_zdevptr(dX), *lddx,
        magma_zdevptr(dworkd),
        magma_cdevptr(dworks),
        iter,
        info );
}

#define magmaf_zcgeqrsv_gpu FORTRAN_NAME( magmaf_zcgeqrsv_gpu, MAGMAF_ZCGEQRSV_GPU )
void magmaf_zcgeqrsv_gpu(
    magma_int_t *m, magma_int_t *n, magma_int_t *nrhs,
    devptr_t *dA, magma_int_t *ldda,
    devptr_t *dB, magma_int_t *lddb,
    devptr_t *dX, magma_int_t *lddx,
    magma_int_t *iter,
    magma_int_t *info )
{
    magma_zcgeqrsv_gpu(
        *m, *n, *nrhs,
        magma_zdevptr(dA), *ldda,
        magma_zdevptr(dB), *lddb,
        magma_zdevptr(dX), *lddx,
        iter,
        info );
}


#ifdef __cplusplus
}
#endif
