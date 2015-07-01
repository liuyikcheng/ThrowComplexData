#include "unity.h"
#include "Main.h"
#include "CException.h"
#include "ErrorObject.h"
#include "stdio.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_doThings(void) {
  ErrorObject *err;
  
	Try {
    doThings();
    TEST_FAIL_MESSAGE("Expect ERR_DUNNO_WHAT_HAPPEN to be thrown. "\
                      "But none thrown");
  } Catch(err) {
    TEST_ASSERT_EQUAL_STRING("Hey! Something is really wrong here.", err->errorMsg);
    TEST_ASSERT_EQUAL(ERR_DUNNO_WHAT_HAPPEN, err->errorCode);
    // printf("Error: %s\n", err->errorMsg);
    freeError(err);
  }
}

void test_specialAdd_given_minus_5_and_13_should_return_6(void){
  int result = specialAdd(-5, 11);
  TEST_ASSERT_EQUAL(6, result);
}

void test_specialAdd_given_7_and_18_should_throw_ERR_NUMBER_NOT_NEGATIVE(void){
  ErrorObject *err;
  int result;
  
  Try{
    result = specialAdd(7, 18);
    TEST_FAIL_MESSAGE("Expect ERR_NUMBER_NOT_NEGATIVE to be thrown. "\
                      "But none thrown");
  }Catch(err) {
    TEST_ASSERT_EQUAL_STRING("First number is not negative", err->errorMsg);
    TEST_ASSERT_EQUAL(ERR_NUMBER_NOT_NEGATIVE, err->errorCode);
    TEST_ASSERT_EQUAL(NULL, result);
  }
}

void test_specialAdd_given_minus_10_and_minus_5_should_throw_ERR_NUMBER_NOT_POSITIVE(void){
  ErrorObject *err;
  int result;
  
  Try{
    result = specialAdd(-10, -5);
    TEST_FAIL_MESSAGE("Expect ERR_NUMBER_NOT_POSITIVE to be thrown. "\
                      "But none thrown");
  }Catch(err) {
    TEST_ASSERT_EQUAL_STRING("Second number is not positive", err->errorMsg);
    TEST_ASSERT_EQUAL(ERR_NUMBER_NOT_POSITIVE, err->errorCode);
    TEST_ASSERT_EQUAL(NULL, result);
  }
}

void test_specialAdd_given_minus_60_and_53_should_throw_ERR_NUMBER_TOO_LARGE(void){
  ErrorObject *err;
  int result;
  
  Try{
    result = specialAdd(-60, 53);
    TEST_FAIL_MESSAGE("Expect ERR_NUMBER_TOO_LARGE to be thrown. "\
                      "But none thrown");
  }Catch(err) {
    TEST_ASSERT_EQUAL_STRING("Second number is more than 50", err->errorMsg);
    TEST_ASSERT_EQUAL(ERR_NUMBER_TOO_LARGE, err->errorCode);
    TEST_ASSERT_EQUAL(NULL, result);
  }
}

void test_specialAdd_given_12_and_minus_100_should_throw_ERR_NUMBER_NOT_NEGATIVE(void){
  ErrorObject *err;
  int result;
  
  Try{
    result = specialAdd(12, -100);
    TEST_FAIL_MESSAGE("Expect ERR_NUMBER_NOT_NEGATIVE to be thrown. "\
                      "But none thrown");
  }Catch(err) {
    TEST_ASSERT_EQUAL_STRING("First number is not negative", err->errorMsg);
    TEST_ASSERT_EQUAL(ERR_NUMBER_NOT_NEGATIVE, err->errorCode);
    TEST_ASSERT_EQUAL(NULL, result);
  }
}