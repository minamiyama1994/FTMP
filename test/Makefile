dummy :
	+make dep
	+make $$(ls *.cpp|sed -e s'/\.cpp/\.test/')
dep :
	+make $$(ls *.cpp|sed -e s'/\.cpp/\.d/')
clean :
	+rm -rfv *.exe *.o *.d
	+touch dummy.d
%.d : %.cpp
	+$(CXX) -std=c++11 -Wall -Wextra -Werror -I ../include -M $< > $@
%.test : %.o
	+$(CXX) -std=c++11 -Wall -Wextra -Werror -I ../include -o $* $^
	+./$*
.cpp.o : 
	+$(CXX) -std=c++11 -Wall -Wextra -Werror -I ../include -c -o $@ $<
include *.d