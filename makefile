obj := obj/Network.o obj/assert.o
main: $(obj)
	g++ -g $(obj) -o main
obj/Network.o:
	g++ -c -g cc/Network.cc -o obj/Network.o
obj/assert.o:
	g++ -c -g cc/assert.cc -o obj/assert.o
