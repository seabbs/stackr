// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppEigen.h>
#include <Rcpp.h>

using namespace Rcpp;


RcppExport SEXP _rcpp_module_boot_stan_fit4model_average_quantiles_mod();
RcppExport SEXP _rcpp_module_boot_stan_fit4stacking_crps_mod();

static const R_CallMethodDef CallEntries[] = {
    {"_rcpp_module_boot_stan_fit4model_average_quantiles_mod", (DL_FUNC) &_rcpp_module_boot_stan_fit4model_average_quantiles_mod, 0},
    {"_rcpp_module_boot_stan_fit4stacking_crps_mod", (DL_FUNC) &_rcpp_module_boot_stan_fit4stacking_crps_mod, 0},
    {NULL, NULL, 0}
};

RcppExport void R_init_stackr(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
