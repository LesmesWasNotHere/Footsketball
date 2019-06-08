#ifndef _ISTATE_H
#define _ISTATE_H

class IState {
    public:
        virtual ~IState() {};
        virtual bool Update(unsigned milis)=0;
        virtual void OnEnter() {};
        virtual void OnExit() {};
};

#endif