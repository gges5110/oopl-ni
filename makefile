.DEFAULT_GOAL := test

ifeq ($(shell uname), Darwin)                                           # Apple
    CXX          := g++
    INCLUDE      := /usr/local/include
    CXXFLAGS     := -pedantic -std=c++11 -I$(INCLUDE) -Wall -Weffc++
    LIB          := /usr/local/lib
    LDFLAGS      := -lboost_serialization -lgtest_main
    CLANG-CHECK  := clang-check
    GCOV         := gcov
    GCOVFLAGS    := -fprofile-arcs -ftest-coverage
    VALGRIND     := valgrind
    DOXYGEN      := doxygen
    CLANG-FORMAT := clang-format
else ifeq ($(CI), true)                                                 # Travis CI
    CXX          := g++-5
    INCLUDE      := /usr/include
    CXXFLAGS     := -pedantic -std=c++11 -Wall -Weffc++
    LIB          := $(PWD)/gtest
    LDFLAGS      := -lboost_serialization -lgtest -lgtest_main -pthread
    CLANG-CHECK  := clang-check
    GCOV         := gcov-5
    GCOVFLAGS    := -fprofile-arcs -ftest-coverage
    VALGRIND     := valgrind
    DOXYGEN      := doxygen
    CLANG-FORMAT := clang-format
else ifeq ($(shell uname -p), unknown)                                  # Docker
    CXX          := g++
    INCLUDE      := /usr/include
    CXXFLAGS     := -pedantic -std=c++11 -Wall -Weffc++
    LIB          := /usr/lib
    LDFLAGS      := -lboost_serialization -lgtest -lgtest_main -pthread
    CLANG-CHECK  := clang-check
    GCOV         := gcov
    GCOVFLAGS    := -fprofile-arcs -ftest-coverage
    VALGRIND     := valgrind
    DOXYGEN      := doxygen
    CLANG-FORMAT := clang-format-3.5
else                                                                    # UTCS
    CXX          := g++-4.8
    INCLUDE      := /usr/include
    CXXFLAGS     := -pedantic -std=c++11 -Wall -Weffc++
    LIB          := /usr/lib
    LDFLAGS      := -lboost_serialization -lgtest -lgtest_main -pthread
    CLANG-CHECK  := clang-check-3.8
    GCOV         := gcov-4.8
    GCOVFLAGS    := -fprofile-arcs -ftest-coverage
    VALGRIND     := valgrind
    DOXYGEN      := doxygen
    CLANG-FORMAT := clang-format-3.8
endif

clean:
	cd examples; make clean
	@echo
	cd exercises; make clean

config:
	git config -l

docker-build:
	docker build -t gpdowning/gcc .

docker-pull:
	docker pull gpdowning/gcc

docker-push:
	docker push gpdowning/gcc

docker-run:
	docker run -it -v $(PWD):/usr/oopl-ni -w /usr/oopl-ni gpdowning/gcc

init:
	touch README
	git init
	git add README
	git commit -m 'first commit'
	git remote add origin git@github.com:gpdowning/oopl-ni.git
	git push -u origin master

pull:
	make clean
	@echo
	git pull
	git status

push:
	make clean
	@echo
	git add .gitignore
	git add .travis.yml
	git add Dockerfile
	git add examples
	git add exercises
	git add makefile
	git commit -m "another commit"
	git push
	git status

status:
	make clean
	@echo
	git branch
	git remote -v
	git status

sync:
	@rsync -r -t -u -v --delete              \
    --include "Hello.c++"                    \
    --include "Docker.sh"                    \
    --include "Assertions.c++"               \
    --include "UnitTests1.c++"               \
    --include "UnitTests2.c++"               \
    --include "UnitTests3.c++"               \
    --include "Coverage1.c++"                \
    --include "Coverage2.c++"                \
    --include "Coverage3.c++"                \
    --include "Exceptions.c++"               \
    --include "Exceptions2.c++"              \
    --include "Exceptions3.c++"              \
    --include "Operators.c++"                \
    --include "Variables.c++"                \
    --include "Types.c++"                    \
    --include "Representations.c++"          \
    --include "Arguments.c++"                \
    --include "Cache.c++"                    \
    --include "Returns.c++"                  \
    --exclude "*"                            \
    ../../../examples/c++/ examples
	@rsync -r -t -u -v --delete              \
    --include "IsPrime1.c++"                 \
    --include "IsPrime1.h"                   \
    --include "IsPrime2.c++"                 \
    --include "IsPrime2.h"                   \
    --include "StrCmp.c++"                   \
    --include "StrCmp.h"                     \
    --include "Equal.c++"                    \
    --include "Incr.c++"                     \
    --exclude "*"                            \
    ../../../exercises/c++/ exercises

test:
	make clean
	@echo
	cd examples; make test
	@echo
	cd exercises; make test

versions:
	which make
	make --version
	@echo
	which git
	git --version
	@echo
	which $(CXX)
	$(CXX) --version
	@echo
	ls -ald $(INCLUDE)/boost
	@echo
	ls -ald $(INCLUDE)/gtest
	@echo
	ls -al /usr/lib/*boost*.a
	@echo
	ls -al $(LIB)/*gtest*.a
	@echo
	which $(CLANG-CHECK)
	-$(CLANG-CHECK) --version
	@echo
	which $(GCOV)
	$(GCOV) --version
	@echo
	which $(VALGRIND)
	$(VALGRIND) --version
	@echo
	which $(DOXYGEN)
	$(DOXYGEN) --version
	@echo
	which $(CLANG-FORMAT)
	-$(CLANG-FORMAT) --version
