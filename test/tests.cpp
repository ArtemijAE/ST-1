// Copyright 2025 UNN-CS

#include <gtest/gtest.h>
#include <cstdint>
#include "alg.h"


TEST(st1, sumPrime1) {
  uint64_t res = sumPrime(2000000);
  uint64_t expected = 142913828922;
  EXPECT_EQ(expected, res);
}
TEST(st1, sumPrime2) {
  uint64_t res = sumPrime(10);
  uint64_t expected = 17;
  EXPECT_EQ(expected, res);
}
TEST(CheckPrimeTest, HandlesNonPrimes) {
    EXPECT_FALSE(checkPrime(0));
    EXPECT_FALSE(checkPrime(1));
    EXPECT_FALSE(checkPrime(4));
    EXPECT_FALSE(checkPrime(9));
    EXPECT_FALSE(checkPrime(15));
    EXPECT_FALSE(checkPrime(25));
    EXPECT_FALSE(checkPrime(49));
    EXPECT_FALSE(checkPrime(121));
}
TEST(CheckPrimeTest, HandlesSmallPrimes) {
    EXPECT_TRUE(checkPrime(2));
    EXPECT_TRUE(checkPrime(3));
    EXPECT_TRUE(checkPrime(5));
    EXPECT_TRUE(checkPrime(7));
    EXPECT_TRUE(checkPrime(11));
    EXPECT_TRUE(checkPrime(13));
    EXPECT_TRUE(checkPrime(17));
    EXPECT_TRUE(checkPrime(19));
}
TEST(CheckPrimeTest, HandlesLargePrime) {
    EXPECT_TRUE(checkPrime(982451653)); 
    EXPECT_TRUE(checkPrime(2147483647)); 
}
TEST(NPrimeTest, HandlesFirstPrimes) {
    EXPECT_EQ(nPrime(1), 2);
    EXPECT_EQ(nPrime(2), 3);
    EXPECT_EQ(nPrime(3), 5);
    EXPECT_EQ(nPrime(4), 7);
    EXPECT_EQ(nPrime(5), 11);
    EXPECT_EQ(nPrime(6), 13);
    EXPECT_EQ(nPrime(7), 17);
    EXPECT_EQ(nPrime(8), 19);
    EXPECT_EQ(nPrime(9), 23);
    EXPECT_EQ(nPrime(10), 29);
}
TEST(NPrimeTest, HandlesZeroIndex) {
    EXPECT_EQ(nPrime(0), 0);
}
TEST(NPrimeTest, HandlesLargerIndices) {
    EXPECT_EQ(nPrime(15), 47);
    EXPECT_EQ(nPrime(20), 71);
    EXPECT_EQ(nPrime(25), 97);
}
TEST(NextPrimeTest, HandlesSmallNumbers) {
    EXPECT_EQ(nextPrime(1), 2);
    EXPECT_EQ(nextPrime(2), 3);
    EXPECT_EQ(nextPrime(3), 5);
    EXPECT_EQ(nextPrime(4), 5);
    EXPECT_EQ(nextPrime(5), 7);
    EXPECT_EQ(nextPrime(6), 7);
    EXPECT_EQ(nextPrime(7), 11);
    EXPECT_EQ(nextPrime(8), 11);
    EXPECT_EQ(nextPrime(9), 11);
    EXPECT_EQ(nextPrime(10), 11);
}
TEST(NextPrimeTest, HandlesNumbersAfterPrimes) {
    EXPECT_EQ(nextPrime(11), 13);
    EXPECT_EQ(nextPrime(13), 17);
    EXPECT_EQ(nextPrime(17), 19);
    EXPECT_EQ(nextPrime(19), 23);
}
TEST(NextPrimeTest, HandlesLargerNumbers) {
    EXPECT_EQ(nextPrime(20), 23);
    EXPECT_EQ(nextPrime(30), 31);
    EXPECT_EQ(nextPrime(48), 53);
    EXPECT_EQ(nextPrime(54), 59);
    EXPECT_EQ(nextPrime(90), 97);
    EXPECT_EQ(nextPrime(100), 101);
}
TEST(NextPrimeTest, HandlesOverflow) {
    EXPECT_EQ(nextPrime(UINT64_MAX), 0);
}
TEST(SumPrimeTest, HandlesSmallBounds) {
    EXPECT_EQ(sumPrime(2), 0);
    EXPECT_EQ(sumPrime(3), 2);
    EXPECT_EQ(sumPrime(4), 2);
    EXPECT_EQ(sumPrime(5), 2);
    EXPECT_EQ(sumPrime(6), 5);
    EXPECT_EQ(sumPrime(7), 5);
    EXPECT_EQ(sumPrime(8), 10);
    EXPECT_EQ(sumPrime(9), 10);
    EXPECT_EQ(sumPrime(10), 17);
}
TEST(SumPrimeTest, HandlesLargerBounds) {
    EXPECT_EQ(sumPrime(11), 17);
    EXPECT_EQ(sumPrime(12), 28);
    EXPECT_EQ(sumPrime(13), 28);
    EXPECT_EQ(sumPrime(14), 41);
    EXPECT_EQ(sumPrime(15), 41);
    EXPECT_EQ(sumPrime(16), 41);
    EXPECT_EQ(sumPrime(17), 41);
    EXPECT_EQ(sumPrime(18), 58);
    EXPECT_EQ(sumPrime(19), 58);
    EXPECT_EQ(sumPrime(20), 77);
}
TEST(SumPrimeTest, HandlesKnownSums) {
    EXPECT_EQ(sumPrime(30), 129);   
    EXPECT_EQ(sumPrime(40), 197);   
    EXPECT_EQ(sumPrime(50), 328);  
}
