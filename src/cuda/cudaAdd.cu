#include "add.h"
#include <cuda_runtime.h>
#include <iostream>


__global__ void add_kernel(int a, int b, int* c)
{
    *c = a + b;
}

void add_GPU(int a, int b, int* c)
{

    int* d_c;
    cudaError_t err;
    err = cudaMalloc((void **)&d_c, sizeof(int));
    if (err != cudaSuccess) 
    {
        std::cerr << "Failed to allocate device memory" << cudaGetErrorString(err) << std::endl;
        exit(EXIT_FAILURE);
    }
    add_kernel<<<1, 1>>>(a, b, d_c);
    err = cudaPeekAtLastError();
    if (err != cudaSuccess) 
    {
        std::cerr << "Kernel launch failed" <<  cudaGetErrorString(err) << std::endl;
        cudaFree(d_c); 
        exit(EXIT_FAILURE);
    }
    err = cudaDeviceSynchronize();
    if (err != cudaSuccess) 
    {
        std::cerr << "Kernel execution failed" << cudaGetErrorString(err) << std::endl;
        cudaFree(d_c); 
        exit(EXIT_FAILURE);
    }
    err = cudaMemcpy(c, d_c, sizeof(int), cudaMemcpyDeviceToHost);
    if (err != cudaSuccess) 
    {
        std::cerr << "Failed to copy data from device to host" << cudaGetErrorString(err) << std::endl;
        cudaFree(d_c);  
        exit(EXIT_FAILURE);
    }
    cudaFree(d_c);
    std::cerr << "GPU" << std::endl;
}

