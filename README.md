[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/W3eTIbNK)
[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-2e0aaae1b6195c2367325f4f02e2d04e9abb55f0b24a779b69b11b9e10269abc.svg)](https://classroom.github.com/online_ide?assignment_repo_id=21974823&assignment_repo_type=AssignmentRepo)
# Week 9 Wed Lab

## Directions

You will be implementing the Queue ADT as a circular array-based class. The `Queue` abstract class is already given to you, along with the header file for the `ArrayQueue` class, and a skeleton of its implementation file.

You are also in charge of writing your own driver program to test your `ArrayQueue` class. Be thorough with your testing by checking all the operations in different scenarios and with various data types.

## Notes

- If you need to access the `length` attribute in your `ArrayQueue` class, you need to write it as `this->length`
- The `buffer` attribute is meant to be a fixed-size, dynamic array
- The class needs to keep track of the indices for the front and back of the queue (that's what the `frontIndex` and `backIndex` attributes are for, respectively)
- There are a number of operations that need to consider if it's invalid for it to be called: in those scenarios, make sure to `throw` a `string` exception explaining the error, like this
```C++
throw string("message goes here");
```

