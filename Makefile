commit:
	./.listup
test_:
	+make $$( ls include/TMP/*.hpp | sed -e s'/include\/TMP\///' | sed -e s'/\.hpp/\.dummy/' )
%.dummy:include/TMP/%.hpp
	echo $< | sed -e s'/^include\//#include"/' | sed -e s'/$$/"/' > $*.cpp
	echo "auto main ( ) -> int { }" >> $*.cpp
	g++ -g -I./include/ -Wall -Wextra -Werror --save-temps -std=c++11 $*.cpp -o $*
	rm -rfv $*.*
%.include_header:include/TMP/%.hpp
	( for word in $$( cat $< ) ; do echo $$word; done ) | sort | uniq.exe | grep '^[a-z_]*$$' | sed -e s'/^/#include"TMP\//' | sed -e s'/$$/\.hpp"/'