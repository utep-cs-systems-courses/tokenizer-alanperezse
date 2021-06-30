OBJS = token_funcs.o history_funcs.o uimain.o
OBJS2 = token_funcs.o history_funcs.o tester.o

CFLAGS = -g -O3

all: uimain tester

uimain: $(OBJS)
	cc -o uimain $(CFLAGS) $(OBJS)

tester: $(OBJS2)
	cc -o tester $(CFLAGS) $(OBJS2)


$(OBJS): tokenizer.h history.h

$(OBJS): tokenizer.h history.h

clean:
	@echo "Cleaning up..."
	rm -f *.o *~ uimain tester

run: uimain
	./uimain

test: tester
	./tester
