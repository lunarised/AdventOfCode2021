CC :=gcc
LDFLAGS :=-W -Wall -O2 -ansi -pedantic
C_SOURCES :=$(wildcard */*.c)
C_EXECUTABLE :=$(C_SOURCES:.c=)
 
all:$(C_EXECUTABLE) $(CPP_EXECUTABLE)

$(C_EXECUTABLE):$(C_SOURCES)
		$(CC) $< $(LDFLAGS) $(CFLAGS) -o $@

clean:
		rm -rf $(EXECUTABLE)