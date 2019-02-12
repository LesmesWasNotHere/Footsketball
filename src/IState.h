class IState {
    public:
        virtual ~IState() {};
        virtual void Update(unsigned milis) = 0;
};