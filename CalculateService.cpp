//
// Created by user on 2023/2/17.
//

#include "CalculateService.hpp"
#include <cmath>

double CalculateService::CohendToNnt(double cohen_d, double control_proportion) {
/*
    This function takes in a Cohen's d effect size and
    a control group proportion and returns the number needed to treat (NNT).
*/

    // TODO: let user define n
    double n = 100;

    double z = 1.96; // 95% confidence interval
    double p1 = 1 - control_proportion;
    double p2 = p1 + cohen_d;
    double q1 = control_proportion;
    double q2 = 1 - p2;
    double pbar = (p1 + p2) / 2;
    double qbar = (q1 + q2) / 2;
    double nnt = 1 / (2 * sqrt(pbar * qbar) * asinh(sqrt((p2 * q1) / (p1 * q2)))
            - z * sqrt((p1 * q1 + p2 * q2) / (p1 * p2 * n)));
    return nnt;
}
