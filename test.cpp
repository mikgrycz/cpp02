#include <gtest/gtest.h>
#include "String.h"

class StringTest : public ::testing::Test {
protected:
    String s1;
    String s2;
};

TEST_F(StringTest, TestDefaultConstructor) {
    EXPECT_EQ(s1.get(0), '\0');
}

TEST_F(StringTest, TestConstructorWithCString) {
    String s("hello");
    EXPECT_EQ(s.get(0), 'h');
}

TEST_F(StringTest, TestCopyConstructor) {
    String s("hello");
    String t(s);
    EXPECT_EQ(t.get(0), 'h');
}

TEST_F(StringTest, TestAssignmentOperator) {
    String s("hello");
    s1 = s;
    EXPECT_EQ(s1.get(0), 'h');
}

TEST_F(StringTest, TestSet) {
    s1.set(0, 'h');
    EXPECT_EQ(s1.get(0), 'h');
}

TEST_F(StringTest, TestGet) {
    s1.set(0, 'h');
    EXPECT_EQ(s1.get(0), 'h');
}

TEST_F(StringTest, TestAdditionOperator) {
    String s("hello");
    String t("world");
    String u = s + t;
    EXPECT_EQ(u.get(0), 'h');
    EXPECT_EQ(u.get(5), 'w');
}

TEST_F(StringTest, TestCopyOnChange) {
    s1 = "hello";
    s2 = s1;
    s1.set(0, 'j');
    EXPECT_EQ(s1.get(0), 'j');
    EXPECT_EQ(s2.get(0), 'h');
}