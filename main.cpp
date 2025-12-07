#include "ArrayQueue.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream> // Added iostream include for cout, endl, etc.
#include <string>   // Added string include for exceptions
using namespace std;

int main() {
    // create a queue of 10 integers
    ArrayQueue<int> queueA(10);

    // attempt to display the front and back
    try {
        cout << queueA.front() << " ";
    } catch (string& e) {
        cout << e << " ";
    }
    try {
        cout << queueA.back() << " ";
    } catch (string& e) {
        cout << e << " ";
    }

    // insert just one element to queue A
    queueA.enqueue(-5);

    // display its length, front, and back
    cout << "queue A length: " << queueA.getLength() << " ";
    cout << "queue A front: "  << queueA.front()     << " ";
    cout << "queue A back: "   << queueA.back()      << " ";

    // now remove the single element from queue A
    queueA.dequeue();

    // display its length, front, and back
    cout << "queue A length: " << queueA.getLength() << " ";
    try {
        cout << queueA.front() << " ";
    } catch (string& e) {
        cout << e << " ";
    }
    try {
        cout << queueA.back() << " ";
    } catch (string& e) {
        cout << e << " ";
    }

    // populate queue A by enqueueing random values
    srand(time(0));
    for (int i = 0; i < queueA.getMaxSize(); i++) {
        queueA.enqueue(rand() % 500);
    }

    // ensure that queue A is now full
    if (queueA.isFull()) {
        cout << "queue A is full! ";
    }
    else {
        cout << "queue A is not full [ERROR] ";
    }

    // display its length, front, and back
    cout << "queue A length: " << queueA.getLength() << " ";
    cout << "queue A front: "  << queueA.front()     << " ";
    cout << "queue A back: "   << queueA.back()      << " ";

    // make a copy of queue A
    ArrayQueue<int> queueB = queueA;

    // loop to dequeue and print
    cout << "queue A contains: ";
    for (int i = 0; i < queueA.getMaxSize(); i++) {
        cout << queueA.front() << ' ';
        queueA.dequeue();
    }
    cout << " ";

    // queue A should now be empty
    if (queueA.isEmpty()) {
        cout << "queue A is now empty ";
    }
    else {
        cout << "queue A is not empty [ERROR] ";
    }

    // display queue B length, front, and back
    cout << "queue B length: " << queueB.getLength() << " ";
    cout << "queue B front: "  << queueB.front()     << " ";
    cout << "queue B back: "   << queueB.back()      << " ";

    // make a copy of queue
    return 0;
}