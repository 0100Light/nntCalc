
#include "CalculateService.hpp"
#include <cmath>
#include <sstream>

double CalculateService::FurukawaMethod(double cohen_d, double cer) {
    return 1/(pnorm(cohen_d + qnorm(cer)) - cer);
}

double CalculateService::KraemerMethod(double cohen_d) {
    // maximum error = 0.1
    return 1 / ((2 * pnorm(cohen_d / sqrt(2)) -1));
}

double CalculateService::normalCDF(double x) {
    return std::erfc(-x / std::sqrt(2)) / 2;
}

double CalculateService::pnorm(double x){
    return normalCDF(x);
}

double CalculateService::qnorm(double x){
    return normalPPF(x);
}

double CalculateService::normalPPF(double x) {
    return NormalCDFInverse(x);
}

double CalculateService::RationalApproximation(double t)
{
    // Abramowitz and Stegun formula 26.2.23.
    // The absolute value of the error should be less than 4.5 e-4.
    double c[] = {2.515517, 0.802853, 0.010328};
    double d[] = {1.432788, 0.189269, 0.001308};
    return t - ((c[2]*t + c[1])*t + c[0]) /
               (((d[2]*t + d[1])*t + d[0])*t + 1.0);
}

double CalculateService::NormalCDFInverse(double p)
{
    /*
     * ref: https://www.johndcook.com/blog/cpp_phi_inverse/
     *
     * Maximum error: 0.0004433814
     *
     * */

    if (p <= 0.0 || p >= 1.0)
    {
        std::stringstream os;
        os << "Invalid input argument (" << p
           << "); must be larger than 0 but less than 1.";
        throw std::invalid_argument( os.str() );
    }

    // See article above for explanation of this section.
    if (p < 0.5)
    {
        // F^-1(p) = - G^-1(p)
        return -RationalApproximation( sqrt(-2.0*log(p)) );
    }
    else
    {
        // F^-1(p) = G^-1(1-p)
        return RationalApproximation( sqrt(-2.0*log(1-p)) );
    }
}

