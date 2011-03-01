TGT    = bfcrypt
SRC    = $(addsuffix .c, $(TGT) blowfish md5 sha256 crc32 des)
OBJ    = $(addsuffix .o, $(TGT))
INC    = -I.
CFLAGS = -W -Wall -O2


all: $(TGT)

$(TGT): $(SRC)
	$(CC) $(CFLAGS) $(INC) $(SRC) -o $(TGT)

clean:
	rm -f $(TGT) $(OBJ)


.PHONY: all clean
