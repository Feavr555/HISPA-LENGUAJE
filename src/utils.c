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

bool __print(const char*const _string,int *n)
{
	int i=0;
	char const* string = _string;
	if(*string=='('){
		string++;
		if(*string==0x22){
			string++;
			i=0;
			puts(__follow(string,&i));
			string+=i;
			if(*string==0x22) { *n=i; return true; }
			else return false;
		}
	}else if(*string==' '){
		string++;
		__print(string,n);
	}else return false;
	return true;
}

bool ___interpeter(const char*const buffer)
{
	int i=0;
	const char* copy = buffer;
	// read first char on file
	if(!__isLetter(copy[0])){
		// Token reserved for system
		if(copy[0]=='#'){
		}else if(copy[0]=='/'){
		}else{
			puts("Character unknow!");
			return false;
		}
	}
	// read first follow on file
	char *follow = __follow(copy,&i);
	copy+=i;
	// API std-hispa
	int n=0;
	if(!strcmp(follow,"print")){
		__print(copy,&n);
		copy+=n+5;
	}else if(!strcmp(follow,"")){
	}else if(!strcmp(follow,"")){
	}else{
		puts("Token unknow!");
		return false;
	}
	if(copy[0]==0x0A) {
		if(copy[1]=='\0') return true;
		___interpeter(copy+1);
	}
	return true;
}

bool __interpeter(const char*const buffer)
{
	int i=0;
	const char * copy = buffer;
	char *follow = __follow(copy,&i);
	copy+=i;
	if(!strcmp(follow,"print")){
		if(copy[0]==' '||copy[0]=='('){
			if(copy[1]==0x22){
				free(follow);
				copy+=2;
				follow = __follow(copy,&i);
				puts(follow);
				free(follow);
				copy+=i;
				if(copy[0]==0x22){
					if(copy[1]==0x0A)
						copy+=2;
						__interpeter(copy);
				}
			}
		}else return false;
	}else return false;
	return true;
}

bool viewError(char *buffer,uint32_t index)
{
	return true;
}




