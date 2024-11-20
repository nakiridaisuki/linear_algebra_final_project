CC=gcc
MAIN=main.o
TEST=test.o
SHELL = /bin/bash
EXE=main
SOURCEDIR=src
SRCFILES=$(wildcard $(SOURCEDIR)/*.c)
SRCOBJS=$(patsubst %.c,%.o,$(SRCFILES))
DBGOBJS=$(patsubst %.c,%.dbg,$(SRCFILES))
# OBJ=$(addprefix $(SOURCEDIR)/, )


test: $(TEST) $(SRCOBJS)
	$(CC) $(TEST) $(SRCOBJS) -o $(EXE) -lm
.PHONY: test

dtest: test.dbg $(DBGOBJS)
	$(CC) -D DEBUG $< $(DBGOBJS) -o $(EXE)
.PHONY: dtest

%.o: %.c
	@$(CC) -c $< -o $@
	
%.dbg: %.c
	@$(CC) -D DEBUG -g -c $< -o $@

all: $(MAIN) $(SRCOBJS)
	$(CC) $(MAIN) $(SRCOBJS) -o $(EXE) -lm


debug: main.dbg $(DBGOBJS)
	$(CC) $< $(DBGOBJS) -o $(EXE)
.PHONY: debug

clean:
	-rm -f $(SOURCEDIR)/*.o $(SOURCEDIR)/*.dbg $(EXE) *.o *.dbg

.PHONY: clean