Joshua Aidelman
1000139
Assignment Three


********************************* Q1 *********************************
    This program takes a fully parenthesized, arithmetic expression and
converts it into a binary expression tree. The input can include decimal
values, or variables. You can then display the tree, print the pre-order,
post-order or in-order equation, update a variable, calculate the equation,
or exit the program.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Sample Output ~~~~~~~~~~~~~~~~~~~~~~~~~~~~
> ./q1 \(\(\(1.56+4.26\)*\(x1-2.23\)\)/x2\)
Type 1 to display tree
Type 2 to display the preorder equation
Type 3 to display the inorder equation
Type 4 to display the postorder equation
Type 5 to update a variable
Type 6 to calculate the equation
Type 7 to exit
> 1
		1.56
			     +
		4.26
				         *
		x1
			     -
		2.23
					               /
				         x2
Value of x1: 0.00
Value of x2: 0.00

Type 1 to display tree
Type 2 to display the preorder equation
Type 3 to display the inorder equation
Type 4 to display the postorder equation
Type 5 to update a variable
Type 6 to calculate the equation
Type 7 to exit
> 2
/*+1.564.26-x12.23x2
Type 1 to display tree
Type 2 to display the preorder equation
Type 3 to display the inorder equation
Type 4 to display the postorder equation
Type 5 to update a variable
Type 6 to calculate the equation
Type 7 to exit
> 3
(((1.56+4.26)*(x1-2.23))/x2)
Type 1 to display tree
Type 2 to display the preorder equation
Type 3 to display the inorder equation
Type 4 to display the postorder equation
Type 5 to update a variable
Type 6 to calculate the equation
Type 7 to exit
> 4
1.564.26+x12.23-*x2/
Type 1 to display tree
Type 2 to display the preorder equation
Type 3 to display the inorder equation
Type 4 to display the postorder equation
Type 5 to update a variable
Type 6 to calculate the equation
Type 7 to exit
> 5
Which variable would you like to update?
> x2
What would you like to change x2 to?
> 5.55
Type 1 to display tree
Type 2 to display the preorder equation
Type 3 to display the inorder equation
Type 4 to display the postorder equation
Type 5 to update a variable
Type 6 to calculate the equation
Type 7 to exit
> 5
Which variable would you like to update?
> x1
What would you like to change x1 to?
> 0.5
Type 1 to display tree
Type 2 to display the preorder equation
Type 3 to display the inorder equation
Type 4 to display the postorder equation
Type 5 to update a variable
Type 6 to calculate the equation
Type 7 to exit
> 1
        1.56
              +
        4.26
                    *
        x1
              -
        2.23
                          /
                    x2
Value of x1: 0.50
Value of x2: 5.55

Type 1 to display tree
Type 2 to display the preorder equation
Type 3 to display the inorder equation
Type 4 to display the postorder equation
Type 5 to update a variable
Type 6 to calculate the equation
Type 7 to exit
> 6
Answer: -1.81
Type 1 to display tree
Type 2 to display the preorder equation
Type 3 to display the inorder equation
Type 4 to display the postorder equation
Type 5 to update a variable
Type 6 to calculate the equation
Type 7 to exit
> 7
Exiting...
********************************* Q2 *********************************
    This program reads a 20x10 integer array from a file named "f.dat".
It then makes the array into an array representation of a heap. The first
3 numbers on a row are the keys, and the next 7 are the data. It then
uses downheap to sort the tree where the sum of a parent's keys are less
than the sum of it's children's keys. It then prints the pre-order traversal
of the tree, and also prints the tree in order from index 1-21.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Sample Output ~~~~~~~~~~~~~~~~~~~~~~~~~~~~
PRE-ORDER TRAVERSAL
-------------------------
index 1: 25 12 17 82 52 53 5 3 68 64 KeyTotal: 54
index 2: 16 14 27 99 29 99 79 45 59 19 KeyTotal: 57
index 4: 12 0 68 68 49 68 74 32 9 30 KeyTotal: 80
index 8: 3 60 76 23 14 81 82 0 38 4 KeyTotal: 139
index 16: 96 89 75 0 63 24 54 20 20 24 KeyTotal: 260
index 17: 88 56 59 88 39 30 44 59 49 72 KeyTotal: 203
index 9: 43 27 20 59 4 84 10 42 43 2 KeyTotal: 90
index 18: 9 83 22 90 74 56 64 75 67 55 KeyTotal: 114
index 19: 49 17 44 32 33 54 60 33 51 87 KeyTotal: 110
index 5: 81 30 16 65 40 39 44 49 32 60 KeyTotal: 127
index 10: 41 82 53 40 29 84 24 61 87 20 KeyTotal: 176
index 20: 41 62 82 46 69 42 74 68 79 28 KeyTotal: 185
index 11: 99 37 50 93 57 6 29 91 92 39 KeyTotal: 186
index 3: 50 9 6 44 59 87 32 36 36 46 KeyTotal: 65
index 6: 25 41 11 88 15 39 88 69 31 49 KeyTotal: 77
index 12: 81 14 42 21 9 69 5 30 20 91 KeyTotal: 137
index 13: 3 37 97 53 36 54 69 68 38 43 KeyTotal: 137
index 7: 44 27 68 96 70 98 85 13 25 47 KeyTotal: 139
index 14: 83 82 43 11 21 4 8 97 93 14 KeyTotal: 208
index 15: 51 90 37 86 42 44 48 64 41 1 KeyTotal: 178


LEVEL ORDER TRAVERSAL
------------------------
index 1: 25 12 17 82 52 53 5 3 68 64 KeyTotal: 54
index 2: 16 14 27 99 29 99 79 45 59 19 KeyTotal: 57
index 3: 50 9 6 44 59 87 32 36 36 46 KeyTotal: 65
index 4: 12 0 68 68 49 68 74 32 9 30 KeyTotal: 80
index 5: 81 30 16 65 40 39 44 49 32 60 KeyTotal: 127
index 6: 25 41 11 88 15 39 88 69 31 49 KeyTotal: 77
index 7: 44 27 68 96 70 98 85 13 25 47 KeyTotal: 139
index 8: 3 60 76 23 14 81 82 0 38 4 KeyTotal: 139
index 9: 43 27 20 59 4 84 10 42 43 2 KeyTotal: 90
index 10: 41 82 53 40 29 84 24 61 87 20 KeyTotal: 176
index 11: 99 37 50 93 57 6 29 91 92 39 KeyTotal: 186
index 12: 81 14 42 21 9 69 5 30 20 91 KeyTotal: 137
index 13: 3 37 97 53 36 54 69 68 38 43 KeyTotal: 137
index 14: 83 82 43 11 21 4 8 97 93 14 KeyTotal: 208
index 15: 51 90 37 86 42 44 48 64 41 1 KeyTotal: 178
index 16: 96 89 75 0 63 24 54 20 20 24 KeyTotal: 260
index 17: 88 56 59 88 39 30 44 59 49 72 KeyTotal: 203
index 18: 9 83 22 90 74 56 64 75 67 55 KeyTotal: 114
index 19: 49 17 44 32 33 54 60 33 51 87 KeyTotal: 110
index 20: 41 62 82 46 69 42 74 68 79 28 KeyTotal: 185
