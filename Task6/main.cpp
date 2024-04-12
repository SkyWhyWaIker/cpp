#include <iostream>
#include <vector>
#include <algorithm>

// Функция any_of
template<typename Iterator, typename Predicate>
bool Any_of(Iterator first, Iterator last, Predicate pred) {
    while (first != last) {
        if (pred(*first)) {
            return true;
        }
        ++first;
    }
    return false;
}

// Функция one_of
template<typename Iterator, typename Predicate>
bool one_of(Iterator first, Iterator last, Predicate pred) {
    bool found = false;
    while (first != last) {
        if (pred(*first)) {
            if (found) return false;
            found = true;
        }
        ++first;
    }
    return found;
}

// Функция is_palindrome
template<typename Iterator, typename Predicate>
bool is_palindrome(Iterator first, Iterator last, Predicate pred) {
    if (first == last) return true;
    --last;
    while (first != last) {
        if (!pred(*first, *last)) return false;
        ++first;
        if (first == last) break;
        --last;
    }
    return true;
}

// Пример пользовательского типа данных
struct CPoint {
    int x, y;
    CPoint(int x, int y) : x(x), y(y) {}
};

// Пример предиката для CPoint
bool is_equal(const CPoint& p1, const CPoint& p2) {
    return p1.x == p2.x && p1.y == p2.y;
}

// Функция для ввода вектора целых чисел
std::vector<int> input_vector_int() {
    std::vector<int> v;
    int n, value;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;
    std::cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> value;
        v.push_back(value);
    }
    return v;
}

// Функция для ввода вектора CPoint
std::vector<CPoint> input_vector_CPoint() {
    std::vector<CPoint> points;
    int n, x, y;
    std::cout << "Enter the number of points: ";
    std::cin >> n;
    std::cout << "Enter the points (x y): ";
    for (int i = 0; i < n; ++i) {
        std::cin >> x >> y;
        points.emplace_back(x, y);
    }
    return points;
}

int main() {
    int choice;
    std::vector<int> v;
    std::vector<CPoint> points;

    std::cout << "Choose an option:\n";
    std::cout << "1. Use predefined vectors\n";
    std::cout << "2. Input vectors manually\n";
    std::cin >> choice;

    if (choice == 1) {
        v = {1, 2, 3, 4, 5};
        points = {{1, 2}, {3, 4}, {5, 6}, {3, 4}, {1, 2}};
    } else if (choice == 2) {
        v = input_vector_int();
        points = input_vector_CPoint();
    } else {
        std::cout << "Invalid choice. Exiting.\n";
        return 1;
    }

    std::cout << "Any of the numbers is greater than 4: " << (Any_of(v.begin(), v.end(), [](int i){ return i > 4; }) ? "Yes" : "No") << '\n';

    std::cout << "Exactly one number is greater than 4: " << (one_of(v.begin(), v.end(), [](int i){ return i > 4; }) ? "Yes" : "No") << '\n';

    std::cout << "The sequence of points is a palindrome: " << (is_palindrome(points.begin(), points.end(), is_equal) ? "Yes" : "No") << '\n';

    return 0;
}