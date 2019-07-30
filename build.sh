#!/bin/bash
mkdir -p bin
cd bin
rm *
cd ..
cd component1
rm -rf build
mkdir build
cd build
cmake ..
make
cp libcomponent1* ../../bin
cd ../..
cd component2
rm -rf build
mkdir build
cd build
cmake ..
make
cp libcomponent2* ../../bin
cd ../..
cd component-tester
rm -rf build
mkdir build
cd build
cmake ..
make
cp component-tester ../../bin
cd ../..
cd bin
cd ..


