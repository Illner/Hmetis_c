if [ -d build ]; then rm -Rf build; fi

mkdir build
cd build

# Release
mkdir Release
cd Release
cmake -DCMAKE_VERBOSE_MAKEFILE:BOOL=ON -D CMAKE_BUILD_TYPE=Release -G "Unix Makefiles" ../..
make

cd ..

# Debug
mkdir Debug
cd Debug
cmake -DCMAKE_VERBOSE_MAKEFILE:BOOL=ON -D CMAKE_BUILD_TYPE=Debug -G "Unix Makefiles" ../..
make

cd ..
