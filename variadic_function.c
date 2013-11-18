#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

void *alloc(const char *fmt, ...);

struct test {
	int i1, i2;
	double d;
	char i3;
};

int main() {
	struct test *p = alloc("iidi", 33, 44, 3.14, 55);

	printf("%d %d %f %d\n", p->i1, p->i2, p->d, p->i3);

	return 0;
}

void *alloc(const char *fmt, ...) {
	struct test *t;
	va_list ap;
	int i1_contains_value, i2_contains_value;

	t = malloc(sizeof(*t));
	va_start(ap, fmt);

	i1_contains_value = 0;
	i2_contains_value = 0;

	while (*fmt) {

		if (*fmt == 'i') {

			if (i1_contains_value == 0) {
				t->i1 = va_arg(ap, int);
				i1_contains_value = 1;
			} else if (i2_contains_value == 0) {
				t->i2 = va_arg(ap, int);
				i2_contains_value = 1;
			} else {
				t->i3 = va_arg(ap, int);
			}

		} else if (*fmt == 'd') {
			t->d = va_arg(ap, double);
		} else if (*fmt == 'c') {
			t->i3 = va_arg(ap, int);
		}
		fmt++;
	}

	va_end(ap);

	return t;
}
