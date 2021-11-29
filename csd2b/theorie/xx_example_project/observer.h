#ifndef OBSERVER_H
#define OBSERVER_H

class Subject;

class Observer {
public:
  virtual ~Observer(){}
  virtual void update(Subject* theChangedSubject) = 0;
  //prevent the default constructor to be generated
  Observer() = delete;
};

#endif
