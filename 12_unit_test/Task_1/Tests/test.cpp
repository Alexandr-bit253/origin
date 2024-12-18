#include "gtest/gtest.h"
#include <extended_array.h>

// FIRST PART
TEST(ExtArrayTest, EmptyArraySize) {
    ExtArray<int> emptyArray(0);
    EXPECT_EQ(emptyArray.size(), 0);
}

TEST(ExtArrayTest, EmptyArrayMean) {
    ExtArray<int> emptyArray(0);
    EXPECT_EQ(emptyArray.mean(), 0.0);
}

TEST(ExtArrayTest, EmptyArrayMedian) {
    ExtArray<int> emptyArray(0);
    EXPECT_EQ(emptyArray.median(), 0.0);
}

TEST(ExtArrayTest, EmptyArrayMode) {
    ExtArray<int> emptyArray(0);
    auto mode = emptyArray.mode();
    EXPECT_EQ(mode.first, 0);
    EXPECT_EQ(mode.second, 0);
}

// SECOND PART
TEST(ExtArrayTest, MeanWithValidRange) {
    ExtArray<int> array{ 1, 2, 3, 4, 5 };

    EXPECT_NEAR(array.mean(0, 5), 3.0, 1e-5); 
    EXPECT_NEAR(array.mean(1, 4), 3.0, 1e-5); 
    EXPECT_NEAR(array.mean(2, 3), 3.0, 1e-5); 
}

TEST(ExtArrayTest, MeanWithInvalidRange) {
    ExtArray<int> array{ 1, 2, 3, 4, 5 };

    EXPECT_THROW(array.mean(3, 2), std::invalid_argument); 
    EXPECT_THROW(array.mean(5, 5), std::invalid_argument); 
    EXPECT_THROW(array.mean(6, 7), std::invalid_argument); 
    EXPECT_THROW(array.mean(4, 6), std::invalid_argument); 
}

//THIRD PART
TEST(ExtArrayTest, CheckSumWithBoolArray) {
    ExtArray<bool> boolArray{ true, false, true, true, false };
    EXPECT_EQ(boolArray.checkSum(), 3); // 3 элемента равны true
}

TEST(ExtArrayTest, CheckSumWithValidIntArray) {
    ExtArray<int> intArray{ 1, 0, 1, 1, 0 };
    EXPECT_EQ(intArray.checkSum(), 3); // 3 элемента равны 1
}

TEST(ExtArrayTest, CheckSumWithInvalidIntArray) {
    ExtArray<int> intArray{ 1, 2, 0, 1 };
    EXPECT_THROW(intArray.checkSum(), std::logic_error); // Массив содержит недопустимое значение 2
}

TEST(ExtArrayTest, CheckSumWithInvalidType) {
    ExtArray<double> doubleArray{ 1.0, 0.0, 1.0 };
    EXPECT_THROW(doubleArray.checkSum(), std::bad_typeid); // Тип double не поддерживается
}

TEST(ExtArrayTest, CheckSumWithEmptyArray) {
    ExtArray<int> emptyArray(0);
    EXPECT_EQ(emptyArray.checkSum(), 0); // Для пустого массива контрольная сумма равна 0
}