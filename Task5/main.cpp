#include <iostream>
#include <exception>

// Класс исключения для переполнения очереди
class Overflow : public std::exception {
public:
    const char* what() const throw() {
        return "Queue overflow";
    }
};

// Класс исключения для извлечения элемента из пустой очереди
class Underflow : public std::exception {
public:
    const char* what() const throw() {
        return "Queue underflow";
    }
};

// Шаблонный класс очереди
template <int N, class T>
class Queue {
private:
    T data[N];
    int front, rear, count;

public:
    Queue() : front(0), rear(0), count(0) {}

    void enqueue(T value) {
        if (count >= N) {
            throw Overflow();
        }
        data[rear] = value;
        rear = (rear + 1) % N;
        count++;
    }

    T dequeue() {
        if (count <= 0) {
            throw Underflow();
        }
        T result = data[front];
        front = (front + 1) % N;
        count--;
        return result;
    }
};

// Шаблонная функция поиска максимального элемента в массиве
template <typename T>
T findMax(T arr[], int size) {
    T max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
//    int arr[] = {1, 2, 3, 4, 5};
//    std::cout << "Max element in array: " << findMax(arr, 5) << '\n';
//
//    try {
//        Queue<5, int> queue;
//        std::cout << "Dequeued: " << queue.dequeue() << '\n';
//        queue.enqueue(1);
//        queue.enqueue(2);
//        queue.enqueue(3);
//        queue.enqueue(4);
//        queue.enqueue(5);
//
//        // Следующая строка вызовет исключение Overflow
//        std::cout << "Dequeued: " << queue.dequeue() << '\n';
//        std::cout << "Dequeued: " << queue.dequeue() << '\n';
//        std::cout << "Dequeued: " << queue.dequeue() << '\n';
//        std::cout << "Dequeued: " << queue.dequeue() << '\n';
//        std::cout << "Dequeued: " << queue.dequeue() << '\n';
//
//        // Следующая строка вызовет исключение Underflow
//    } catch (const std::exception& e) {
//        std::cerr << "Caught exception: " << e.what() << '\n';
//    }

    return 0;
}