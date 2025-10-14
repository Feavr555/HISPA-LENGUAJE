#include <utils.h>


int main(int argc,char**argv)
{
	char *buffer = __read(argv[1]);
	___interpeter(buffer);
	free(buffer);
	return 0;
}

