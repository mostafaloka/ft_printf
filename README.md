# ft_printf

the second project at 42. you just finished libft, you know how to write functions,
and now the subject drops this on you: recode printf().

not the whole thing — no padding, no width, no precision flags. just the core mechanic.
but the core mechanic is the interesting part anyway: how does a function accept
any number of arguments of any type and still know what to do with them?
that's what this project is actually about.

---

## the problem printf() solves

in C, every function has a fixed number of parameters. `strlen` takes one. `memcpy` takes three.
you always know at compile time what you're passing and what type it is.

printf() breaks that rule. you can call it like this:

```c
printf("%d %s %c\n", 42, "hello", 'x');
```

three arguments of three different types, and printf handles all of them correctly.
how? variadic functions. specifically, the `va_list` mechanism defined in `<stdarg.h>`.

---

## how variadic functions work

when you declare a function with `...` in its signature:

```c
int ft_printf(const char *format, ...);
```

the compiler knows this function can take extra arguments. those arguments don't have
names or types — you have to pull them out manually using four macros:

**va_start(ap, last)** — initializes a `va_list` named `ap`, starting after the last
named parameter. you always call this first.

**va_arg(ap, type)** — retrieves the next argument as the given type. if you say
`va_arg(ap, int)`, you get the next int. if the actual argument wasn't an int,
you get garbage. the function has no way to check — that's why format strings exist.
they tell the function what to expect.

**va_copy(dest, src)** — copies a va_list. useful if you need to traverse the arguments
twice. we didn't need this for ft_printf but it exists.

**va_end(ap)** — cleans up the va_list. always call this before returning.

the whole thing looks like this in practice:

```c
int ft_printf(const char *format, ...)
{
    va_list ap;
    va_start(ap, format);
    // do stuff with ap
    va_end(ap);
    return (count);
}
```

---

## what ft_printf actually does

it walks through the format string character by character.
most characters it just prints directly. when it hits a `%`, it looks at the next
character to figure out what conversion to apply, pulls the next argument from `va_list`,
formats it, and prints it.

the conversions we handle:

**%c** — prints a single character. pulled from va_list as an int (chars get promoted
to int in variadic calls), then written with write().

**%s** — prints a string. pulled as a `char *`. if it's NULL, prints "(null)" —
that's what the real printf does, and the testers will check for it.

**%d and %i** — both print a signed decimal integer. same implementation, two specifiers.
handle negative numbers, handle INT_MIN (its absolute value overflows a signed int,
so you can't just negate it — you have to treat it as a special case or work in unsigned).

**%u** — unsigned decimal. simpler than %d because no sign to worry about.

**%x and %X** — hexadecimal. lowercase for %x, uppercase for %X.
the conversion is just repeated division by 16 with a lookup into "0123456789abcdef"
or "0123456789ABCDEF".

**%p** — pointer address in hex, prefixed with "0x". pulled as `void *`, cast to
`unsigned long` for the conversion. this is the one that varies most between systems —
on 64-bit machines, pointers are 8 bytes.

**%%** — literal percent sign. no argument consumed. just print '%'.

---

## the return value

ft_printf returns the total number of characters printed. not bytes, not something else —
characters. you have to count every single character you write, including the ones inside
conversions, and return the total at the end.

this is easy to forget and annoying to fix later. count as you go.

---

## what we don't implement

the real printf has width, precision, and flag modifiers:

```c
printf("%-10.3f", 3.14159);  // left-aligned, 3 decimal places, width 10
```

none of that. the subject explicitly says no buffer management, no flags.
just the eight conversions above and %%. that's the scope.

---

## build

```bash
make        # builds libftprintf.a
make clean  # removes object files
make fclean # removes object files and the archive
make re     # fclean + make
```

to use it:
```bash
gcc your_file.c -L. -lftprintf -o your_program
```

your header is ft_printf.h. it contains the prototype:

```c
int ft_printf(const char *format, ...);
```

---

## score

100 / 100
