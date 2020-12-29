![](https://i.imgur.com/zXfESsW.png)
# libft

libft is my own C library,  made from scratch with the most basic features and functions of the C programming language. It's also the first project of the 42cursus at #42Born2Code.

This version is the one I maintain as long as I need to for my C projects at 42. You can find the graded and original version [here]().

## 42 school's linter

For the common core projects, we have to use the 42 school's linter, the [norminette](https://github.com/42School/norminette),
in order to ensure that our C code respects all the [rules](https://github.com/42School/norminette/blob/master/pdf/en.norm.pdf).
This repository is making use of this [norminette-action](https://github.com/alexandregv/norminette-action) to check that, everytime a change is made.

The norm is a good way for us to learn without coding badly, even if some constraints can be really questionable.

The [version 3 of the norminette](https://github.com/42School/norminette) has been released, and will be taken as the new reference since the 4th of January of 2021. My libft has been and will be updated accordingly.

## Testing
I am a big fan of the TDD approach. I made [this framework](https://github.com/abrabant-42/libft-crit) based on the criterion test API. I am updating it each time I make changes in my lib. A new function is usually developed in the dev branch and merged when tests have been made.

## Motivations
If you're not a 42 school, you may ask what is the purpose of "reinventing" the wheel with this library. At 42, we do not have
access to the standard library, or only to basic system call implementations such as `write` or `malloc`. This is why we can implement these useful and missing functions by ourselves and then use them in future projects. 

Of course, 99.99% of the time my own implementations will be less efficient than the original implementation, made by experienced programmers. But keep in mind that the goal here is to LEARN. Reinventing the wheel is bad, unless you do it for learning purposes!

Moreover, you'll find a lot of non-standard functions that are my pure creation, and this is also what makes the libft very personal at the end (and useful).

I always try and like to provide good documentation about what I am coding, therefore you'll find a lot of comments explaining things about how and why I implemented some things.

## Related

- [libft-crit](https://github.com/abrabant-42/libft-crit))
- [42school/norminette](https://github.com/42School/norminette)
- [alexandregv/norminette-action](https://github.com/alexandregv/norminette-action)
