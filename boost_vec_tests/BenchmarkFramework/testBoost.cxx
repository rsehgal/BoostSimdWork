#include<iostream>
//#include <backend.h>
#include <Implementation.h>
using namespace vecgeom;
int main(int argc, char *argv[]){

TestCondAssign4<kBs>();
//BsBool cond;
//BsPrecision t1,t2,res;
//res = cond ? t1 : t2;
//res = if_else(cond,t1,t2);
std::cout<<"----------------------------"<<std::endl;
std::cout<<"Test passed...."<<std::endl;
return 0;

}
