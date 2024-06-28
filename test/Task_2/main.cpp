#include <iostream>
//подключаем макросы catch2
#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_session.hpp>
#include "list_node.h"

//юнит-тест
TEST_CASE( "List" ) {
    List l;

    SECTION("adding an element using the function PushBack")
    {
        l.PushBack(5);
        CHECK(l.Size() == 1);
    }
    
    SECTION("adding an element using the function PushFront")
    {
        l.PushFront(5);
        CHECK(l.Size() == 1);
    }

    SECTION("deleting an element using the function PopBack")
    {
        l.PushBack(5);
        l.PushBack(15);
        l.PopBack();
        CHECK(l.Size() == 1);
    }

    SECTION("deleting an element using the function PopFront")
    {
        l.PushBack(15);
        l.PopFront();
        CHECK(l.Size() == 0);
    }

    SECTION("Difficult test adding and deleting elements")
    {
        l.PushBack(23);
        l.PushFront(55);
        l.PopFront();
        l.PushFront(12);
        l.PopBack();
        l.PushBack(18);
        l.PushFront(5);
        CHECK(l.Size() == 3);
    }

    SECTION("deleting an element using the function PopBack when list is empty")
    {
        l.PushBack(15);
        l.PopBack();
        REQUIRE_THROWS(l.PopBack());
    }

    SECTION("deleting an element using the function PopFront when list is empty")
    {
        REQUIRE_THROWS(l.PopFront());
    }

}

int main( int argc, char* argv[] ){
    return Catch::Session().run( argc, argv );
}
  



