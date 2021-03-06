#ifndef INTEGRATOR_H
#define INTEGRATOR_H

//TODO: Add way to add constants to integration term and template the class

#include <vector>
#include "IO.h"
#include "Sensor.h"

class Integrator: public IO{
private:
  float value;
  float y;
  float constant;
  vector<Sensor*> vec;
  vector<Sensor*>::iterator iter;
  Timer dt;
  bool _coup;

public:
//Constructor
Integrator(std::string name = "default"):IO(name){
  this->lock();
  this->value = 0.0;
  this->_coup = 1;
  this->constant = 1.0;
  this->unlock();
};

// Methods
void sensor_add(Sensor* obj){
  this->lock();
  this->vec.push_back(obj);
  this->unlock();
};

void set_const(float constant){
  this->lock();
  this->constant = constant;
  this->unlock();
};

float read(bool update=1){
  if (update){
    this->update();
  }
  return this->value;
};

void set(float value){
  this->lock();
  this->value = value;
  this->unlock();
};

void update(){
  this->lock();
  this->dt.stop();
  float del = this->dt.read();
  this->dt.reset();
  this->dt.start();
  this->y=1.0;

  for (iter = vec.begin(); iter != vec.end(); iter++){
    this->y = this->y * (*(*iter)).read();
  }
  this->y *= this->constant;

  this->value = this->value + (this->y * del);
  this->unlock();
};

void start(){
  this->lock();
  this->dt.start();
  this->unlock();
};

void couple(bool couple=1){
  this->lock();
  this->_coup = couple;
  this->unlock();
};

string toString(){
  stringstream ss;
  ss << this->get_name();
  ss << ":";
  ss << fixed << setprecision(2) << this->read();
  return ss.str();
};

string toStringInfo(){
  stringstream ss;
  ss << fixed << setprecision(2) << this->read();
  return ss.str();

};

string toStringHeader(){
  return this->get_name();
};

string toJsonObject(){
  return "Not Implemented";
};
};


#endif
