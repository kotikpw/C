#include <stddef.h>
#include <stdlib.h>
#include <assert.h>
#include <stdarg.h>

void* alloc_init(size_t size, const char* fmt, ...)
{
	void* mem = malloc(size);

	void* p = mem;
	va_list args;
	va_start(args, fmt);
	while(*fmt)
	{
		switch(*fmt++)
		{
			case 'i': *(int   *)p = va_arg(args, int   ); p += sizeof(/* TODO padding */ int   ); break;
			case 'd': *(double*)p = va_arg(args, double); p += sizeof(/* TODO padding */ double); break;
			case 'c': *(char  *)p = va_arg(args, char  ); p += sizeof(/* TODO padding */ char  ); break;
			default: assert(0 && "Unknown format!");
		}
	}
	va_end(args);

	return mem;
}

// TEST CASE:

#include <stdio.h>

struct test
{
	int i1, i2;
	double d;
	char c;
};

int main(void)
{
	struct test* p = alloc_init(sizeof(struct test), "iidc", 33, 44, 3.14, 'a');

	printf("%d %d %f %c\n", p->i1, p->i2, p->d, p->c);

	free(p);
}
