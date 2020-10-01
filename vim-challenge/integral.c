#include <stdio.h>

float simpson(float a, float b, float (*f) (float), float dx) {
	float value_of_interval_integral =
					0.5 * (f(a) + f(b)) / dx;
	return value_of_interval_integral;
}


float integral(float a, float b, float (*f) (float), int n) {
	
	float dx = (b - a) / n;
    float value_of_integral = 0.0;

for (int i=0; i<n; i++) {
float si_a = a + (i)*dx;
float si_b = a + (i+1)*dx;
value_of_integral += simpson(si_a, si_b, f, dx);
}

return value_of_integral;
}

float square(float x) {
	return x*x;
}

int main(int argc, char** argv) {
	float twopi = 2 * 3.14;
	float integral_of_f = integral(0.0, 1.0, square, 1e3);
	/*float integral_of_sin = integral(0.0, twopi, sin, 10);*/
	printf("Całka z funkjci f (0.0 - 1.0) = %g\n", integral_of_f);
	/*printf("Całka z sinus (0 - 2pi) = %g\n", integral_of_sin);*/
	return 0;
}
