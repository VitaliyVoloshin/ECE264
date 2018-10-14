# Makefile
TARGET = hw10
WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)

TESTFLAGS = -DTEST_MAINFUNC -DTEST_FUNCGIVEN -DTEST_IMGTOGRAY -DTEST_HEADERVALID -DTEST_BMPOPENFILE -DTEST_BMPWRITEFUNC -DTEST_BMPFREEFUNC

SRCS =  hw10.c bmpfunc.c bmpimage.c
OBJS = $(SRCS:%.c=%.o)

VALGRIND = valgrind --tool=memcheck --verbose --log-file=memcheck.txt --leak-check=full

$(TARGET): $(OBJS)
	$(GCC) $(TESTFLAGS) $(OBJS) -o $(TARGET)

.c.o:
	$(GCC) $(TESTFLAGS) -c $*.c

testall: test1 test2 test3 test4 testmemory

testadd: $(TARGET)
	test1
	test2
	test3
	test4
	testmemory

testmemory:	$(TARGET)
	$(VALGRIND) ./hw10 exampleImages/RV2.bmp expectedImages/outputRV2.bmp

test1: $(TARGET)
	./hw10 exampleImages/RV.bmp expectedImages/outputRV.bmp
	
test2: $(TARGET)
	./hw10 exampleImages/RV2.bmp expectedImages/outputRV2.bmp

test3: $(TARGET)
	./hw10 exampleImages/RV2Small.bmp expectedImages/outputRV2Small.bmp

test4: $(TARGET)
	./hw10 exampleImages/CondProb.bmp expectedImages/outputCondProb.bmp

clean:
	rm -f $(OBJS) $(TARGET)
	rm -f *.txt
