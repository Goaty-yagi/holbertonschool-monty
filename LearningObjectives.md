# Learning Objectives

- What do LIFO and FIFO mean
- What is a stack, and when to use it
- What is a queue, and when to use it
- What are the common implementations of stacks and queues
- What are the most common use cases of stacks and queues
- What is the proper way to use global variables

## 1, What do LIFO and FIFO mean

LIFO stabds for Last In First Out, like typing a message in the input field. it is called a "stack"
Always in and out from the same side called "top"
Same as FILO

<br>

FIFO stands for First In First out, like a line in front of a restaurant. called “queue”. In from one side called "rear", and out from the other side called "fromt".
Same as LILO.
Both LILO and FIFO are associated with data structures that maintain the original order of insertion when elements are accessed or removed.

<br>

## 2, What is a stack, and when to use it
 A stack is a linear data structure in which elements can be inserted and deleted only from one side of the list.

 1, Function calls: 
  Stacks are employed in programming languages to manage function calls. When a function is called, its context is added to the call stack. When the function completes, its context is removed from the stack.

 2, Undo functionality
  In applications like text editors or graphic design software, a stack can be used to implement an undo feature. Each action that modifies the document is pushed onto the stack. Undoing an action involves popping the most recent action.

 3, Expression evaluation:
  Stacks are used in evaluating arithmetic expressions, particularly in converting infix expressions (like "3 + 4") to postfix or prefix notation for easier evaluation.

 4, Backtracking algorithms:
 Some algorithms, like depth-first search in graphs, utilize stacks to keep track of paths and backtrack when necessary.

## 3, What is a queue, and when to use it
Queue is a linear data structure in which elements can be inserted only from one side of the list.

 1, Process Scheduling:
  Queues are often used in operating systems to manage tasks or processes waiting to be executed. The first task added to the queue is the first one processed by the system.

 2, Breadth-First Search:
  In graph theory and algorithms, queues are crucial in implementing the breadth-first search (BFS) algorithm. BFS explores all neighbors of a node before moving on to the next level of nodes, and a queue helps maintain the order in which nodes are processed.

 3, Print Spooling:
  Printers use queues to manage print jobs. Jobs are added to the print queue and processed in the order they were added.

 4, Buffer in Networking:
  In computer networking, queues are used in network switches or routers to manage incoming data packets. They are stored in queues before being processed and forwarded.

 5, Handling Requests:
  Queues can be used in systems that handle requests, such as customer service centers or ticketing systems, to manage incoming requests and serve them based on the order they arrived.

## 4, What are the common implementations of stacks and queues

Both of them can be implemented as Array-Based Implementation and Linked List Implementation.
In this project, we supposed to use Linked List Implementation.

### stacks:
- Use a linked list where each node points to the next node.
- The head of the linked list represents the top of the stack.
- Push operation adds a new node at the head of the list.
- Pop operation removes the node at the head of the list.
- Doesn't have a fixed capacity but requires memory allocation for each new node.

### queues
- Similar to the linked list implementation of a stack.
- Maintains pointers to the front and rear nodes of the linked list.
- Enqueue adds a new node at the rear, dequeue removes a node from the front.
- Dynamic structure, no fixed size, but may have slightly higher memory overhead due to node pointers.

## 5, What are the most common use cases of stacks and queues

See, 2 and 3.

## 6, What is the proper way to use global variables

Global variables are accessible from anywhere in your program, which can be convenient but also introduces some risks, like potential side effects and difficulties in tracking changes. If you need to use global variables, here are some best practices to consider:

- Minimize Global Variables:<br>
 Limit their Use: Minimize the number of global variables. If possible, use local variables or pass data through function parameters instead.

- Avoid Mutable Globals: <br>
 If a global variable must be used, consider making it immutable (constant). This reduces the risk of unintended changes.

- Naming Conventions:<br>
 Descriptive Names: Use descriptive names to clearly indicate the purpose of the global variable.

- Avoid Shadowing: <br>
 Avoid using the same name for a local variable and a global variable within the same scope to prevent confusion.

- Access and Modifying Global Variables:<br>
 Avoid Direct Modification: Limit direct modification of global variables. Instead, use functions or methods to modify them. This helps maintain control and consistency.

- Encapsulation: <br>
 When modifying global variables, encapsulate their access within functions or methods. This promotes better code organization and makes it easier to manage changes.

- Documentation and Comments:<br>
 Document Usage: Clearly document the purpose, scope, and usage of global variables. This helps other developers understand their role and prevents misuse.

- Comment Changes: <br>
 If a global variable is modified in multiple places, add comments to indicate why and where modifications occur.

- Use Cases for Global Variables:<br>
 Configuration Constants: Constants that do not change during program execution, such as configuration settings or constants, can be appropriate as global variables.

- Application State: <br>
 In some cases, managing application-wide state might involve global variables. However, consider alternative designs, like using singletons or state management patterns in such cases.

- Declaration and Definition: <br>
 Declare global var in a header file with extern, but not define.
```c

// header file
extern int myVariable; // Declaration using extern
```

```c
#include "header.h"

int myVariable = 42; // Definition of the variable. memory is allocated.

```

Another source file can access

```c
#include "header.h"
#include <stdio.h>

extern int myVariable; // Declaration (optional since it's already in the header)

int main() {
    printf("Value of myVariable: %d\n", myVariable); // Accessing myVariable
    return 0;
}

```

## Extern vs defined global var in header file, why extern is better?

- Preventing Multiple Definitions:<br> 
If a variable is defined (allocated memory and initialized) in a header file and that header is included in multiple source files, each source file will have its own instance of that variable, which can lead to multiple definitions during linking and cause errors. Declaring it as extern in the header file informs the compiler that the variable is defined elsewhere, preventing multiple definitions.

- Sharing Global Variables:<br>
 When you declare a variable as extern in a header file, it serves as a reference to a global variable defined in a single source file. This allows multiple source files to access and use the same global variable without duplicating it.

- Modularity and Encapsulation:<br>
 Using extern helps in separating declaration from definition, promoting modularity and encapsulation. The header file only contains declarations (extern int myVariable;) while the actual definition (int myVariable = 42;) resides in a specific source file. This separation keeps the implementation details hidden from other parts of the program.

- Code Maintainability: <br>
It makes the codebase more maintainable as changes to the variable's definition or type can be made in one place (the source file where it's defined) without affecting all files that include the header.

- Avoiding Unnecessary Memory Allocation:<br>
 Global variables defined directly in header files would lead to unnecessary memory allocation in every source file that includes the header. Using extern avoids this issue by not allocating memory for the variable in each source file.

- Overall, using extern for variable declarations in header files promotes clean code, modularity, and prevents issues related to multiple definitions. It encourages better code organization and improves the maintainability of larger C projects.

### Do I need to free global var as extern?

No.

### is it possible to reassign global var as extern?

within the memory allocation, yes.
