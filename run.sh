#!/bin/bash

if [[ $1 == "b" ]]; then
	printf "\n"
	echo "======================================"
	echo "BUILD"
	echo "--------------------------------------"
	cd build
	cmake ..
	make -j2
	echo "======================================"
	printf "\n"
else
	if [[ $1 == "e" ]]; then
		printf "\n"
		echo "======================================"
		echo "EXECUTE"
		echo "--------------------------------------"
		cd build
		./kukacpp
		echo "======================================"
		printf "\n"
	else
		printf "\n"
		echo "======================================"
		echo "BUILD"
		echo "--------------------------------------"
		cd build
		cmake ..
		make -j2
		printf "\n"
		echo "======================================"
		echo "EXECUTE"
		echo "--------------------------------------"
		./kukacpp
		echo "======================================"
		printf "\n"
	fi
fi