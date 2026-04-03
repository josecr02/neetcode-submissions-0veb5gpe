class DynamicArray {
    // I will have some private variables like the size. Also hold the array.
    int size;
    int *theVector;
    int currentIndex;
public:

    DynamicArray(int capacity) : size{capacity}, theVector{new int[size]}, currentIndex{0} {

    }

    int get(int i) {
        return theVector[i];
    }

    void set(int i, int n) {
        theVector[i] = n;
    }

    void pushback(int n) {
        // check resize
        if (currentIndex == size){
            resize();
        }
        theVector[currentIndex] = n;
        ++currentIndex;
    }

    int popback() {
        
        int value =  theVector[currentIndex - 1];
        --currentIndex;
        return value;
    }

    void resize() {
        int newSize = 2 * size;
        int i = 0;
        int* theNewVector = new int[newSize];
        for (i; i < currentIndex; ++i){
            theNewVector[i] = theVector[i];
        }
        delete theVector;
        // do not change until we have succesfully created the new array:
        theVector = theNewVector;
        size = newSize;
    }

    int getSize() {
        return currentIndex;
    }

    int getCapacity() {
        return size;
    }

    ~DynamicArray(){
        delete theVector;
    }
};
