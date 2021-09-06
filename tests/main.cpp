#include <gtest/gtest.h>
#include <fingerprint.h>
#include <string>

TEST(FingerprintTests, construction)
{
    //fgpt is constructed empty and invalid;
    Fingerprint test_fgpt;
    EXPECT_EQ(0, test_fgpt.get_size());
    EXPECT_FALSE(test_fgpt.is_valid());
    //after which it is filled via either string;
    std::string test_fgpt_string = "HA256 Fingerprint=34:66:B6:49:AB:A7:DC:9B:81:D2:0A:6B:20:0D:60:A5:00:A3:46:8B:10:8D:1B:B8:BE:3C:0A:D5:B9:F7:43:AD";
    EXPECT_TRUE(test_fgpt.parse_from_string(test_fgpt_string));
    Fingerprint fgpt_two = test_fgpt;
    //or file
    EXPECT_TRUE(test_fgpt.parse_from_file("../../../consumer/test_digest.txt"));

    //as they are both generated from the same string - they should be equal which we will confirm by comparing their first keys
    EXPECT_EQ(test_fgpt[0], "34");
    EXPECT_EQ(fgpt_two[0], "34");
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}