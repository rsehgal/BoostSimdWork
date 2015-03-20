#include <cassert>
#include <cmath>
#include <float.h>
#include <limits>
#include <stdio.h>

#include <boost/simd/sdk/simd/pack.hpp>
#include <boost/simd/include/functions/splat.hpp>
#include <boost/simd/include/functions/plus.hpp>
#include <boost/simd/include/functions/multiplies.hpp>
#include <boost/simd/include/functions/is_equal.hpp>
#include <boost/simd/include/functions/abs.hpp>
#include <boost/simd/operator/functions/logical_and.hpp>
#include <boost/simd/include/functions/if_else.hpp>
#include <boost/simd/include/functions/if_else_zero.hpp>
#include <boost/simd/include/functions/if_zero_else_one.hpp>
#include <boost/simd/include/functions/if_one_else_zero.hpp>
#include <boost/simd/include/functions/is_greater.hpp>
#include <boost/simd/include/functions/is_less.hpp>
#include  <boost/simd/memory/functions/load.hpp>
#include <boost/simd/memory/functions/aligned_load.hpp>
#include <boost/simd/memory/prefetch.hpp>
#include <boost/simd/memory/functions/store.hpp>
//#include <boost/simd/arithmetic/functions/sqrt.hpp>
#include <boost/simd/include/functions/sqrt.hpp>
#include <boost/simd/operator/functions/minus.hpp>

typedef double Precision;

namespace vecgeom {

struct kBs {
  typedef boost::simd::pack<int>                   int_v;
  typedef boost::simd::pack<Precision>       precision_v;
  typedef boost::simd::pack<bool> bool_v;
  typedef boost::simd::pack<int>              inside_v;
  constexpr static bool early_returns = false;
  const static precision_v kOne;
  const static precision_v kZero;
  const static bool_v kTrue;
  const static bool_v kFalse;
};

constexpr int kVectorSize = sizeof(kBs::precision_v)/sizeof(Precision);

typedef kBs::int_v       BsInt;
typedef kBs::precision_v BsPrecision;
typedef kBs::bool_v      BsBool;
typedef kBs::inside_v    BsInside;

//template <typename Type>
//VECGEOM_INLINE
inline
void CondAssign(//boost::simd::pack<bool> const &cond,
				boost::simd::pack<Precision> const &cond,
                boost::simd::pack<Precision> const &thenval,
                boost::simd::pack<Precision> const &elseval,
                boost::simd::pack<Precision> &output) {
  //(*output)(cond) = thenval;
  //(*output)(!cond) = elseval;
  //output = cond ? thenval : elseval;
  std::cout<<"....This Guy is Called ...."<<std::endl;
  //boost::simd::pack<Precision> mask = if_one_else_zero(cond);
  output = if_else(cond,thenval,elseval);
  //std::cout<<"Output : "<<output<<std::endl;
}
/*
template <typename Type>
//VECGEOM_INLINE
void CondAssign(boost::simd::pack<bool> const &cond,
                Type const &thenval,
                Type const &elseval,
                boost::simd::pack<Type> *const output) {
  //(*output)(cond) = thenval;
  //(*output)(!cond) = elseval;
  output = cond ? thenval : elseval;
}
*/
}// end of global namespace
