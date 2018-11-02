all: q1 q2

q1: q1.c
	gcc -Wall -g -std=c99 -pedantic q1.c -o q1
