# mpiric maths
![logo](res/icons/mpiric_128.png)
The repository was created to collect the best
portable fast math functions on the internet.
Because its goal is to provide portable approximations,
you won't find SIMD-based algorithms here.

Currently most of the code here comes from [pt_math](https://github.com/pmttavara/pt_math).
Another important source is the [hacker's delight](https://hackersdelight.org) website.

The makefile targets include svg-graphs generation with `charter`
and basic performance tests. You can find a copy of the resulting
files in `res`, but if you run them by yourself they will be in `bin`
(Please read the makefile for more details).

Please note github seems to break svg files rendering, open them
independently in your browser.

To clone his repository correctly, use the following command
```
git clone --recurse-submodules https://github.com/cylgom/mpiric.git
```

Everything here is public domain work, except of course
the `charter` submodule used to generate graphs.
