GCC = gcc -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror -fprofile-arcs -ftest-coverage

# Which ops to test by defining the symbols
FLAGS = -DTEST_ADD

# List all .c files
SRCS = add.c  template.c

# Object files are created by converting .c to .o
OBJS = $(SRCS:%.c=%.o)


template: $(OBJS)
	$(GCC) $(FLAGS) $(OBJS) -o template

.c.o:
	$(GCC) $(FLAGS) -c $*.c

testall: testadd

testadd: template
		 ./template 4 5 A > add1.out

coverage: testall
		  gcov $(SRCS)

clean: #remove all machine generated files
	rm -f template *.o *.out *gcda *gcno *gcov
