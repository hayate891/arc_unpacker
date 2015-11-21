#include "fmt/leaf/kcap_group/kcap_archive_decoder.h"
#include "test_support/catch.hh"
#include "test_support/decoder_support.h"
#include "test_support/file_support.h"

using namespace au;
using namespace au::fmt::leaf;

static const std::string dir = "tests/fmt/leaf/files/kcap/";

static void do_test(const std::string &input_path)
{
    const std::vector<std::shared_ptr<File>> expected_files
    {
        tests::stub_file("123.txt", "1234567890"_b),
        tests::stub_file("abc.xyz", "abcdefghijklmnopqrstuvwxyz"_b),
    };
    const KcapArchiveDecoder decoder;
    const auto input_file = tests::file_from_path(dir + input_path);
    const auto actual_files = tests::unpack(decoder, *input_file);
    tests::compare_files(expected_files, actual_files, true);
}

TEST_CASE("Leaf KCAP archives", "[fmt]")
{
    SECTION("Version 1")
    {
        do_test("v1.pak");
    }

    SECTION("Version 2, compressed")
    {
        do_test("v2-compressed.pak");
    }

    SECTION("Version 2, uncompressed")
    {
        do_test("v2-uncompressed.pak");
    }
}