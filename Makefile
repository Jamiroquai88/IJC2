#makefile
#Riesenie UJC-DU2, 16.3.2014
#Autor: Jan Profant, FIT
#Prelozene: gcc 4.8.1

CP=g++-4.8
CC=gcc
CFLAGS=-std=c99 -pedantic  -Wall -Wextra -g
CPFLAGS=-std=c++11 -pedantic -Wall
HTABLIB=hash_function.o htab_init.o htab_lookup.o htab_foreach.o htab_remove.o htab_clear.o htab_free.o htab_statistics.o

############################################################

all: wordcount fold fold2 wordcount-dynamic

############################################################

#################  staticka kniznica  ######################

libhtable.a: $(HTABLIB)
	ar crs libhtable.a $(HTABLIB)

#################  dynamicka kniznica  ####################

libhtable.so: $(HTABLIB)
	$(CC) $(CFLAGS) -shared -o libhtable.so $(HTABLIB)

###########################################################

wordcount: wordcount.o io.o libhtable.a
	$(CC) $(CFLAGS) -o wordcount -static io.o wordcount.o libhtable.a

wordcount-dynamic: wordcount.o io.o libhtable.so
	$(CC) $(CFLAGS) -o wordcount-dynamic io.o wordcount.o libhtable.so

#############################################################

hash_function.o: hash_function.c htable.h
	$(CC) $(CFLAGS) -c -fPIC $<

htab_init.o: htab_init.c htable.h
	$(CC) $(CFLAGS) -c -fPIC $<

htab_lookup.o: htab_lookup.c htable.h
	$(CC) $(CFLAGS) -c -fPIC $<

htab_foreach.o: htab_foreach.c htable.h
	$(CC) $(CFLAGS) -c -fPIC $<

htab_remove.o: htab_remove.c htable.h
	$(CC) $(CFLAGS) -c -fPIC $<

htab_clear.o: htab_clear.c htable.h
	$(CC) $(CFLAGS) -c -fPIC $<

htab_free.o: htab_free.c htable.h
	$(CC) $(CFLAGS) -c -fPIC $<

htab_statistics.o: htab_statistics.c htable.h
	$(CC) $(CFLAGS) -c -fPIC $<

###############################################################

fold.o: fold.c
	$(CC) $(CFLAGS) -c $<

io.o: io.c io.h
	$(CC) $(CFLAGS) -c $<

fold2.o: fold2.cc
	$(CP) $(CPFLAGS) -c $<

fold: fold.o
	$(CC) $(CFLAGS) fold.o -lm -o $@

fold2: fold2.o
	$(CP) $(CPFLAGS) fold2.o -lm -o $@


