# Make
<!-- TODO -->
The make utility automatically determines which pieces of a large program need to be recompiled, and issues commands to recompile them.

Its purpose is to automate the process of compiling and linking source code files into executable programs.

-   Examples show C programs, since they are most common, but you can use make with any programming language whose compiler can be run with a shell command.

### Using Make

1. You need a file called a `makefile` to tell `make` what to do. Most often, the makefile tells make how to compile and link a program.

2. Run the make command within the directory that has the `makefile`
    ```shell
    make
    ```

