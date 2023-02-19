#include <gtest/gtest.h>
#include "../CalculateService.hpp"

int main(int argc, char* argv[]){

    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}

class CDFParamTest : public ::testing::TestWithParam<double> {

protected:
/*
    ref: https://www.danielsoper.com/statcalc/calculator.aspx?id=53
*/
    std::map<double, double> resMap = {
            {0, 0.5},
            {1, 0.84134475},
            {1.1, 0.86433394},
            {1.3, 0.90319952},
            {1.5, 0.93319280},
            {1.64, 0.94949741652589625},
            {3, 0.99865010}
    };
};


TEST_P(CDFParamTest, expect_near){
    auto in = GetParam();
    EXPECT_NEAR(CalculateService::normalCDF(in), resMap[in], 0.0000001);
}

INSTANTIATE_TEST_SUITE_P(
        simple_values,
        CDFParamTest,
        ::testing::Values(0, 1, 1.1, 1.3, 1.5, 1.64, 3)
        );


class KraemerMethodTests : public ::testing::TestWithParam<double> {
protected:
    std::map<double, double> res = {
            {0.34, 5.3 },
            {0.17, 10.5 },
            { 0.21, 8.5 }
    };
};

TEST_P(KraemerMethodTests, expect_near){
    EXPECT_NEAR(res[GetParam()], CalculateService::KraemerMethod(GetParam()), 0.1);
}

INSTANTIATE_TEST_SUITE_P(values_from_table_02,
                         KraemerMethodTests,
                         ::testing::Values(0.34, 0.17, 0.21)
                         );

void PPFDemo()
{
    std::cout << "\nShow that the NormalCDFInverse function is accurate at \n"
              << "0.05, 0.15, 0.25, ..., 0.95 and at a few extreme values.\n\n";

    double p[] =
            {
                    0.0000001,
                    0.00001,
                    0.001,
                    0.05,
                    0.15,
                    0.25,
                    0.35,
                    0.45,
                    0.55,
                    0.65,
                    0.75,
                    0.85,
                    0.95,
                    0.999,
                    0.99999,
                    0.9999999
            };

    // Exact values computed by Mathematica.
    double exact[] =
            {
                    -5.199337582187471,
                    -4.264890793922602,
                    -3.090232306167813,
                    -1.6448536269514729,
                    -1.0364333894937896,
                    -0.6744897501960817,
                    -0.38532046640756773,
                    -0.12566134685507402,
                    0.12566134685507402,
                    0.38532046640756773,
                    0.6744897501960817,
                    1.0364333894937896,
                    1.6448536269514729,
                    3.090232306167813,
                    4.264890793922602,
                    5.199337582187471
            };

    double maxerror = 0.0;
    int numValues = sizeof(p)/sizeof(double);
    std::cout << "p, exact CDF inverse, computed CDF inverse, diff\n\n";
    std::cout << std::setprecision(7);
    for (int i = 0; i < numValues; ++i)
    {
        double computed = CalculateService::NormalCDFInverse(p[i]);
        double error = exact[i] - computed;
        std::cout << p[i] << ", " << exact[i] << ", "
                  << computed << ", " << error << "\n";         if (fabs(error) > maxerror)
            maxerror = fabs(error);
    }

    std::cout << "\nMaximum error: " << maxerror << "\n\n";
}

TEST(PPF, ppf_demo){
    PPFDemo();
    EXPECT_TRUE(true);
}

class FuruTests : public ::testing::TestWithParam<double> {
protected:
};

TEST_P(FuruTests, d0_34){
    std::map<double, double> ans = {
            { 0.42, 7.4 },
            { 0.35, 7.6 },
            { 0.26, 8.3 },
            { 0.21, 9.1 },
    };

    EXPECT_NEAR(CalculateService::FurukawaMethod(0.34, GetParam()), ans[GetParam()], 0.1);
}


INSTANTIATE_TEST_SUITE_P(d_0_34, FuruTests,
    ::testing::Values(0.42, 0.35, 0.26, 0.21)
);