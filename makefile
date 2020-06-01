obj := obj/Network.o obj/assert.o obj/BinaryArithematic.o obj/MatrixArithematic.o obj/Activation.o obj/main.o
main: $(obj)
	g++ -g $(obj) -o main
obj/Network.o: cc/Network.cc
	g++ -c -g cc/Network.cc -o obj/Network.o
obj/assert.o: cc/assert.cc
	g++ -c -g cc/assert.cc -o obj/assert.o
obj/BinaryArithematic.o: cc/BinaryArithematic.cc
	g++ -c -g cc/BinaryArithematic.cc -o obj/BinaryArithematic.o
obj/MatrixArithematic.o: cc/MatrixArithematic.cc
	g++ -c -g cc/MatrixArithematic.cc -o obj/MatrixArithematic.o
obj/Activation.o: cc/Activation.cc
	g++ -c -g cc/Activation.cc -o obj/Activation.o
obj/main.o: cc/main.cc
	g++ -c -g cc/main.cc -o obj/main.o
