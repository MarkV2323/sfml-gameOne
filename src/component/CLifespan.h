#pragma once

namespace game {
    class CLifespan {
    public:
        int remaining {0};
        int total {0};
        CLifespan() {};
        CLifespan(int total) : remaining(total), total(total) {};
        ~CLifespan() {};
    };
}