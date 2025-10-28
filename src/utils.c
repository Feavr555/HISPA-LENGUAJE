#include <utils.h>

// Is better function for read files to array text?
char* __read(const char *file)
{
	FILE *f = fopen(file,"rb");
	fseek(f,0,SEEK_END);
	long s = ftell(f);
	fseek(f,0,SEEK_SET);
	char *buffer = (char*)malloc((int)s);
	fread(buffer,(int)s,1,f);
	fclose(f);
	return buffer;
}

// Get me a follow for interpeter
char* __follow(const char *const buffer,int *n)
{
	uint32_t i=0;
	while(__isLetter(buffer[i])) i++;
	char *follow = (char*)malloc(i);
	i=0;
	while(__isLetter(buffer[i])){
		follow[i] = buffer[i];
		i++;
	}
	follow[i] = '\0';
	*n=i;
	return follow;
}


bool viewError(char *buffer,uint32_t index)
{
	return true;
}




