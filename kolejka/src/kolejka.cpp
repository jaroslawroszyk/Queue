#include "../include/kolejka.h"
#include <algorithm>
#include <string>
#include <stdexcept>

constexpr int defaultCapacity = 4;

Queue::Queue(int capacity) : capacity(capacity), tab(nullptr), count(0), begin(0)
{
    tab = new std::string[capacity];
}

Queue::Queue() : Queue(defaultCapacity)
{
}

Queue::Queue(std::initializer_list<std::string> strList)
        : capacity(strList.size() + defaultCapacity), tab(nullptr), count(strList.size()), begin(0)
{
    tab = new std::string[capacity];
    int i = 0;
    for (auto el: strList)
    {
        tab[i] = el;
        ++i;
    }
}

Queue::~Queue()
{
    delete[]tab;
}

auto Queue::insert(std::string str) -> void  // wstawiamy napis do tablicy stringow na ostatnie miejsce
{
    if (capacity <= count)
        throw std::out_of_range("capacity is to low");
    int firstEmptyIndex = (begin + count) % capacity;
    tab[firstEmptyIndex] = str;
    ++count;
}

auto Queue::check() -> std::string  // zwracamy co znajduje sie na 1 miejscu w tablicy
{
    return tab[0];
}

auto Queue::size() -> int
{
    return count;
}

auto Queue::pop() -> std::string
{
    --count;
    std::string result = tab[begin];
    tab[begin] = "";
    begin++;
    begin %= capacity;
    return result;
}

Queue::Queue(const Queue &rhs) : capacity(rhs.capacity), tab(nullptr), count(rhs.count), begin(rhs.begin)
{
    tab = new std::string[capacity];
    for (int i = 0; i < count; ++i)
    {
        tab[i] = rhs.tab[i];
    }
}

Queue::Queue(Queue &&rhs) noexcept: capacity(rhs.capacity), tab(rhs.tab), count(rhs.count), begin(rhs.begin)
{
    rhs.tab = nullptr;
}

//Queue &Queue::operator=(const Queue &rhs) : capacity(rhs.capacity),tab(nullptr), count(rhs.cout),begin(rhs.begin()
//{
//    if (this == &rhs)
//        return *this;
//    if (capacity != rhs.capacity)
//    {
//        delete[]tab;
//        tab = new std::string[rhs.capacity];
//    }
//    std::copy(rhs.tab,rhs.tab + rhs.capacity, tab);
//    return *this;
//}

