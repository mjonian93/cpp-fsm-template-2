#ifndef FINITE_STATE_MACHINE_H
#define FINITE_STATE_MACHINE_H

#include <memory>
#include "state.h"

template <typename T>
  class FiniteStateMachine
  {
  // A Finite State Machine
  // - An FSM consists of a set of states,
  // - and at any given time, an FSM can exist in only one 
  //   State out of these possible set of states.
  // A map to represent the a set of states.
  protected:
    std::map<T, std::unique_ptr<State<T>>> mStates;
    // The current state.
    State<T>* mCurrentState;
  public:
    FiniteStateMachine()
      : mCurrentState(nullptr)
    {
    }
    template <class S>
    State<T>& add(T id)
    {
      static_assert(not std::is_same<State<T>, S>());
      mStates[id] = std::make_unique<S>(*this);
      return *mStates[id];
    }
    State<T>& getState(T stateID)
    {
      return *mStates[stateID];
    }
    State<T>& getCurrentState()
    {
      return *mCurrentState;
    }
    const State<T>& getCurrentState() const
    {
      return *mCurrentState;
    }
    
    void setCurrentState(T stateID)
    {
      State<T>* state = &getState(stateID);
      setCurrentState(state);
    }
    void update()
    {
      if (mCurrentState != nullptr)
      {
        mCurrentState->update();
      }
    }
  protected:
    void setCurrentState(State<T>* state)
    {
      if (mCurrentState == state)
      {
        return;
      }
      if (mCurrentState != nullptr)
      {
        mCurrentState->exit();
      }
      mCurrentState = state;
      if (mCurrentState != nullptr)
      {
        mCurrentState->enter();
      }
    }
  };

  #endif