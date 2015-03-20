#include<iostream>
#include <backend.h>
#include <typeinfo>

namespace vecgeom {

template<class Backend>
void TestCondAssign(){
typedef typename Backend::bool_v      Bool_t;
typedef typename Backend::precision_v      Float_t;

 Bool_t cond;
 Float_t t1,t2,res;
 CondAssign(cond,t1,t2,&res);
}

template<class Backend>
void TestCondAssign2(){
typedef typename Backend::bool_v      Bool_t;
typedef typename Backend::precision_v      Float_t;
 Bool_t cond;
 Float_t t1,t2,res;
//res = cond ? t1 : t2;
//res = if_else(cond,t1,t2);
CondAssign(cond,t1,t2,&res);
}

template<class Backend>
void TestCondAssign3(){
typedef boost::simd::pack<Precision>       precision_v;
typedef boost::simd::pack<bool> bool_v;

bool_v cond(false);
precision_v t1(1.0),t2(2.),res(0.),mask(0.);

std::cout<< typeid(t1).name() <<std::endl;

//res = if_else(cond,t1,t2);
mask = if_one_else_zero(t1 > t2);
std::cout<< mask <<std::endl;
res = if_else(mask, t1, t2);
std::cout<<res<<std::endl;
}

template<class Backend>
void TestCondAssign4(){
//typedef typename Backend::precision_v   precision_v;
//std::cout<< typeid(precision_v).name() << std::endl;
typedef boost::simd::pack<Precision>       precision_v;
precision_v t1(1.0),t2(2.),res(0.),mask(0.);
std::cout<< typeid(t1).name() <<std::endl;
mask = if_one_else_zero(t1 > t2);

CondAssign( mask,t1,t2,res);
std::cout<<"Res from 4 : "<<res<<std::endl;

}

}// end of global namespace
