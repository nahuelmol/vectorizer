OUT = out/out

prove:
	g++ -I $(CURDIR) -o $(OUT) prove.cpp

compile:
	g++ -I $(CURDIR) -o $(OUT) start.cpp
run:
	out/out.exe