#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

struct test {
	int i1, i2;
	double d;
	char i3;
};

struct test* alloc(const char *fmt, ...) { 
	struct test *out = malloc(sizeof(struct test*));
	va_list args;
	va_start(args, fmt);

	int i1_has_value = 0;
	int i2_has_value = 0;

	for(int i = 0; i < strlen(fmt); i++) {
		switch(fmt[i]) {
			case 'i':
				if(!i1_has_value) {
					out->i1 = va_arg(args,int);
					i1_has_value = 1;
				}
				else if(!i2_has_value) {
					out->i2 = va_arg(args,int);
					i2_has_value = 1;
				}
				else 
					out->i3 = va_arg(args,int);
				break;
			case 'd':
				out->d = va_arg(args,double);
				break;
		}
	}

	va_end(args);

	return out;
}

int main() {
	struct test *p = alloc("iidi", 33, 44, 3.14, 55);
	printf("%d %d %f %d\n", p->i1, p->i2, p->d, p->i3);

	return 0;
}
