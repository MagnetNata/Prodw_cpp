#pragma once

#include <iostream>
//подключаем макросы catch2
#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_session.hpp>

//проверяемые функции Empty, Size, Clear
struct ListNode
{
public:
    ListNode(int value, ListNode* prev = nullptr, ListNode* next = nullptr)
        : value(value), prev(prev), next(next)
    {
        if (prev != nullptr) prev->next = this;
        if (next != nullptr) next->prev = this;
    }

public:
    int value;
    ListNode* prev;
    ListNode* next;
};


class List
{
public:
    List()
        : m_head(new ListNode(static_cast<int>(0))), m_size(0),
        m_tail(new ListNode(0, m_head))
    {       
    }

    virtual ~List()
    {
        Clear();
        delete m_head;
        delete m_tail;
    }

    bool Empty() { return m_size == 0; }

    unsigned long Size() { return m_size; }

    void PushFront(int value)
    {
        new ListNode(value, m_head, m_head->next);
        ++m_size;
    }

    void PushBack(int value)
    {
        new ListNode(value, m_tail->prev, m_tail);
        ++m_size;
    }

    int PopFront()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_head->next->next);
        int ret = node->value;
        delete node;
        return ret;
    }

    int PopBack()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_tail);
        int ret = node->value;
        delete node;
        return ret;
    }

    void Clear()
    {
        auto current = m_head->next;
        while (current != m_tail)
        {
            current = current->next;
            delete extractPrev(current);
        }
    }

private:
    ListNode* extractPrev(ListNode* node)
    {
        auto target = node->prev;
        target->prev->next = target->next;
        target->next->prev = target->prev;
        --m_size;
        return target;
    }

private:
    ListNode* m_head;
    ListNode* m_tail;
    unsigned long m_size;
};

//юнит-тест
TEST_CASE( "List" ) {
    List l;
    INFO( "PushBack" );
    l.PushBack(5);
    CHECK( l.Size() == 1 );

    INFO( "PushFront" );
    l.PushFront(5);
    CHECK( l.Size() == 2 );

    INFO( "PopBack" );
    l.PopBack();
    CHECK( l.Size() == 1 );

    INFO( "PopFront" );
    l.PopFront();
    CHECK( l.Size() == 0 );
 
    INFO( "Difficult_test" );
    l.PushBack(23);
    l.PushFront(55);
    l.PopFront();
    l.PushFront(12);
    l.PopBack();
    l.PushBack(18);
    l.PushFront(5);
    CHECK( l.Size() == 3 );

    INFO( "PopBack_empty" );
    l.PopBack();
    REQUIRE( l.Size() == 0 );

    INFO( "PopFront_empty" );
    l.PopFront();
    REQUIRE( l.Size() == 0 );
}

int main( int argc, char* argv[] ){
    return Catch::Session().run( argc, argv );
}
  



