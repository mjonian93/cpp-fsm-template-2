#ifndef STATE_H
#define STATE_H

#include <memory>
#include <map>
#include <string>
#include <cassert>

template <typename T>
class FiniteStateMachine;

template <typename T>
  class State
  {
  public:
    // The ID of the state.
    inline T getID()
    {
      return mID;
    }
    inline const std::string& getName() const
    {
      return mName;
    }
    explicit State(FiniteStateMachine<T>& fsm, T id,
      std::string name = "default")
      : mName(name)
      , mID(id)
      , mFsm(fsm)
    {
    }
    virtual ~State() {}
    virtual void enter()
    {
    }
    virtual void exit()
    {
    }
    virtual void update()
    {
    }
  protected:
    std::string mName;
    T mID;
    FiniteStateMachine<T>& mFsm;
  };

  #endif