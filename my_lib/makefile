LIBOBJS=build/queue.o build/param_check.o
LIBDEPS=$(LIBOBJS:.o=.d)
BUILDCMD=gcc -c $< -o $@ -MMD -MF $*.d

.PHONY: all clean cleanALL

all: $(LIBOBJS)

-include $(LIBDEPS)

build/queue.o: data_structure/queue/queue.c
		$(BUILDCMD) 
		

build/param_check.o: common/param_check.c
		$(BUILDCMD)


clean:
		rm -f build/*.d

cleanALL:
		rm -f build/*.d build/*.o
