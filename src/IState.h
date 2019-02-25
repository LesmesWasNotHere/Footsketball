#ifndef _ISTATE_H
#define _ISTATE_H

class IState {
    public:
        virtual ~IState() {};
        virtual void Update(unsigned milis) = 0;
};

#endif