# ComplexMath
A library for C that make complex math simpler. Official docs and more features are incoming 
### What can I do with this library?
Well, you can do basically every operation between complex numbers: sum, subtraction, multiplication, division and even exponentials! (Esponentials are coming soon). All the functions are in the documentation section (See the last section for formulas references).

### Documentation

|Syntax| What does|
|---------|-------|
|CM_ComplexNumber|Struct for complex numbers|
|CM_CreateComplexNumber()|Works like a constructor in OOP, it takes real and immaginary values as 2 parameters|
|CM_Sum()|Sums 2 numbers|
|CM_Sub()|Subtract the second number from the first one|
|CM_Multiply()|Multiplies 2 numbers using the following formula **1***|
|CM_Divide()|Divides 2 numbers using the following formula **2***|
|CM_printcn()|Prints a complex number with the following format: `Re: a, Im: b`|
|CM_Pow()|Elevates the first number to the second number power using the following formula **3***|
|CM_W()|Returns the Lambert W function of a number (at the moment it works only with real ones) with the following formula **4***|
|CM_Ln()|Take the natural logarithm with the following formula **5***|
|CM_Log()|Takes the first argument logarithm base of the second argument using the logarithm general formula **6***|
|CM_RiemannZeta()|Plugs the first argument in the Riemann Zeta Function, and the second argument will be how many numbers you want to sum, because it can't be infinite. Riemann Zeta Function can be calculated with the following formula **7***|

### Other functionalities
This library also includes some other useful functions, like rad2deg and deg2rad, respectively radiants to degrees and degrees to radiants.

### Formula references
Rembemer that $a + bi$ and $c + di$ are complex numbers  
**1***: $(a + bi)(c + di) = ac - bd + (ad + bc)i$  
**2***: $\frac{a + bi}{c + di} = \frac{ac+bd}{c^2 + d^2} + \frac{bc - ac}{c^2 + d^2}i$  
**3***: $(a + bi)^{c + di} = e^{\ln{\sqrt{a^2 + b^2}}c - d\tan^{-1}{\frac{b}{a}}}(\cos{(\ln{\sqrt{a^2 + b^2}d + c\tan^{-1}{\frac{b}{a}})}} +$
$i\sin{(\ln{\sqrt{a^2 + b^2}d + c\tan^{-1}{\frac{b}{a}})}})$  
**4***: $W(z)= x, x_{n} = x_{n} - \frac{x_{n-1}e^{x_{n-1}}-z}{e^{x_{n-1}}(x_{n-1}+1)}$  
**5***: $\ln z = \ln r + (\theta + 2k\pi)i,  k \in Z $  
**6***: $\log_{b}a = \frac{\log_{d}a}{\log_{d}b}, d \in C $  
**7***: $\zeta(z) = \sigma$

### WARNINGS
The Lambert W function doesn't work pretty well, so it may probably work bad
