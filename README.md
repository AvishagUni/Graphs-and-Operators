# Ex2cpp

Operator Overloads
Arithmetic Operators
Addition (+ and +=): Adds the adjacency matrices of two graphs of the same size. Throws an exception if the graphs differ in size.
Subtraction (- and -=): Subtracts the adjacency matrix of one graph from another, assuming both graphs are of the same size.
Multiplication (*): Supports both graph-to-graph matrix multiplication and scalar multiplication of a graph's adjacency matrix.
Unary Operators
Unary Plus (+): Returns the graph itself, effectively making no changes to the adjacency matrix.
Unary Minus (-): Returns a new graph with all values in the adjacency matrix negated.
Increment and Decrement Operators
Prefix and Postfix Increment (++): Increments each entry in the graph's adjacency matrix by one.
Prefix and Postfix Decrement (--): Decrements each entry in the graph's adjacency matrix by one.
Comparison Operators
Equality (==) and Inequality (!=): Compares two graphs for equality or inequality based on their sizes and the contents of their adjacency matrices.
Greater Than (>), Less Than (<), Greater Than or Equal To (>=), and Less Than or Equal To (<=): Compares graphs based on their sizes and, if sizes are equal, by their edge counts.
Stream Insertion Operator
Stream Insertion (<<): Facilitates the printing of a graph’s adjacency matrix to an output stream, such as std::cout, formatting the output for clarity and readability.
Exception Handling
Graph operations that involve size mismatches throw a runtime exception with a message indicating the issue. It is recommended to catch these exceptions to handle potential errors gracefully during runtime.
