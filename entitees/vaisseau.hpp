#pragma once

class Vaisseau {
    
    public:
        Vaisseau(int x, int y);
        ~Vaisseau();
        virtual void afficher();
        void bouger(int x, int y);

    protected:
        int x_;
        int y_;
};

