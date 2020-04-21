// Generated by rstantools.  Do not edit by hand.

/*
    stackr is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    stackr is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with stackr.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef MODELS_HPP
#define MODELS_HPP
#define STAN__SERVICES__COMMAND_HPP
#include <rstan/rstaninc.hpp>
// Code generated by Stan version 2.19.1
#include <stan/model/model_header.hpp>
namespace model_model_average_quantiles_namespace {
using std::istream;
using std::string;
using std::stringstream;
using std::vector;
using stan::io::dump;
using stan::math::lgamma;
using stan::model::prob_grad;
using namespace stan::math;
static int current_statement_begin__;
stan::io::program_reader prog_reader__() {
    stan::io::program_reader reader;
    reader.add_event(0, 0, "start", "model_model_average_quantiles");
    reader.add_event(49, 47, "end", "model_model_average_quantiles");
    return reader;
}
template <typename T0__, typename T1__, typename T2__, typename T3__>
typename boost::math::tools::promote_args<T0__, T1__, T2__, T3__>::type
pointwise_interval_score(const T0__& y,
                             const T1__& lower,
                             const T2__& upper,
                             const T3__& alpha, std::ostream* pstream__) {
    typedef typename boost::math::tools::promote_args<T0__, T1__, T2__, T3__>::type local_scalar_t__;
    typedef local_scalar_t__ fun_return_scalar_t__;
    const static bool propto__ = true;
    (void) propto__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning
    int current_statement_begin__ = -1;
    try {
        {
        current_statement_begin__ = 3;
        local_scalar_t__ res(DUMMY_VAR__);
        (void) res;  // dummy to suppress unused var warning
        stan::math::initialize(res, DUMMY_VAR__);
        stan::math::fill(res, DUMMY_VAR__);
        stan::math::assign(res,(((upper - lower) + (((2 / alpha) * (lower - y)) * logical_lt(y, lower))) + (((2 / alpha) * (y - upper)) * logical_gt(y, upper))));
        current_statement_begin__ = 6;
        return stan::math::promote_scalar<fun_return_scalar_t__>(res);
        }
    } catch (const std::exception& e) {
        stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
        // Next line prevents compiler griping about no return
        throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
    }
}
struct pointwise_interval_score_functor__ {
    template <typename T0__, typename T1__, typename T2__, typename T3__>
        typename boost::math::tools::promote_args<T0__, T1__, T2__, T3__>::type
    operator()(const T0__& y,
                             const T1__& lower,
                             const T2__& upper,
                             const T3__& alpha, std::ostream* pstream__) const {
        return pointwise_interval_score(y, lower, upper, alpha, pstream__);
    }
};
#include <stan_meta_header.hpp>
class model_model_average_quantiles : public prob_grad {
private:
        int K;
        int T;
        double alpha;
        std::vector<matrix_d> forecasts;
        vector_d y;
        vector_d lambda;
        double dirichlet_alpha;
public:
    model_model_average_quantiles(stan::io::var_context& context__,
        std::ostream* pstream__ = 0)
        : prob_grad(0) {
        ctor_body(context__, 0, pstream__);
    }
    model_model_average_quantiles(stan::io::var_context& context__,
        unsigned int random_seed__,
        std::ostream* pstream__ = 0)
        : prob_grad(0) {
        ctor_body(context__, random_seed__, pstream__);
    }
    void ctor_body(stan::io::var_context& context__,
                   unsigned int random_seed__,
                   std::ostream* pstream__) {
        typedef double local_scalar_t__;
        boost::ecuyer1988 base_rng__ =
          stan::services::util::create_rng(random_seed__, 0);
        (void) base_rng__;  // suppress unused var warning
        current_statement_begin__ = -1;
        static const char* function__ = "model_model_average_quantiles_namespace::model_model_average_quantiles";
        (void) function__;  // dummy to suppress unused var warning
        size_t pos__;
        (void) pos__;  // dummy to suppress unused var warning
        std::vector<int> vals_i__;
        std::vector<double> vals_r__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning
        try {
            // initialize data block variables from context__
            current_statement_begin__ = 12;
            context__.validate_dims("data initialization", "K", "int", context__.to_vec());
            K = int(0);
            vals_i__ = context__.vals_i("K");
            pos__ = 0;
            K = vals_i__[pos__++];
            check_greater_or_equal(function__, "K", K, 2);
            current_statement_begin__ = 13;
            context__.validate_dims("data initialization", "T", "int", context__.to_vec());
            T = int(0);
            vals_i__ = context__.vals_i("T");
            pos__ = 0;
            T = vals_i__[pos__++];
            check_greater_or_equal(function__, "T", T, 1);
            current_statement_begin__ = 16;
            context__.validate_dims("data initialization", "alpha", "double", context__.to_vec());
            alpha = double(0);
            vals_r__ = context__.vals_r("alpha");
            pos__ = 0;
            alpha = vals_r__[pos__++];
            check_greater_or_equal(function__, "alpha", alpha, 0);
            check_less_or_equal(function__, "alpha", alpha, 1);
            current_statement_begin__ = 18;
            validate_non_negative_index("forecasts", "T", T);
            validate_non_negative_index("forecasts", "K", K);
            validate_non_negative_index("forecasts", "2", 2);
            context__.validate_dims("data initialization", "forecasts", "matrix_d", context__.to_vec(2,T,K));
            forecasts = std::vector<Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> >(2, Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>(T, K));
            vals_r__ = context__.vals_r("forecasts");
            pos__ = 0;
            size_t forecasts_j_2_max__ = K;
            size_t forecasts_j_1_max__ = T;
            size_t forecasts_k_0_max__ = 2;
            for (size_t j_2__ = 0; j_2__ < forecasts_j_2_max__; ++j_2__) {
                for (size_t j_1__ = 0; j_1__ < forecasts_j_1_max__; ++j_1__) {
                    for (size_t k_0__ = 0; k_0__ < forecasts_k_0_max__; ++k_0__) {
                        forecasts[k_0__](j_1__, j_2__) = vals_r__[pos__++];
                    }
                }
            }
            current_statement_begin__ = 19;
            validate_non_negative_index("y", "T", T);
            context__.validate_dims("data initialization", "y", "vector_d", context__.to_vec(T));
            y = Eigen::Matrix<double, Eigen::Dynamic, 1>(T);
            vals_r__ = context__.vals_r("y");
            pos__ = 0;
            size_t y_j_1_max__ = T;
            for (size_t j_1__ = 0; j_1__ < y_j_1_max__; ++j_1__) {
                y(j_1__) = vals_r__[pos__++];
            }
            current_statement_begin__ = 21;
            validate_non_negative_index("lambda", "T", T);
            context__.validate_dims("data initialization", "lambda", "vector_d", context__.to_vec(T));
            lambda = Eigen::Matrix<double, Eigen::Dynamic, 1>(T);
            vals_r__ = context__.vals_r("lambda");
            pos__ = 0;
            size_t lambda_j_1_max__ = T;
            for (size_t j_1__ = 0; j_1__ < lambda_j_1_max__; ++j_1__) {
                lambda(j_1__) = vals_r__[pos__++];
            }
            current_statement_begin__ = 22;
            context__.validate_dims("data initialization", "dirichlet_alpha", "double", context__.to_vec());
            dirichlet_alpha = double(0);
            vals_r__ = context__.vals_r("dirichlet_alpha");
            pos__ = 0;
            dirichlet_alpha = vals_r__[pos__++];
            // initialize transformed data variables
            // execute transformed data statements
            // validate transformed data
            // validate, set parameter ranges
            num_params_r__ = 0U;
            param_ranges_i__.clear();
            current_statement_begin__ = 26;
            validate_non_negative_index("weights", "K", K);
            num_params_r__ += (K - 1);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }
    ~model_model_average_quantiles() { }
    void transform_inits(const stan::io::var_context& context__,
                         std::vector<int>& params_i__,
                         std::vector<double>& params_r__,
                         std::ostream* pstream__) const {
        typedef double local_scalar_t__;
        stan::io::writer<double> writer__(params_r__, params_i__);
        size_t pos__;
        (void) pos__; // dummy call to supress warning
        std::vector<double> vals_r__;
        std::vector<int> vals_i__;
        current_statement_begin__ = 26;
        if (!(context__.contains_r("weights")))
            stan::lang::rethrow_located(std::runtime_error(std::string("Variable weights missing")), current_statement_begin__, prog_reader__());
        vals_r__ = context__.vals_r("weights");
        pos__ = 0U;
        validate_non_negative_index("weights", "K", K);
        context__.validate_dims("parameter initialization", "weights", "vector_d", context__.to_vec(K));
        Eigen::Matrix<double, Eigen::Dynamic, 1> weights(K);
        size_t weights_j_1_max__ = K;
        for (size_t j_1__ = 0; j_1__ < weights_j_1_max__; ++j_1__) {
            weights(j_1__) = vals_r__[pos__++];
        }
        try {
            writer__.simplex_unconstrain(weights);
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(std::runtime_error(std::string("Error transforming variable weights: ") + e.what()), current_statement_begin__, prog_reader__());
        }
        params_r__ = writer__.data_r();
        params_i__ = writer__.data_i();
    }
    void transform_inits(const stan::io::var_context& context,
                         Eigen::Matrix<double, Eigen::Dynamic, 1>& params_r,
                         std::ostream* pstream__) const {
      std::vector<double> params_r_vec;
      std::vector<int> params_i_vec;
      transform_inits(context, params_i_vec, params_r_vec, pstream__);
      params_r.resize(params_r_vec.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r(i) = params_r_vec[i];
    }
    template <bool propto__, bool jacobian__, typename T__>
    T__ log_prob(std::vector<T__>& params_r__,
                 std::vector<int>& params_i__,
                 std::ostream* pstream__ = 0) const {
        typedef T__ local_scalar_t__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // dummy to suppress unused var warning
        T__ lp__(0.0);
        stan::math::accumulator<T__> lp_accum__;
        try {
            stan::io::reader<local_scalar_t__> in__(params_r__, params_i__);
            // model parameters
            current_statement_begin__ = 26;
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> weights;
            (void) weights;  // dummy to suppress unused var warning
            if (jacobian__)
                weights = in__.simplex_constrain(K, lp__);
            else
                weights = in__.simplex_constrain(K);
            // model body
            {
            current_statement_begin__ = 31;
            validate_non_negative_index("average_upper", "T", T);
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> average_upper(T);
            stan::math::initialize(average_upper, DUMMY_VAR__);
            stan::math::fill(average_upper, DUMMY_VAR__);
            stan::math::assign(average_upper,rep_vector(0, T));
            current_statement_begin__ = 32;
            validate_non_negative_index("average_lower", "T", T);
            Eigen::Matrix<local_scalar_t__, Eigen::Dynamic, 1> average_lower(T);
            stan::math::initialize(average_lower, DUMMY_VAR__);
            stan::math::fill(average_lower, DUMMY_VAR__);
            stan::math::assign(average_lower,rep_vector(0, T));
            current_statement_begin__ = 34;
            for (int k = 1; k <= K; ++k) {
                current_statement_begin__ = 35;
                stan::math::assign(average_lower, add(average_lower, multiply(get_base1(weights, k, "weights", 1), stan::model::rvalue(forecasts, stan::model::cons_list(stan::model::index_uni(1), stan::model::cons_list(stan::model::index_omni(), stan::model::cons_list(stan::model::index_uni(k), stan::model::nil_index_list()))), "forecasts"))));
                current_statement_begin__ = 36;
                stan::math::assign(average_upper, add(average_upper, multiply(get_base1(weights, k, "weights", 1), stan::model::rvalue(forecasts, stan::model::cons_list(stan::model::index_uni(2), stan::model::cons_list(stan::model::index_omni(), stan::model::cons_list(stan::model::index_uni(k), stan::model::nil_index_list()))), "forecasts"))));
            }
            current_statement_begin__ = 39;
            for (int t = 1; t <= T; ++t) {
                current_statement_begin__ = 40;
                lp_accum__.add((-(get_base1(lambda, t, "lambda", 1)) * pointwise_interval_score(get_base1(y, t, "y", 1), get_base1(average_lower, t, "average_lower", 1), get_base1(average_upper, t, "average_upper", 1), alpha, pstream__)));
            }
            current_statement_begin__ = 45;
            lp_accum__.add(dirichlet_log<propto__>(weights, rep_vector(dirichlet_alpha, K)));
            }
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
        lp_accum__.add(lp__);
        return lp_accum__.sum();
    } // log_prob()
    template <bool propto, bool jacobian, typename T_>
    T_ log_prob(Eigen::Matrix<T_,Eigen::Dynamic,1>& params_r,
               std::ostream* pstream = 0) const {
      std::vector<T_> vec_params_r;
      vec_params_r.reserve(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        vec_params_r.push_back(params_r(i));
      std::vector<int> vec_params_i;
      return log_prob<propto,jacobian,T_>(vec_params_r, vec_params_i, pstream);
    }
    void get_param_names(std::vector<std::string>& names__) const {
        names__.resize(0);
        names__.push_back("weights");
    }
    void get_dims(std::vector<std::vector<size_t> >& dimss__) const {
        dimss__.resize(0);
        std::vector<size_t> dims__;
        dims__.resize(0);
        dims__.push_back(K);
        dimss__.push_back(dims__);
    }
    template <typename RNG>
    void write_array(RNG& base_rng__,
                     std::vector<double>& params_r__,
                     std::vector<int>& params_i__,
                     std::vector<double>& vars__,
                     bool include_tparams__ = true,
                     bool include_gqs__ = true,
                     std::ostream* pstream__ = 0) const {
        typedef double local_scalar_t__;
        vars__.resize(0);
        stan::io::reader<local_scalar_t__> in__(params_r__, params_i__);
        static const char* function__ = "model_model_average_quantiles_namespace::write_array";
        (void) function__;  // dummy to suppress unused var warning
        // read-transform, write parameters
        Eigen::Matrix<double, Eigen::Dynamic, 1> weights = in__.simplex_constrain(K);
        size_t weights_j_1_max__ = K;
        for (size_t j_1__ = 0; j_1__ < weights_j_1_max__; ++j_1__) {
            vars__.push_back(weights(j_1__));
        }
        double lp__ = 0.0;
        (void) lp__;  // dummy to suppress unused var warning
        stan::math::accumulator<double> lp_accum__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning
        if (!include_tparams__ && !include_gqs__) return;
        try {
            if (!include_gqs__ && !include_tparams__) return;
            if (!include_gqs__) return;
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }
    template <typename RNG>
    void write_array(RNG& base_rng,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& vars,
                     bool include_tparams = true,
                     bool include_gqs = true,
                     std::ostream* pstream = 0) const {
      std::vector<double> params_r_vec(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r_vec[i] = params_r(i);
      std::vector<double> vars_vec;
      std::vector<int> params_i_vec;
      write_array(base_rng, params_r_vec, params_i_vec, vars_vec, include_tparams, include_gqs, pstream);
      vars.resize(vars_vec.size());
      for (int i = 0; i < vars.size(); ++i)
        vars(i) = vars_vec[i];
    }
    static std::string model_name() {
        return "model_model_average_quantiles";
    }
    void constrained_param_names(std::vector<std::string>& param_names__,
                                 bool include_tparams__ = true,
                                 bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        size_t weights_j_1_max__ = K;
        for (size_t j_1__ = 0; j_1__ < weights_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "weights" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        if (!include_gqs__ && !include_tparams__) return;
        if (include_tparams__) {
        }
        if (!include_gqs__) return;
    }
    void unconstrained_param_names(std::vector<std::string>& param_names__,
                                   bool include_tparams__ = true,
                                   bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        size_t weights_j_1_max__ = (K - 1);
        for (size_t j_1__ = 0; j_1__ < weights_j_1_max__; ++j_1__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "weights" << '.' << j_1__ + 1;
            param_names__.push_back(param_name_stream__.str());
        }
        if (!include_gqs__ && !include_tparams__) return;
        if (include_tparams__) {
        }
        if (!include_gqs__) return;
    }
}; // model
}  // namespace
typedef model_model_average_quantiles_namespace::model_model_average_quantiles stan_model;
#endif
