include ./build_util/makefile.conf
NAME = FlowAnalysis
STARTUP_DEFS=

LFLAGS=$(USE_SEMIHOST) $(GC) $(MAP)

$(NAME)-$(CORE).axf: *.c
	$(CC) $^ $(CFLAGS) $(LFLAGS) -o $@ 

all: $(NAME)-$(CORE).axf

clean:
	$(RM) -f $(NAME)*.axf *.map

