/*
   -- MAGMA (version 2.0) --
   Univ. of Tennessee, Knoxville
   Univ. of California, Berkeley
   Univ. of Colorado, Denver
   @date

   @author Ahmad Abdelfattah

   @precisions normal z -> s d c
*/

#include "magma_internal.h"
#include "batched_kernel_param.h"

/***************************************************************************//**
    Purpose
    -------
    ZGBTRS solves a system of linear equations
    A * X = B,  A**T * X = B,  or  A**H * X = B with a general band matrix A
    using the LU factorization computed by ZGBTRF.

    This is the batched version of the routine.
    Currently, only (A * X = B) is supported (no-trans only)

    Arguments
    ---------
    @param[in]
    transA  magma_trans_t
            Specifies the form of the system of equations.
            Currently, only MagnaNoTrans is supported (A*X = B)

    @param[in]
    n       INTEGER
            The order of the matrix A.  n >= 0.

    @param[in]
    kl      INTEGER
            The number of subdiagonals within the band of A.  KL >= 0.

    @param[in]
    ku      INTEGER
            The number of superdiagonals within the band of A.  KL >= 0.

    @param[in]
    nrhs    INTEGER
            The number of right hand sides, i.e., the number of columns
            of the matrix B.  NRHS >= 0.

    @param[in]
    dA_array    Array of pointers, dimension (batchCount).
                Each contains the details of the LU factorization of the band matrix A,
                as computed by ZGBTRF.  U is stored as an upper triangular band
                matrix with KL+KU superdiagonals in rows 1 to KL+KU+1, and
                the multipliers used during the factorization are stored in
                rows KL+KU+2 to 2*KL+KU+1.

    @param[in]
    ldda    INTEGER
            The leading dimension of each array A.  LDDA >= (2*KL+KU+1).

    @param[in]
    dipiv_array  Array of pointers, dimension (batchCount), for corresponding matrices.
            Each is an INTEGER array, dimension (min(M,N))
            The pivot indices; for 1 <= i <= min(M,N), row i of the
            matrix was interchanged with row IPIV(i).

    @param[in,out]
    dB_array    Array of pointers, dimension (batchCount).
                Each is a COMPLEX*16 array, dimension (LDB,NRHS)
                On entry, the right hand side matrix B.
                On exit, the solution matrix X.

    @param[in]
    lddb    INTEGER
            The leading dimension of each array B.  LDDB >= max(1, N).

    @param[out]
    info_array  Array of INTEGERs, dimension (batchCount), for corresponding matrices.
      -     = 0:  successful exit
      -     < 0:  if INFO = -i, the i-th argument had an illegal value
                  or another error occured, such as memory allocation failed.

    @param[in]
    batchCount  INTEGER
                The number of matrices to operate on.

    @param[in]
    queue   magma_queue_t
            Queue to execute in.

    @ingroup magma_getrf_batched
*******************************************************************************/
extern "C" magma_int_t
magma_zgbtrs_batched(
    magma_trans_t transA,
    magma_int_t n, magma_int_t kl, magma_int_t ku, magma_int_t nrhs,
    magmaDoubleComplex **dA_array, magma_int_t ldda, magma_int_t **dipiv_array,
    magmaDoubleCompplex** dB_array, magma_int_t lddb,
    magma_int_t *info_array,
    magma_int_t batchCount, magma_queue_t queue)
{
#define dA_array(i, j)    dA_array, i, j
#define dB_array(i, j)    dB_array, i, j

    magma_int_t kv = kl + ku;

    // apply L^(-1) as a series of row interchanges and rank-1 updates
    for(magma_int_t j = 0; j < N; j++) {
        // swap
        magmablas_zgbtrs_swap_batched(nrhs, dB_array, lddb, dipiv_array, j, batchCount, queue);

        // geru
        magmablas_zgeru_batched_core(
            min(kl, n-j), nrhs,
            MAGMA_Z_NEG_ONE,
            dA_array(kv+1, j), ldda, 1,
            dB_array(j   , 0), lddb, lddb,
            dB_array(j+1 , 0), lddb,
            batchCount, queue );
    }

#undef dA_array
#undef dB_array
}
