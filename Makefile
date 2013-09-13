commit:
	./.listup
test_:
	for f in include/TMP/*.hpp ; do \
		echo $$f | sed -e s'/^include\//#include"/' | sed -e s'/$$/"/' > test.cpp ; \
		echo "auto main ( ) -> int { }" >> test.cpp ; \
		echo $$f | sed -e s'/^include\///' ; \
		g++ -g -I/local/include/boost-1_54/ -I./include/ -DBOOST_RESULT_OF_USE_DECLTYPE -Wall -Wextra -Werror --save-temps -std=c++11 test.cpp -o test ; \
	done