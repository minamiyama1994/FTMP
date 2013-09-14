commit:
	./.listup
test_:
	+make $$( ls include/TMP/*.hpp | sed -e s'/include\/TMP\///' | sed -e s'/\.hpp/\.dummy/' )
%.dummy:include/TMP/%.hpp
	echo $< | sed -e s'/^include\//#include"/' | sed -e s'/$$/"/' > $*.cpp
	echo "auto main ( ) -> int { }" >> $*.cpp
	g++ -g -I./include/ -DBOOST_RESULT_OF_USE_DECLTYPE -Wall -Wextra -Werror --save-temps -std=c++11 $*.cpp -o $*
	rm -rfv $*.*