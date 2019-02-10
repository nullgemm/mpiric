![logo](res/icons/mpiric_128.png)

# Mpiric maths
This repository was created to collect the best
portable fast math functions on the internet.
Because its goal is to provide _portable_ approximations,
you won't find SIMD-based algorithms here.

Currently most of the code here comes from [pt_math](https://github.com/pmttavara/pt_math).
Another important source is the [hacker's delight](https://hackersdelight.org) website.

## Testing
You can easily make a testing executable which will generate svg
graphics with `charter` and write some basic benchmarking logs.
A copy of the resulting files can be found in the `res` folder,
but if you choose to re-generate them they will be written in `bin`.

The makefile includes the following targets
 - *bin/mpiric_test* (phony): makes the testing executable
 - *bin/charter_svg*: makes the charter svg graph generator
 - *run*: runs the executable to generate svg graphs and write benchmarking logs
 - *svg*: copies the svg files in the res folder

Github seems to break svg files rendering, please open them
independently in your browser by right-clicking on them and
choosing "view image".

## Using
To clone this repository use the following command
```
git clone --recurse-submodules https://github.com/cylgom/mpiric.git
```

To use these functions you must include `cylgom.h` and `mpiric.h`.
`mpiric.c` should also be compiled and linked with your program.

## License
Everything here is public domain work, except of course
the `charter` submodule used to generate graphs.
