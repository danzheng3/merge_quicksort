WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)
VAL = valgrind --tool=memcheck --log-file=memcheck.txt --leak-check=full --verbose

TESTFALGS = -DTEST_BUILDTREE

SRCS = pa2.c sorting.c
OBJS = $(SRCS:%.c=%.o)

pa2: $(OBJS)
	$(GCC) $(TESTFALGS) $(OBJS) -o pa2
