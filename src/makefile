OBJS = token_funcs.o history_funcs.o uimain.o

CFLAGS = -g -O3

all: uimain

uimain: $(OBJS)
	cc -o uimain $(CFLAGS) $(OBJS)

$(OBJS): tokenizer.h history.h

clean:
	@echo "Cleaning up..."
	rm -f *.o *~ uimain

run: uimain
	./uimain
