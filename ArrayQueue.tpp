template <typename T>
ArrayQueue<T>::ArrayQueue(int i)
: frontIndex(0), backIndex(-1), maxSize(i) {
    // Allocate the dynamic array
    buffer = new T[maxSize];
    this->length = 0; // Initialize length from base class
}

template <typename T>
ArrayQueue<T>::ArrayQueue(const ArrayQueue<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
ArrayQueue<T>& ArrayQueue<T>::operator=(const ArrayQueue<T>& rightObj) {
    if (this != &rightObj) {
        // Must delete existing buffer before clearing and copying
        delete[] buffer;
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
ArrayQueue<T>::~ArrayQueue() {
    // Delete the dynamic buffer array
    delete[] buffer;
}

// ----------------------------------------------------------------------
// BRANCH MODIFIED: Queue Operations
// ----------------------------------------------------------------------

template <typename T>
T ArrayQueue<T>::back() const {
    if (this->isEmpty()) {
        throw string("back: error, queue is empty");
    }
    // backIndex always points to the newest (last) element
    return buffer[backIndex];
}

template <typename T>
void ArrayQueue<T>::clear() {
    // Reset indices and length, no need to deallocate memory
    frontIndex = 0;
    backIndex = -1; // Set backIndex to -1 to signify an empty state
    this->length = 0;
}

template <typename T>
void ArrayQueue<T>::copy(const ArrayQueue<T>& copyObj) {
    // Ensure we allocate a new buffer
    this->maxSize = copyObj.maxSize;
    this->length = copyObj.length;
    this->frontIndex = copyObj.frontIndex;
    this->backIndex = copyObj.backIndex;
    
    this->buffer = new T[maxSize];

    // Copy elements from the source's buffer (not just the length of the queue, but the full buffer setup)
    // For simplicity and safety, copy the entire raw buffer contents.
    for (int i = 0; i < maxSize; ++i) {
        this->buffer[i] = copyObj.buffer[i];
    }
    // Note: A more optimized copy would only copy the used portion (from frontIndex up to backIndex, handling wrap-around).
}

template <typename T>
void ArrayQueue<T>::dequeue() {
    if (this->isEmpty()) {
        throw string("dequeue: error, queue is empty");
    }
    
    // Move frontIndex forward, handling wrap-around
    frontIndex = (frontIndex + 1) % maxSize;
    this->length--;
    
    // Optional: If the queue becomes empty, reset frontIndex/backIndex for a clean start
    if (this->isEmpty()) {
        frontIndex = 0;
        backIndex = -1;
    }
}

template <typename T>
void ArrayQueue<T>::enqueue(const T& elem) {
    if (this->isFull()) {
        throw string("enqueue: error, queue is full");
    }
    
    // Move backIndex forward, handling wrap-around
    // (backIndex must be updated BEFORE insertion)
    backIndex = (backIndex + 1) % maxSize;
    
    // Insert the element
    buffer[backIndex] = elem;
    this->length++;
}

template <typename T>
T ArrayQueue<T>::front() const {
    if (this->isEmpty()) {
        throw string("front: error, queue is empty");
    }
    // frontIndex always points to the oldest (first) element
    return buffer[frontIndex];
}

// The following functions were provided and are complete:

template <typename T>
int ArrayQueue<T>::getLength() const {
    return this->length;
}

template <typename T>
int ArrayQueue<T>::getMaxSize() const {
    return maxSize;
}

template <typename T>
bool ArrayQueue<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
bool ArrayQueue<T>::isFull() const {
    return this->length == maxSize;
}
