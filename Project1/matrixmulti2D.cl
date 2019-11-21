__kernel void MatrixMultiple2D(__global int* A,__global int* B,
		__global int* C,__global int* n){
		const int i = get_global_id(0);
		const int j = get_global_id(1);
		int localsize_x = get_local_size(0);
		int localsize_y = get_local_size(1);
		int gridsize = get_num_groups(0) * get_local_size(0);
		int size = *n;
		int temp=0;	
		printf("localsize_x=>%d\n",localsize_x);
		printf("localsize_y=>%d\n",localsize_y);
		printf("get_num_groups(0)=>%d\n",get_num_groups(0));
		printf("get_num_groups(1)=>%d\n",get_num_groups(1));
		printf("get_local_size(0)=>%d\n",get_local_size(0));
		printf("gridsize=>%d\n",gridsize);
		for(int k=0;k<size;k++){			
			temp += A[i*size+k]*B[k*size+j];
		}
		C[i*size+j] = temp;
}
