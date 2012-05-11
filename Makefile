CFLAGS = -O2 -std=c99

OBJECTS = lzf_c.o lzf_d.o crc64.o output.o redis-check-dump.o

all: $(OBJECTS)
	cc $(OBJECTS) -o redis-check-dump
