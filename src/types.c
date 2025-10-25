#include <types.h>


#define DEFINE_VEC(typename,size)	\
typedef struct{				\
	char *name;			\
	float data[size];		\
}typename;
DEFINE_VEC(vec1,1)
DEFINE_VEC(vec2,2)
DEFINE_VEC(vec3,3)

