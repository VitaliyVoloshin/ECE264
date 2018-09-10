WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)

TESTFLAGS = -DTEST_MERGE -DTEST_MERGESORT -DTEST_MERGESSORT

SRCS = main.c
OBJS = $(SRCS:%.c=%.o)

hw07: $(OBJS)
	$(GCC) $(TESTFLAGS) $(OBJS) -o hw07

.c.o:
	$(GCC) $(TESTFLAGS) -c $*.c

testall: test1

testadd: hw07
	test1

test1: hw07
	./hw07 Input/Test1 output1.txt
	diff -i -w output1.txt Expected/Expected1

clean: #remove all machine generated files
	rm -f hw07 *.o output?
	rm -f *.txt
