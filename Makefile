PROJECT=algorithms
SOURCES=main.c testing.c algorithms.c
LIBRARY=nope
INCPATHS=#../some_other_project/
LIBPATHS=#../yet_another_project/
LDFLAGS=-fsanitize=address
CFLAGS=-c -Wall -g
CC=gcc

ODIR=obj

# ------------ MAGIC BEGINS HERE -------------

# Automatic generation of some important lists
_OBJECTS=$(SOURCES:.c=.o)
OBJECTS=$(patsubst %,$(ODIR)/%,$(_OBJECTS))
INCFLAGS=$(foreach TMP,$(INCPATHS),-I$(TMP))
LIBFLAGS=$(foreach TMP,$(LIBPATHS),-L$(TMP))

# Set up the output file names for the different output types
ifeq "$(LIBRARY)" "shared"
	BINARY=lib$(PROJECT).so
	LDFLAGS += -shared
else ifeq "$(LIBRARY)" "static"
	BINARY=lib$(PROJECT).a
else
	BINARY=$(PROJECT)
endif

all: $(SOURCES) $(BINARY)

$(BINARY): $(OBJECTS)
# Link the object files, or archive into a static library
ifeq "$(LIBRARY)" "static"
	ar rcs $(BINARY) $(OBJECTS)
else
	$(CC) $(LIBFLAGS) $(OBJECTS) $(LDFLAGS) -o $@
endif

$(ODIR)/%.o: %.c
	$(CC) $(INCFLAGS) $(CFLAGS) -fPIC $< -o $@

distclean: clean
	rm -f $(BINARY)

clean:
	rm -f $(OBJECTS)
