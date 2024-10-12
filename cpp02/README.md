# README

## INFO

### FIXED POINT NUMBERS
A fixed point number is way of representing a number using fixed number of bits to represent both the integer and fractional parts of a number.

#### Why & why not?
Fixed point numbers are memory and performance efficient due to their limited nature which can be adjusted to suit the situation.
However, as their precision is limited, they should be used mindfully when precision is fixed and known. In other words fixed point numbers may lead to inaccurate results with highly precise calculations that might require more precision than the provided fixed fractional part offers.

#### Common use cases:
* Game development: offers speed for graphics & physics calculations where speed is a priority ove precision.
* Signal processing: known and consistent levels of precision.

#### Tldr:
Fixed point number is a floating point number with fixed number of decimals (/accuracy).
Offers memory efficiency and proecssing speed with the cost of precision.

###  DEGRADING ACCURACY OF FLOATING POINT NUMBERS
Floats gradually degrade in accuracy over iterative usage.
I.e. doing arithmetic using the result of previous calculation as
a part of the calculation leads to compounding of minor inaccuracy
comes from having to work with near infinite or infinite numbers
(like 1/3 or pi)  while only having finite compute, time and storage
to power and present those calculations.
#### TLDR:
Floating point numbers offer INACCURATE PRECISION while integers offers ACCURATE IMPRECISION.
So int over float when possible, especially with iterative processes like
algorithms. Example: when applicable storing floats as separate
numerator & denumerator INTs (1/3 => 1, 3).
