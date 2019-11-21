__kernel void MatrixMultiple(__global int* A,__global int* B,
		__global int* C,__global int size){
		const int i = get_global_id(0);
		const int j = get_global_id(1);
		int temp;
		for(int k=0;k<size;k++){
			temp = A[k*size+i]*B[j*size+k];
		}
		C[j*size+i] = temp;
}
