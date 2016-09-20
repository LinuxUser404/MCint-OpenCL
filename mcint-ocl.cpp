#include <iostream> 
#include <CL/cl.hpp>
#include <vector>


inline void checkErr(cl_int err, const char * name) {
	if (err != CL_SUCCESS) {
		std::cerr << "ERROR: " << name  << " (" << err << ")" << std::endl;
		exit(EXIT_FAILURE);
	}
}

int main(int argc, char* argv[])
{
	cl_int err;
	std::vector< cl::Platform > platformList;
	cl::Platform::get(&platformList);
	checkErr(platformList.size()!=0 ? CL_SUCCESS : -1, "cl::Platform::get");
	std::cerr << "Platform number is: " << platformList.size() << std::endl;
	std::string platformVendor;
	for(int i = 0; i < platformList.size(); ++i)
	{
		platformList[i].getInfo((cl_platform_info)CL_PLATFORM_VENDOR, &platformVendor);
		std::cerr << "Platform is by: " << platformVendor << std::endl;
	}
	//cl_context_properties cprops[3] = {CL_CONTEXT_PLATFORM, (cl_context_properties)(platformList[0])(), 0};cl::Context context(CL_DEVICE_TYPE_CPU, cprops, NULL, NULL, &err);
	checkErr(err, "Context::Context()"); 
	return 0;
}