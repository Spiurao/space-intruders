#pragma once

class Vaisseau {
    
    public:
        Vaisseau(int x, int y);
        ~Vaisseau();
        void afficher();
        void bouger(int x, int y);

    private:
        int x_;
        int y_;
};

