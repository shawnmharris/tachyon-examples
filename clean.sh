#!/bin/bash
mkdir -p bin
cd bin
rm -rf *
cd ..
cd component1
rm -rf build
cd ..
cd component2
rm -rf build
cd ..
cd component-tester
rm -rf build
cd ..
rm -rf bin

