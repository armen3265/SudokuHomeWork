#include "gtest/gtest.h"
#include "sudoku.h"

namespace {
TEST(SudokuTest, hardest) {
        bool is_hard = false;
        try
        {
                Sudoku sudoku;
                std::string task[sudoku.size] =
                {
                        "000000000",
                        "030000160",
                        "067035004",
                        "608120900",
                        "090080030",
                        "002079806",
                        "800690350",
                        "026000090",
                        "000000000"
                };
                sudoku.enterDigits(task);
                sudoku.solve();
}
        catch (const std::exception&)
        {
                is_hard = true;
        }
        EXPECT_TRUE(is_hard);
}

TEST(SudokuTest, solved)
{
  Sudoku sudoku;
  std::string task[9] =
  {
        "530070000",
        "600195000",
        "098000060",
        "800060003",
        "400803001",
        "700020006",
        "060000280",
        "000419005",
        "000080079"
};
        sudoku.enterDigits(task);
        sudoku.solve();

        std::string programAnswer = sudoku.answer();
        std::string trueAnswer = "534678912672195348198342567859761423426853791713924856961537284287419635345286179";

        EXPECT_EQ(trueAnswer, programAnswer);
}//Test
}//namespace

int main(int argv, char** argc)
{
        ::testing::InitGoogleTest(&argv, argc);
        return RUN_ALL_TESTS();
}
