#include "Arduino.h"
#include "MacAddress.h"
#include "MacAddress8.h"
#include <unity.h>

void test_constructor_def(void) {
    MacAddress ma;
    TEST_ASSERT_EQUAL(0, ma.Value());
}

void test_constructor_ulong(void) {
  uint64_t maval = 123456789012345;
  MacAddress ma = MacAddress(maval);
  TEST_ASSERT_EQUAL(maval, ma.Value());
}

void test_constructor_bytearray(void) {
  uint8_t macbytes[] = {0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6};
  uint8_t macbytes2[6];
  MacAddress ma = MacAddress(macbytes);
  ma.toBytes(macbytes2);
  TEST_ASSERT_EQUAL(0, memcmp(macbytes, macbytes2, 6));
}

void test_constructor_bytes(void) {
  uint8_t macbytes[] = {0x00, 0xCD, 0x01, 0xFE, 0xB2, 0xF0};
  MacAddress ma = MacAddress(0x00, 0xCD, 0x01, 0xFE, 0xB2, 0xF0);
  uint8_t bytes[6];
  ma.toBytes(bytes);
  TEST_ASSERT_EQUAL(0, memcmp(macbytes, bytes, 6));
}

void test_cstr(void) {
  char cs1[32];
  char cs2[32];
  MacAddress ma;
  sprintf(cs1, "AA:BB:CC:DD:EE:FF");
  ma.fromCStr(cs1);
  ma.toCStr(cs2);
  TEST_ASSERT_EQUAL(0, strcmp(cs1, cs2));
}

void test_string(void) {
  MacAddress ma;
  String s1 = "AA:BB:CC:DD:EE:FF";
  ma.fromString(s1);
  String s2 = ma.toString();
  TEST_ASSERT_EQUAL(true, s1==s2);
}

void test_copy_bytes(void) {
  uint8_t macbytes[] = {0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6};
  uint8_t macbytes2[6];
  MacAddress ma = macbytes;                //Implicit byte copy
  ma.toBytes(macbytes2);
  TEST_ASSERT_EQUAL(0, memcmp(macbytes, macbytes2, 6));
}

void test_copy_val(void) {
  uint64_t maval = 123456789012345;
  MacAddress ma = maval;                   //Convert uint64_t to object
  TEST_ASSERT_EQUAL(maval, ma);             //Implicit conversion to uint64_t
}

void test_class_equals_ba(void) {
  uint8_t macbytes[] = {0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6};
  MacAddress ma = macbytes;
  TEST_ASSERT_EQUAL(true, ma==macbytes);
}

void test_classes_equal(void) {
  MacAddress ma1;
  MacAddress ma2;
  ma1.fromString("A1:B2:C3:D4:E5:D6");
  ma2.fromString("A1:B2:C3:D4:E5:D6");
  TEST_ASSERT_EQUAL(true, ma1==ma2);
}

void test_readindexedbyte(void) {
  uint8_t macbytes[] = {0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6};
  MacAddress ma = macbytes;
  uint8_t b5 = ma[5];
  TEST_ASSERT_EQUAL(b5, macbytes[5]);
}

void test_readindexedbyte_outofrange_neg(void) {
  uint8_t macbytes[] = {0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6};
  MacAddress ma = macbytes;
  uint8_t b0 = ma[-1];
  TEST_ASSERT_EQUAL(b0, macbytes[0]);
}

void test_readindexedbyte_outofrange_high(void) {
  uint8_t macbytes[] = {0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6};
  MacAddress ma = macbytes;
  uint8_t b5 = ma[999];
  TEST_ASSERT_EQUAL(b5, macbytes[5]);
}

void test_setindexedbyte(void) {
  uint8_t macbytes[] = {0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6};
  MacAddress ma = macbytes;
  ma[1] = 0xB9;
  TEST_ASSERT_EQUAL(ma[1], 0xB9);
}

void test_setindexedbyte_outofrange_neg(void) {
  uint8_t macbytes[] = {0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6};
  MacAddress ma = macbytes;
  ma[-1] = 0xB9;
  TEST_ASSERT_EQUAL(ma[0], 0xB9);
}

void test_setindexedbyte_outofrange_high(void) {
  uint8_t macbytes[] = {0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6};
  MacAddress ma = macbytes;
  ma[999] = 0x14;
  TEST_ASSERT_EQUAL(ma[5], 0x14);
}

void test_pointer_to_bytearray(void) {
  uint8_t macbytes[] = {0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6};
  MacAddress ma = macbytes;
  const uint8_t *ptr = ma;
  TEST_ASSERT_EQUAL(0, memcmp(ptr, macbytes, 6));
}

void test_pointer_to_uint64_t(void) {
  MacAddress ma = 0x123456;
  const uint64_t *ptr = ma;
  TEST_ASSERT_EQUAL(true, *ptr==0x123456);
}

// void test_printto(void) {
//   uint8_t macbytes[] = {0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6};
//   MacAddress ma = macbytes;
//   char buf[18];
//   ma.toCStr(buf);
//   char buf2[18];
//   ma.print(buf2);
// }



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

void test_8constructor_bytes(void) {
  uint8_t macbytes[] = {0x00, 0xCD, 0x01, 0xFE, 0xB2, 0xF0, 0x67, 0x44};
  MacAddress8 ma = MacAddress8(0x00, 0xCD, 0x01, 0xFE, 0xB2, 0xF0, 0x67, 0x44);
  uint8_t bytes[8];
  ma.toBytes(bytes);
  TEST_ASSERT_EQUAL(0, memcmp(macbytes, bytes, 8));
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

void test_8class_equals_ba(void) {
  uint8_t macbytes[] = {0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6, 0xAA, 0xBB};
  MacAddress ma = macbytes;
  TEST_ASSERT_EQUAL(true, ma==macbytes);
}

void test_8classes_equal(void) {
  MacAddress8 ma1;
  MacAddress8 ma2;
  ma1.fromString("A1:B2:C3:D4:E5:D6:AA:BB");
  ma2.fromString("A1:B2:C3:D4:E5:D6:AA:BB");
  TEST_ASSERT_EQUAL(true, ma1==ma2);
}

void test_8readindexedbyte(void) {
  uint8_t macbytes[] = {0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6, 0xAA, 0xBB};
  MacAddress8 ma = macbytes;
  uint8_t b7 = ma[7];
  TEST_ASSERT_EQUAL(b7, macbytes[7]);
}

void test_8readindexedbyte_outofrange_neg(void) {
  uint8_t macbytes[] = {0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6, 0xAA, 0xBB};
  MacAddress8 ma = macbytes;
  uint8_t b0 = ma[-1];
  TEST_ASSERT_EQUAL(b0, macbytes[0]);
}

void test_8readindexedbyte_outofrange_high(void) {
  uint8_t macbytes[] = {0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6, 0xAA, 0xBB};
  MacAddress8 ma = macbytes;
  uint8_t b7 = ma[999];
  TEST_ASSERT_EQUAL(b7, macbytes[7]);
}

void test_8setindexedbyte(void) {
  uint8_t macbytes[] = {0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6, 0xAA, 0xBB};
  MacAddress8 ma = macbytes;
  ma[6] = 0xB9;
  TEST_ASSERT_EQUAL(ma[6], 0xB9);
}

void test_8setindexedbyte_outofrange_neg(void) {
  uint8_t macbytes[] = {0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6, 0xAA, 0xBB};
  MacAddress8 ma = macbytes;
  ma[-1] = 0xB9;
  TEST_ASSERT_EQUAL(ma[0], 0xB9);
}

void test_8setindexedbyte_outofrange_high(void) {
  uint8_t macbytes[] = {0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6, 0xAA, 0xBB};
  MacAddress8 ma = macbytes;
  ma[999] = 0x14;
  TEST_ASSERT_EQUAL(ma[7], 0x14);
}

void test_8pointer_to_bytearray(void) {
  uint8_t macbytes[] = {0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6, 0xAA, 0xBB};
  MacAddress8 ma = macbytes;
  const uint8_t *ptr = ma;
  TEST_ASSERT_EQUAL(0, memcmp(ptr, macbytes, 8));
}

void test_8pointer_to_uint64_t(void) {
  MacAddress8 ma = 0x12345678;
  const uint64_t *ptr = ma;
  TEST_ASSERT_EQUAL(true, *ptr==0x12345678);
}

void runtests(void) {
    UNITY_BEGIN();
    RUN_TEST(test_constructor_def);
    RUN_TEST(test_constructor_ulong);
    RUN_TEST(test_constructor_bytearray);
    RUN_TEST(test_constructor_bytes);
    RUN_TEST(test_cstr);
    RUN_TEST(test_string);
    RUN_TEST(test_copy_bytes);
    RUN_TEST(test_copy_val);
    RUN_TEST(test_class_equals_ba);
    RUN_TEST(test_classes_equal);
    RUN_TEST(test_readindexedbyte);
    RUN_TEST(test_readindexedbyte_outofrange_neg);
    RUN_TEST(test_readindexedbyte_outofrange_high);
    RUN_TEST(test_setindexedbyte);
    RUN_TEST(test_setindexedbyte_outofrange_neg);
    RUN_TEST(test_setindexedbyte_outofrange_high);
    RUN_TEST(test_pointer_to_bytearray);
    RUN_TEST(test_pointer_to_uint64_t);
    //RUN_TEST(test_printto);

    RUN_TEST(test_8constructor_def);
    RUN_TEST(test_8constructor_ulong);
    RUN_TEST(test_8constructor_bytearray);
    RUN_TEST(test_8constructor_bytes);
    RUN_TEST(test_8cstr);
    RUN_TEST(test_8string);
    RUN_TEST(test_8copy_bytes);
    RUN_TEST(test_8copy_val);
    RUN_TEST(test_8class_equals_ba);
    RUN_TEST(test_8classes_equal);
    RUN_TEST(test_8readindexedbyte);
    RUN_TEST(test_8readindexedbyte_outofrange_neg);
    RUN_TEST(test_8readindexedbyte_outofrange_high);
    RUN_TEST(test_8setindexedbyte);
    RUN_TEST(test_8setindexedbyte_outofrange_neg);
    RUN_TEST(test_8setindexedbyte_outofrange_high);
    RUN_TEST(test_8pointer_to_bytearray);
    RUN_TEST(test_8pointer_to_uint64_t);
    //RUN_TEST(test_8printto);

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