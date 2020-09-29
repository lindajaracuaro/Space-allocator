// Allocating space
//It's an example of how to use new & delete to allocate space

#include <cstdio>
#include <new>

//Using a constant expression called count expresada en bytes
constexpr size_t count = 1024;

int main()
{
	//Tells what we're going to do
	printf("Alocating space for %lu long int at *ip with new\n", count);

	//Allocate array
	long int* ip;

	//Try to create a new long int till count is over
	//The pointer will point to a new int 
	//Allocate items of the size[count]
	try {
		ip = new long int[count];
	}
	//If you find an exception of the system callled stderr finish the operation to avoid that the system collapses
	catch(std::bad_alloc &ba){
		fprintf(stderr, "Cannot allocate memory (%s) \n", ba.what());
		return 1;
	}

	//Initialize the 1024 objects to values 0 - 1 - 2 - 3...
	for (long int i = 0; i < count; ++i)
	{
		ip[i] = i;
		printf("%ld \t", ip[i]);
	}


	puts("");

	//Deallocate the array
	// Add [] if you want to delete more than one object
	delete[] ip;
	puts("space at *ip deleted");

return 0;
}