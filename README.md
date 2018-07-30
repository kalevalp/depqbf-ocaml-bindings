# DepQBF OCaml Bindings
Ocaml bindings for the DepQBF QBF solver's C API. More information on
DepQBF can be found here: http://lonsing.github.io/depqbf/

## Prerequisites

Naturally, you need to have the DepQBF compiled on your system. This
code was tested with DepQBF version 6.03.

## Compilation

#### Compiling the module interface:

    ocamlc -c depqbf.ml

#### Compiling the library stub file

**Note:** before compiling, youd need to make sure that the file is
pointing to the correct location of `qdpll.h` in your system. (This
should probably be generified at some point.)

    ocamlc -c depqbf_stubs.c

## Compiling and Running an Example

To compile the example `basic-api-example.ml` from the `examples`
directory:

    ocamlc -custom -o prog unix.cma depqbf.cmo examples/basic-api-example.ml depqbf_stubs.o -ccopt -L<path-to-libqdpll.so.*> -cclib -lqdpll

