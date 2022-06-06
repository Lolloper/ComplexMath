# ComplexMath
A library for C that make complex math simpler. Official docs and more features are incoming 
### What can I do with this library?
Well, you can do basically every operation between complex numbers: sum, subtraction, multiplication, division and even exponentials! (Esponentials are coming soon). All the functions are in the documentation section (See the last section for formulas references).

### Documentation

|Operation| Action|
|---------|-------|
|CM_ComplexNumber|Struct for complex numbers|
|CM_CreateComplexNumber|Works like a constructor in OOP, it takes real and immaginary values as 2 parameters|
|CM_Sum|Sums 2 numbers|
|CM_Sub|Subtract the second number from the first one|
|CM_Multiply|Multiplies 2 numbers with the following formula **1***|
|CM_Divide|Divides 2 numbers with the following formula **2***|

### Other functionalities
This library also includes some other useful functions, like rad2deg and deg2rad, respectively radiants to degrees and degrees to radiants.

### Formula references
Rembemer that $a + bi$ and $c + di$ are complex numbers  
**1***: $(a + bi)(c + di) = ac - bd + (ad + bc)i$  
**2***: $\frac{a + bi}{c + di} = \frac{ac+bd}{c^2 + d^2} + \frac{bc - ac}{c^2 + d^2}i$  
**3***: $(a + bi)^{c + di} = e^{\ln{\sqrt{a^2 + b^2}}c - d\arctan{f}}()$
