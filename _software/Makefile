EIGEN_DIR=/usr/include/eigen3/

all: example_2_1 example_2_2 example_3_1 example_3_2 example_3_3

example_2_1: example_2_1.cpp
	g++ -Wall $< -o $@

example_2_2: example_2_2.cpp
	g++ -Wall -std=c++11 $< -o $@

example_3_1: example_3_1.cpp
	g++ -Wall -I$(EIGEN_DIR) $< -o $@

example_3_2: example_3_2.cpp
	g++ -Wall -std=c++11 -I$(EIGEN_DIR) $< -o $@

example_3_3: example_3_3.cpp
	g++ -Wall -std=c++11 -I$(EIGEN_DIR) $< -o $@
	