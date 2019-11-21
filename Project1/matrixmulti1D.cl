__kernel void MatrixMultiple1D(__global int* A,__global int* B,
		__global int* C,__global int* n){
		const int i = get_global_id(0);
		const int local_x_size = get_local_id(0);
		int x = i/5;
		int y = i%5;
		int size = *n;
		int temp=0;	
		printf("local_x=>%d\n",local_x_size);
		for(int k=0;k<size;k++){
			if(x==2&&y==2)
			{
				printf("A[%d]*B[%d]=%d\n",k*size+x,y*size+k,(A[k*size+x]*B[y*size+k]));
			}
			temp += A[x*size+k]*B[k*size+y];
		}
		C[x*size+y] = temp;
}
