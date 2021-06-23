OBJS = token_funcs.o tester.c

CFLAGS = -g -O3

all: tester

tester: $(OBJS)
	cc -o tester $(CFLAGS) $(OBJS)

$(OBJS): tokenizer.h

clean:
	@echo "Cleaning up..."
	rm -f *.o *~

run: tester
	./tester
