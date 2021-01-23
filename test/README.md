![](https://i.imgur.com/DqWmaUD.png)
# libft-crit

**libft-crit** is a test framework used to test my own C library, called **libft**. It is built with the [criterion test API](https://github.com/Snaipe/Criterion). 

## Usage

### Requirements
- An operating system running on the linux kernel (not compatible with Windows or MacOS)
- `bash` (bourne against shell) command-line shell.
- criterion
- a C compiler (the framework has been built using clang)
- `libbsd` package, that provides BSD-specific implementations not included in `glibc` by default.
- my libft (if you're a 42 student and want to test your lib, please [read that]())

If you've all of that, then you're good to go!

### Commands
For convenience, I made a little bash script which is doing everything by itself while providing a clean command-line interface to test the functions.

```bash
# Run all the test suites
./run.sh all

# Run specific test suites, assuming pattern suite/ft_*_suite.c
./run.sh ft_strcmp ft_strdup
```
## Motivations

I made this framework to ensure that all the functions included in my lib are functional, even after making changes to it. While writing tests takes time, it's worth it for the long term.

I am also a big fan of the TDD approach (Test Driven Development), which I am applying on almost all my projects.

## I am a 42 student, and want to test my own libft
This framework has been built to ensure that my library, which I tweaked very much, is working as expected. Therefore, you'll not find so much utility in that project since the tests are no longer conforming to the project requirements.

However, you can use it to test some basic functions individually, like `memcpy`, `strncmp` and so on. If you're looking for a complete test framework, easy to install and use, you can look at my old [libft-unity](https://github.com/abrabant-42/) project **but keep in mind that I am not maintaining it actively**.
