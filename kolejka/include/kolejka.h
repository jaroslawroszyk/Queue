#pragma once

#include <string>
#include <initializer_list>

class Queue
{
public:
    Queue();

    Queue(int capacity);

    Queue(std::initializer_list<std::string>);

    Queue(const Queue &rhs);

    Queue(Queue &&rhs) noexcept;

    Queue &operator=(const Queue &rhs);

    ~Queue();

    auto insert(std::string) -> void;

    auto check() -> std::string;

    auto size() -> int;

    auto pop() -> std::string;

private:
    int capacity;
    std::string *tab;
    int count;
    int begin;
};