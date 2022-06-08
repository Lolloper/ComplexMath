#include <math.h>
#include <stdio.h>
/* PI value */
#define CM_PI 3.141592653589793
/* E value */
#define CM_E 2.718281828459045

/* Radians and degrees converter functions */
#define CM_rad2deg(x) 180*x/B_PI
#define B_deg2rad(x) B_PI*x/180

/* Complex number struct */
typedef struct {
	double Re;
	double Im;
} CM_ComplexNumber;

/* Complex number "constructor" */
CM_ComplexNumber CM_CreateComplexNumber(double r, double i)
{
	CM_ComplexNumber n2r;
	n2r.Re = r;
	n2r.Im = i;
	return n2r;
}

/* Basic automated print function */
void CM_printcn(CM_ComplexNumber a)
{
	printf("Re: %f, Im: %f\n", a.Re, a.Im);
}

/* Sums two complex numbers */
CM_ComplexNumber CM_Sum(CM_ComplexNumber a , CM_ComplexNumber b)
{
	return CM_CreateComplexNumber(a.Re+b.Re, a.Im+b.Im);
}
/* Subtracts the second number from the first one */
CM_ComplexNumber CM_Sub(CM_ComplexNumber a, CM_ComplexNumber b)
{
	return CM_CreateComplexNumber(a.Re-b.Re, a.Im-b.Im);
}
/* Multiplies two complex numbers */
CM_ComplexNumber CM_Mult(CM_ComplexNumber a, CM_ComplexNumber b)
{
	return CM_CreateComplexNumber((a.Re*b.Re)-(a.Im*b.Im), (a.Re*b.Im)+(a.Im*b.Re));
}
/* Divides the first number by the second one */
CM_ComplexNumber CM_Div(CM_ComplexNumber a, CM_ComplexNumber b)
{
	double d = b.Re*b.Re + b.Im*b.Im;
	return CM_CreateComplexNumber((a.Re*b.Re+a.Im*b.Im)/d, (a.Im*b.Re-a.Re*b.Im)/d);
}
/* Rises the first number to the second-number-exponent */
CM_ComplexNumber CM_Pow(CM_ComplexNumber a, CM_ComplexNumber b)
{
	double r = sqrt(a.Re*a.Re + a.Im*a.Im);
	double theta = atan(a.Im/a.Re);
	double pre = pow(r, b.Re)*exp(-b.Im*theta);
	double angle = (b.Re*theta) + (b.Im*log(r));
	return CM_CreateComplexNumber((double) pre*cos(angle), (double) pre*sin(angle));
}

/* Faster sqrt */
/*double _sqrt(double x)
{
	double y, iMin, iMax;
	if (x == 1) y = 1;
	else 
	{
		if (x < 0.0f) x = x;
		else 
		{
			iMin=x/2;
			while (1)
			{
				if ((iMin*iMin)-x < 0) {iMin+=x/10;}
				else if ((iMin*iMin)-x > 0) {iMax=iMin; iMin-=x/10; break;}
			}
			y = (iMin+iMax)/2;
			y = (float) 3*x/4;
		}
		y -= (y-x/y)/2; // Newton's iteration
	}
	return y;
}
*/
/* Lambert W function */
double CM_W(double x)
{
	double y = log(x), expy;
	for (int i = 0; i < 10; i++)
	{
		expy = exp(y);
		y -= (y*expy - x)/(expy*(y + 1));
	}
	return y;
}
