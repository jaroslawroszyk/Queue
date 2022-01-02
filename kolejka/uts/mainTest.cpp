#include <gtest/gtest.h>
#include "../include/kolejka.h"

class QueueTest : public ::testing::Test
{
protected:
    QueueTest()
    {};

    ~QueueTest() override
    {};
};


TEST_F(QueueTest, TestingQueueWithOneInsertAndCheckSize)
{
    Queue sut(1);
    std::string str = "2022";
    sut.insert(str);
    EXPECT_EQ(sut.check(), str);
    int expectedSize = 1;
    EXPECT_EQ(sut.size(), expectedSize);
}

TEST_F(QueueTest, WhenCapacityIsTooLowShouldThrowException)
{
    Queue sut(1);
    EXPECT_THROW({
                     try
                     {
                         sut.insert("first");
                         sut.insert("secound");
                     } catch (const std::out_of_range &e)
                     {
                         EXPECT_STREQ("capacity is to low", e.what());
                         throw;
                     }

                 }, std::out_of_range);
}

TEST_F(QueueTest, TestingWhatIsInTheFirstPlaceOnArray)
{
    Queue sut(2);
    std::string str = "hello";
    std::string str2 = "2022";
    sut.insert(str);
    sut.insert(str2);
    EXPECT_EQ(sut.check(), str);
}

TEST_F(QueueTest, TestingSizeQueueShouldBeTHREE)
{
    Queue sut(3);
    std::string str = "hello";
    std::string str2 = "2022";
    std::string str3 = "xd";
    sut.insert(str);
    sut.insert(str2);
    sut.insert(str3);
    int expectedSize = 3;
    EXPECT_EQ(sut.size(), expectedSize);
}

TEST_F(QueueTest, WhenInsertTwoElementsAndPopOneShouldReturnSizeIsOne)
{
    Queue sut(2);
    std::string str = "hi";
    std::string str2 = "hi";
    sut.insert(str);
    sut.insert(str2);
    EXPECT_EQ(sut.check(), str);
    EXPECT_EQ(sut.pop(), str);
    int expectedSize = 1;
    EXPECT_EQ(sut.size(), expectedSize);
}

TEST_F(QueueTest, WhenInsertTwoElementsAndPopTwoShouldReturnSizeIsZero)
{
    Queue sut(2);
    std::string str = "hi";
    std::string str2 = "hi";
    sut.insert(str);
    sut.insert(str2);
    EXPECT_EQ(sut.check(), str);
    EXPECT_EQ(sut.pop(), str);
    EXPECT_EQ(sut.pop(), str2);
    int expectedSize = 0;
    EXPECT_EQ(sut.size(), expectedSize);
}

TEST_F(QueueTest, TestingCtrWithInitializerList)
{
    Queue sut({"Hello", "2022", "xD"});
    EXPECT_EQ(sut.size(), 3);

    EXPECT_EQ(sut.pop(), "Hello");
    EXPECT_EQ(sut.pop(), "2022");
    EXPECT_EQ(sut.pop(), "xD");

    EXPECT_EQ(sut.size(), 0);
}

TEST_F(QueueTest, WhenCopyQueueToAnotherwAndPopAllElementsShouldReturnSizeIsZero)
{
    Queue toCopy({"Hello", "2022", "c++", "good"});
    Queue sut(toCopy);

    EXPECT_EQ(toCopy.size(), 4);
    EXPECT_EQ(sut.size(), 4);

    EXPECT_EQ(sut.pop(), "Hello");
    EXPECT_EQ(sut.pop(), "2022");
    EXPECT_EQ(sut.pop(), "c++");
    EXPECT_EQ(sut.pop(), "good");

    int exceptedSize = 0;
    EXPECT_EQ(sut.size(), exceptedSize);
}

TEST_F(QueueTest, WhenMoveQueueToAnotherAndCheckingPopElementsShouldReturnSizeIsOne)
{
    Queue toMove({"Hello", "2022", "c++", "good"});
    Queue sut(std::move(toMove));

    EXPECT_EQ(toMove.size(), 4);
    EXPECT_EQ(sut.size(), 4);

    EXPECT_EQ(sut.pop(), "Hello");
    EXPECT_EQ(sut.pop(), "2022");
    EXPECT_EQ(sut.pop(), "c++");

    int exceptedSize = 1;
    EXPECT_EQ(sut.size(), exceptedSize);
}

TEST_F(QueueTest, WhenInsertTwoElementsAndNextToCopyQueueToAnotherQueueAndPopOneElementShouldReturnSizeIsOne)
{
    Queue toAssignment(3);
    toAssignment.insert("hello");
    toAssignment.insert("C++");
    int exceptedSize = 2;
    EXPECT_EQ(toAssignment.size(), exceptedSize);

    Queue sut = toAssignment;
    EXPECT_EQ(sut.size(), exceptedSize);

    exceptedSize = 1;
    sut.pop();
    EXPECT_EQ(sut.size(), 1);
}

TEST_F(QueueTest, When)
{
    Queue que1({"haha", "ha"});
    Queue que2;
    que2 = que1;

    EXPECT_EQ(que2.size(), 2);
}