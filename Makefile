LIBS:= ntl gmp
LIBFLAGS:=$(addprefix -l, $(LIBS));

main : main.cpp threshold_paillier.cpp
	g++ -std=c++11 -lpthread -g -O2 $^ -o $@ $(LIBFLAGS)
