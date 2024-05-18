#ifndef NUMERICAL_MATRIXIN_DATA_TYPE_CONSTANTS_H
#define NUMERICAL_MATRIXIN_DATA_TYPE_CONSTANTS_H

#include <cstdint>
#include <complex>
#include <boost/multiprecision/float128.hpp>  

using int8 = int8_t;
using uint8 = uint8_t;

using int16 = int16_t;
using uint16 = uint16_t;

using int32 = int32_t;
using uint32 = uint32_t;

using int64 = int64_t;
using uint64 = uint64_t;

using float32 = float;
using float64 = double;
using float128 = long double;

using complex32 = std::complex<float32>;
using complex64 = std::complex<float64>;
using complex128 = std::complex<boost::multiprecision::float128>;

#endif