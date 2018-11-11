interface IState {
    public:
        virtual ~IState() {}
        virtual void Update() = 0;
}