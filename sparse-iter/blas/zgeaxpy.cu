/*
    -- MAGMA (version 1.1) --
       Univ. of Tennessee, Knoxville
       Univ. of California, Berkeley
       Univ. of Colorado, Denver
       @date

       @precisions normal z -> c d s

*/
#include "common_magma.h"
#include "common_magmasparse.h"

#define BLOCK_SIZE 256


// axpy kernel for matrices stored in the MAGMA format
__global__ void 
zgeaxpy_kernel( 
    int num_rows, 
    int num_cols, 
    magmaDoubleComplex alpha, 
    magmaDoubleComplex * dy, 
    magmaDoubleComplex beta, 
    magmaDoubleComplex * dx)
{
    int row = blockIdx.x*blockDim.x+threadIdx.x;
    int j;

    if( row<num_rows ){
        for( j=0; j<num_cols; j++ ){
            int idx = row + j*num_rows;
            dx[ idx ] = alpha * dx[ idx ] + beta * dy[ idx ];
        }
    }
}

/**
    Purpose
    -------
    
    This routine computes Y = alpha *  X + beta * Y on the GPU.
    The input format is a dense matrix (vector block) stored in 
    magma_z_matrix format.
    
    Arguments
    ---------

    @param[in]
    alpha       magmaDoubleComplex
                scalar multiplier.
                
    @param[in]
    Y           magma_z_matrix
                input/output matrix Y.
                
    @param[in]
    beta        magmaDoubleComplex
                scalar multiplier.
                
    @param[in,out]
    X           magma_z_matrix*
                input matrix X.
    @param[in]
    queue       magma_queue_t
                Queue to execute in.

    @ingroup magmasparse_zblas
    ********************************************************************/

extern "C" 
magma_int_t
magma_zgeaxpy(
    magmaDoubleComplex alpha,
    magma_z_matrix Y,
    magmaDoubleComplex beta,
    magma_z_matrix *X,
    magma_queue_t queue )
{
    int m = Y.num_rows;
    int n = Y.num_cols;
    dim3 grid( magma_ceildiv( m, BLOCK_SIZE ) );
    magma_int_t threads = BLOCK_SIZE;
    zgeaxpy_kernel<<< grid, threads, 0, queue >>>
                    ( m, n, alpha, Y.dval, beta, X->dval );
                    
    return MAGMA_SUCCESS;
}
