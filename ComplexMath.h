#include <math.h>
/* PI value */
#define CM_PI 3.141592653589793


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

/* Basic arithmetic functions */
CM_ComplexNumber CM_Sum(CM_ComplexNumber a, CM_ComplexNumber b)
{
	return CM_CreateComplexNumber(a.Re+b.Re, a.Im+b.Im);
}
CM_ComplexNumber CM_Sub(CM_ComplexNumber a, CM_ComplexNumber b)
{
	return CM_CreateComplexNumber(a.Re-b.Re, a.Im-b.Im);
}
CM_ComplexNumber CM_Multiply(CM_ComplexNumber a, CM_ComplexNumber b)
{
	return CM_CreateComplexNumber((a.Re*b.Re)-(a.Im*b.Im), (a.Re*b.Im)+(a.Im*b.Re));
}
CM_ComplexNumber CM_Divide(CM_ComplexNumber a, CM_ComplexNumber b)
{
	double d = b.Re*b.Re + b.Im*b.Im;
	return CM_CreateComplexNumber((a.Re*b.Re+a.Im*b.Im)/d, (a.Im*b.Re-a.Re*b.Im)/d);
}
