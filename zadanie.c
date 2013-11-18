#include <stdio.h>
#include <stdarg.h>

void *alloc(const char *fmt, ...);

struct test {
	int i1, i2;
	double d;
	char i3;
};

int 
main() {
	struct test *p = alloc("iidi", 33, 44, 3.14, 55);

	printf("%d %d %f %d\n", p->i1, p->i2, p->d, p->i3);

	return 0;
}
