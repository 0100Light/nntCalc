
#ifndef NNTCALC_CALCULATESERVICE_HPP
#define NNTCALC_CALCULATESERVICE_HPP


class CalculateService {

public:
    static double FurukawaMethod(double cohen_d, double cer);
    static double KraemerMethod(double cohen_d);

    static double normalCDF(double x);
    static double normalPPF(double x);
    static double pnorm(double x);
    static double qnorm(double x);

    static double RationalApproximation(double t);
    static double NormalCDFInverse(double p);
};


#endif //NNTCALC_CALCULATESERVICE_HPP
