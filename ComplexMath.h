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
	double theta = atan2(a.Im, a.Re);
	double pre = pow(r, b.Re)*exp(-b.Im*theta);
	double angle = (b.Re*theta) + (b.Im*log(r));
	return CM_CreateComplexNumber((double) pre*cos(angle), (double) pre*sin(angle));
}

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

CM_ComplexNumber CM_Ln(CM_ComplexNumber x)
{
	double theta;
	if (abs(x.Re) > 0.0f) theta = (double) atan(x.Im/x.Re);
	else theta = CM_PI;
	double r = sqrt((x.Re*x.Re) + (x.Im*x.Im));
	return CM_CreateComplexNumber(log(r), theta);	
}

CM_ComplexNumber CM_Log(CM_ComplexNumber base, CM_ComplexNumber arg)
{
	CM_ComplexNumber result = CM_Div(CM_ln(base), CM_ln(arg));
	return CM_CreateComplexNumber(result.Re, result.Im);
}

CM_ComplexNumber CM_RiemannZeta(CM_ComplexNumber z, int maxIteration)
{
	CM_ComplexNumber result = CM_CreateComplexNumber(0.0f, 0.0f), numbToSum;
	
	if(((int)z.Re%2 == 0 && z.Re < 0 ) && z.Im == 0.0f) result = CM_CreateComplexNumber(0.0f, 0.0f);
	else if (z.Re == -1.0f && z.Im == 0.0f) result = CM_CreateComplexNumber((double)-1/12, 0.0f);
	else
		for (int i = 1; i <= maxIteration; i++)
		{
			numbToSum = CM_Pow(CM_CreateComplexNumber((double)i, 0.0f), CM_CreateComplexNumber(-z.Re, -z.Im));
			result = CM_Sum(result, numbToSum);
		}
	return result;
}
