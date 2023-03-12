#pragma once
#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <stdio.h>
#include <cmath>

__global__ void loop_kernel(int* d_results, int num_results) {
    int idx = blockIdx.x * blockDim.x + threadIdx.x;
    if (idx < num_results) {
        // do some computation
        int result = idx * 2;
        d_results[idx] = sqrtf(result);
    }
}

int doBigCalc()
{
    const int num_results = 100000000;
    const int num_threads_per_block = 256;
    const int num_blocks = (num_results + num_threads_per_block - 1) / num_threads_per_block;
    printf("num_results = %d\n", num_results);
    // allocate and initialize memory on the host
    int h_results[num_results];
    for (int i = 0; i < num_results; i++) {
        h_results[i] = 0;
    }

    // allocate memory on the device
    int* d_results;
    cudaMalloc((void**)&d_results, num_results * sizeof(int));

    // copy memory from host to device
    cudaMemcpy(d_results, h_results, num_results * sizeof(int), cudaMemcpyHostToDevice);

    // launch kernel
    loop_kernel <<<num_blocks, num_threads_per_block >>> (d_results, num_results);

    // copy memory from device to host
    cudaMemcpy(h_results, d_results, num_results * sizeof(int), cudaMemcpyDeviceToHost);

    // print out results
    //for (int i = 0; i < num_results; i++) {
    //    printf("result[%d] = %d\n", i, h_results[i]);
    //}

    printf("done");
    // free memory on device
    cudaFree(d_results);

    return 0;
}