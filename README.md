# ComplexMath
A library for C that make complex math simpler. Official docs and more features are incoming 
### What can I do with this library?
Well, you can do basically every operation between complex numbers: sum, subtraction, multiplication, division and even exponentials! (Esponentials are coming soon). All the operations are in this table (See the last section for formulas references):

|Operation| Action|
|---------|-------|
|CM_CreateComplexNumber|Works like a constructor in OOP, it takes real and immaginary values as 2 parameters|
|CM_Sum|Sums 2 numbers|
|CM_Sub|Subtract the second number from the first one|
|CM_Multiply|Multiplies 2 numbers with the following formula **1***|
|CM_Divide|Divides 2 numbers with the following formula **2***|

### Other functionalities
This library also includes some other useful functions, like rad2deg and deg2rad, respectively radiants to degrees and degrees to radiants.

### Formula references
Rembemer that _a + bi_ and _c + di_ are complex numbers    
(a + bi)(c + di) = ac - bd + (ad + bc)i  
(a + bi)/(c + di) = (ac + bd + (bc - ad)$i$)/(c^2 ^ $d^2$)
