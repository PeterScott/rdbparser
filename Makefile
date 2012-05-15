CFLAGS = -O2 -std=c99

COMMON = lzf_c.o lzf_d.o crc64.o redis-check-dump.o

all: biggest dump

biggest: $(COMMON) largest.o
	cc $^ -o $@

dump: $(COMMON) output.o
	cc $^ -o $@


clean:
	rm -f *.o dump biggest
