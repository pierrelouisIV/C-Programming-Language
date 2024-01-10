# Create static library
```bash
    ar -rcs libhfsecurity.a encrypt.o checksum.o
```

## Parameters
    - r: means the .a file will be updated if it already exists.
    - c: means that the archive will be created without any feedback.
    - s: tells ar to create an index at the start of the .a file.

## Standard

1. .a files have names like lib*something*.a

## Where to store the .a ?

1. You can put the .a file in a standard directory (usr/local/include or usr/include)
2. Put the .a file in some other directory

## Use it
- If the header files are not in a standard (usr/include) use -I *location*
- If the library files are not in a standard (usr/lib) use -L *location*
```bash
    gcc test_code.c -I . -L/my_lib -lhfsecurity -o test_code
```


# Create dynamic library

1. First, create an object file:
```bash
    gcc -I/includes -fPIC -c hfcal.c -o hfcal.o
```

2. Create the dynamic library (.so or shared object on Linux & Unix machines):
```bash
    gcc -shared hfcal.o -o /libs/libhfcal.so
```

## Use it
```bash
    gcc -I/includes -c elliptical.c -o elliptical.o
    gcc elliptical.o -L/libs -lhfcal -o elliptical
```

## On Linux
- You need to add your library directory to the LD_LIBRARY_PATH:
- And export it,, then the elliptical will find libhfcal.so

    ```bash
    export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/libs
    ./elliptical
    ```
- No need to do this if the library is somewhere standard, like /usr/lib
