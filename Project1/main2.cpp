//#define CL_USE_DEPRECATED_OPENCL_1_2_APIS
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <CL/cl.hpp>
//#define MAX_SOURCE_SIZE (0x100000)
//#define MEM_SIZE (128)
//#define Array_Size 128 
//
//
//int main() {
//	cl_context context = 0;
//	cl_command_queue queue = 0;
//	cl_program program = 0;
//	cl_platform_id platform_id;
//	cl_device_id device_id = NULL;
//	cl_mem obj[2] = {0,0};
//	cl_uint ret_num_platforms;
//	cl_uint ret_num_devices;
//	cl_int ret;
//	cl_int errorcode;
//	cl_kernel kernel;
//
//
//	FILE* fp;
//	char filename[] = "./arrayadd.cl";
//	errno_t err;
//	char* source_str;
//	size_t source_size;
//	size_t file_size;
//	err = fopen_s(&fp, filename,"rb");
//	fseek(fp, 0, SEEK_END);
//	file_size = ftell(fp);
//	rewind(fp);
//	source_str = (char*)malloc(file_size+1);
//	if (!fp) {
//		fprintf(stderr, "Failed to load kernel.\n");
//		exit(1);
//	}
//	source_str[file_size] = '\0';
//	source_size = fread(source_str, sizeof(char), file_size, fp);
//	fclose(fp);
//	/* Get Platform and Device Info */
//	ret = clGetPlatformIDs(1, &platform_id, &ret_num_platforms);
//	printf("Get cur platformid=>%d\n",platform_id);
//
//	ret = clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_DEFAULT, 1, &device_id, &ret_num_devices);
//	printf("Get cur device_id=>%d\n", device_id);
//
//	/* Create OpenCL context */
//	context = clCreateContext(NULL, 1, &device_id, NULL, NULL, &ret);
//	if (context == NULL) {
//		printf_s("no context found,fail to open");
//		return 0;
//	}
//
//	queue = clCreateCommandQueue(context, device_id,0,&errorcode);
//
//	if (queue == NULL) {
//		printf_s("no queue found,fail to open");
//		printf_s("%d\n", errorcode);
//		return 0;
//	}
//	program = clCreateProgramWithSource(context, 1, (const char**)&source_str, NULL, NULL);
//
//	if (program == NULL) {
//		printf_s("no program found,fail to open");
//		return 0;
//	}
//
//	errorcode = clBuildProgram(program, 1, &device_id, NULL, NULL, NULL);
//	kernel = clCreateKernel(program,"arrayadd",&errorcode);
//
//	if (kernel ==NULL) {
//		return 0;
//	}
//
//	//create store object for kernel function
//	int a[Array_Size];
//	int b[Array_Size];
//	int result[Array_Size];
//
//	//init a
//	for (size_t i = 0; i < Array_Size; i++)
//	{
//		a[i] = i;
//	}
//
//	obj[0] = clCreateBuffer(context, CL_MEM_READ_ONLY, (Array_Size * sizeof(int)), NULL, &errorcode);
//	obj[1] = clCreateBuffer(context, CL_MEM_READ_ONLY,(Array_Size *sizeof(int)),NULL,&errorcode);
//	ret = clEnqueueWriteBuffer(queue, obj[0], CL_TRUE, 0, (Array_Size * sizeof(int)), a, 0, NULL, NULL);
//	ret = clEnqueueWriteBuffer(queue, obj[1], CL_TRUE,0,(Array_Size *sizeof(int)), b, 0, NULL, NULL);
//
//	if (ret != CL_SUCCESS) {
//		printf("Fail to WriteBuffer");
//	}
//
//	ret = clSetKernelArg(kernel, 0, (Array_Size * sizeof(int)), &obj[0]);
//	ret = clSetKernelArg(kernel,1,(Array_Size*sizeof(int)), &obj[1]);
//
//	if (ret != CL_SUCCESS) {
//		printf("Fail to SetKernelArg");
//	}
//
//	size_t globalworksize[1] = { 128 };
//	size_t localworksize[1] = { 1 };
//
//	err = clEnqueueNDRangeKernel(queue, kernel, 1, NULL, globalworksize,
//		localworksize, 0, NULL, NULL);
//
//
//	/*ret = clEnqueueTask(queue, kernel, 0, NULL, NULL);*/
//
//	if (err != CL_SUCCESS) {
//		printf("Fail to EnqueueNDRangeKernel");
//	}
//
//	ret = clEnqueueReadBuffer(queue,obj[1],CL_TRUE, 0,(Array_Size * sizeof(int))
//		, result,0,NULL,NULL);	
//
//	int cc = 1;
//
//}