remove_id: main.cc input.h input.cc
	g++ main.cc input.cc -L../Libraries/Params -lParams -L../Libraries/Files -lfiles -o remove_id -g -Wall -std=c++11
