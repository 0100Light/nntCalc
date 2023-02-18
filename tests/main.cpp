//
// Created by user on 2023/2/18.
//

#include <gtest/gtest.h>

int main(int argc, char* argv[]){

    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}

TEST(MainSuite, google_test_should_run){
    EXPECT_TRUE(true);
}
