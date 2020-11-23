![](https://i.imgur.com/zXfESsW.png)
# libft
![](https://github.com/abrabant-42/libft/workflows//norminette/badge.svg)


libft is my own C library,  made from scratch with the most basic features and functions of the C programming language. It's also the first project of the 42cursus at #42Born2Code.


This version is the one I maintain as long as I need to for my C projects at 42. You can find the graded and original version [here]().

## Testing
I am a big fan of the TDD approach. I made [this framework](https://github.com/abrabant-42/libft-crit) based on the criterion test API. I am updating it each time I make changes in my lib. A new function is usually developed in the dev branch and merged when tests have been made.

## Motivations
If you're not a 42 school, you may ask what is the purpose of "reinventing" the wheel with this library. At 42, we do not have
access to the standard library, or only to basic system call implementations such as `write` or `malloc`. This is why we can implement these useful and missing functions by ourselves and then use them in future projects. 

Of course, 99.99% of the time my own implementations will be less efficient than the original implementation, made by experienced programmers. But keep in mind that the goal here is to LEARN. Reinventing the wheel is bad, unless you do it for learning purposes!

Moreover, you'll find a lot of non-standard functions that are my pure creation, and this is also what makes the libft very personal at the end (and useful).


I always try and like to provide good documentation about what I am coding, therefore you'll find a lot of comments explaining things about how and why I implemented some things.
