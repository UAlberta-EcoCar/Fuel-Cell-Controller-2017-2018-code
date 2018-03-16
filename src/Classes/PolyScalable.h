#ifndef POLYSCALABLE_H
#define POLYSCALABLE_H

#include "Scalable.h"
#include <vector>

template <class T>
class PolyScalable: public Scalable<T>{
private:
  vector<T> param_vec;
  typename vector<T>::iterator param_iter;

public:
  // Constructor's
  PolyScalable(){};

  PolyScalable(T a){
    this->param_vec.push_back(a);
    this->param_vec.push_back(0.0);
  };

  PolyScalable(T a, T b){
    this->param_vec.push_back(a);
    this->param_vec.push_back(b);
  };

  PolyScalable(T a, T b, T c){
    this->param_vec.push_back(a);
    this->param_vec.push_back(b);
    this->param_vec.push_back(c);
  };

  PolyScalable(T a, T b, T c, T d){
    this->param_vec.push_back(a);
    this->param_vec.push_back(b);
    this->param_vec.push_back(c);
    this->param_vec.push_back(d);
  };

  PolyScalable(T a, T b, T c, T d, T e){
    this->param_vec.push_back(a);
    this->param_vec.push_back(b);
    this->param_vec.push_back(c);
    this->param_vec.push_back(d);
    this->param_vec.push_back(e);
  };

  PolyScalable(T a, T b, T c, T d, T e, T f){
    this->param_vec.push_back(a);
    this->param_vec.push_back(b);
    this->param_vec.push_back(c);
    this->param_vec.push_back(d);
    this->param_vec.push_back(e);
    this->param_vec.push_back(f);
  };

  PolyScalable(vector<T> params){
    this->param_vec = params;
  };

  T scale(T value){
    T scaled = 0;
    int count = 0;
    for(param_iter = param_vec.begin(); param_iter < param_vec.end(); param_iter++){
      if ((*param_iter) != 0){
        scaled += (*param_iter)*pow(value, count);
        count++;
      }
    }

    return scaled;
  };

  void set_params(vector<T> params){
    this->param_vec = params;
  };
};

#endif