#include "Arduino.h"
#include "MacAddress6.h"
#include "MacAddress8.h"
#include <unity.h>

void test_constructor_def(void) {
    MacAddress6 ma;
    TEST_ASSERT_EQUAL(0, ma.Value());
}

void test_constructor_ulong(void) {
  uint64_t maval = 123456789012345;
  MacAddress6 ma = MacAddress6(maval);
  TEST_ASSERT_EQUAL(maval, ma.Value());
}

void test_constructor_bytearray(void) {
  uint8_t macbytes[] = {0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6};
  uint8_t macbytes2[6];
  MacAddress6 ma = MacAddress6(macbytes);
  ma.toBytes(macbytes2);
  TEST_ASSERT_EQUAL(0, memcmp(macbytes, macbytes2, 6));
}

void test_cstr(void) {
  char cs1[32];
  char cs2[32];
  MacAddress6 ma;
  sprintf(cs1, "AA:BB:CC:DD:EE:FF");
  ma.fromCStr(cs1);
  ma.toCStr(cs2);
  TEST_ASSERT_EQUAL(0, strcmp(cs1, cs2));
}

void test_string(void) {
  MacAddress6 ma;
  String s1 = "AA:BB:CC:DD:EE:FF";
  ma.fromString(s1);
  String s2 = ma.toString();
  TEST_ASSERT_EQUAL(true, s1==s2);
}

void test_copy_bytes(void) {
  uint8_t macbytes[] = {0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6};
  uint8_t macbytes2[6];
  MacAddress6 ma = macbytes;                //Implicit byte copy
  ma.toBytes(macbytes2);
  TEST_ASSERT_EQUAL(0, memcmp(macbytes, macbytes2, 6));
}

void test_copy_val(void) {
  uint64_t maval = 123456789012345;
  MacAddress6 ma = maval;                   //Convert uint64_t to object
  TEST_ASSERT_EQUAL(maval, ma);             //Implicit conversion to uint64_t
}

void test_classes_equal(void) {
  MacAddress6 ma1;
  MacAddress6 ma2;
  ma1.fromString("A1:B2:C3:D4:E5:D6");
  ma2.fromString("A1:B2:C3:D4:E5:D6");
  TEST_ASSERT_EQUAL(true, ma1==ma2);
}



void test_8constructor_def(void) {
    MacAddress8 ma;
    TEST_ASSERT_EQUAL(0, ma.Value());
}

void test_8constructor_ulong(void) {
  uint64_t maval = 123456789012345;
  MacAddress8 ma = MacAddress8(maval);
  TEST_ASSERT_EQUAL(maval, ma.Value());
}

void test_8constructor_bytearray(void) {
  uint8_t macbytes[] = {0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6, 0xAA, 0xBB};
  uint8_t macbytes2[8];
  MacAddress8 ma = MacAddress8(macbytes);
  ma.toBytes(macbytes2);
  TEST_ASSERT_EQUAL(0, memcmp(macbytes, macbytes2, 8));
}

void test_8cstr(void) {
  char cs1[32];
  char cs2[32];
  MacAddress8 ma;
  sprintf(cs1, "AA:BB:CC:DD:EE:FF:AB:AC");
  ma.fromCStr(cs1);
  ma.toCStr(cs2);
  TEST_ASSERT_EQUAL(0, strcmp(cs1, cs2));
}

void test_8string(void) {
  MacAddress8 ma;
  String s1 = "AA:BB:CC:DD:EE:FF:AB:AC";
  ma.fromString(s1);
  String s2 = ma.toString();
  TEST_ASSERT_EQUAL(true, s1==s2);
}

void test_8copy_bytes(void) {
  uint8_t macbytes[] = {0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6, 0xAA, 0xBB};
  uint8_t macbytes2[8];
  MacAddress8 ma = macbytes;                //Implicit byte copy
  ma.toBytes(macbytes2);
  TEST_ASSERT_EQUAL(0, memcmp(macbytes, macbytes2, 8));
}

void test_8copy_val(void) {
  uint64_t maval = 123456789012345;
  MacAddress8 ma = maval;                   //Convert uint64_t to object
  TEST_ASSERT_EQUAL(maval, ma);             //Implicit conversion to uint64_t
}

void test_8classes_equal(void) {
  MacAddress8 ma1;
  MacAddress8 ma2;
  ma1.fromString("A1:B2:C3:D4:E5:D6:AA:BB");
  ma2.fromString("A1:B2:C3:D4:E5:D6:AA:BB");
  TEST_ASSERT_EQUAL(true, ma1==ma2);
}

void runtests(void) {
    UNITY_BEGIN();
    RUN_TEST(test_constructor_def);
    RUN_TEST(test_constructor_ulong);
    RUN_TEST(test_constructor_bytearray);
    RUN_TEST(test_cstr);
    RUN_TEST(test_string);
    RUN_TEST(test_copy_bytes);
    RUN_TEST(test_copy_val);
    RUN_TEST(test_classes_equal);

    RUN_TEST(test_8constructor_def);
    RUN_TEST(test_8constructor_ulong);
    RUN_TEST(test_8constructor_bytearray);
    RUN_TEST(test_8cstr);
    RUN_TEST(test_8string);
    RUN_TEST(test_8copy_bytes);
    RUN_TEST(test_8copy_val);
    RUN_TEST(test_8classes_equal);
    UNITY_END();
}

void setup() {
    Serial.begin(115200);
    delay(2000);  // Allow USB connection to stabilize
    runtests();
}

void loop() {
    delay(5000);
}