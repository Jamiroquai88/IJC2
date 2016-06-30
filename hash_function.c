#include "htable.h"

unsigned int hash_function(const char *str, unsigned int htab_size)
{
	unsigned int h=0;
	const unsigned char *p;
	for((p=(unsigned char*)str); *p!='\0'; p++)
		h = 65599*h + *p;
	return h % htab_size;
}
