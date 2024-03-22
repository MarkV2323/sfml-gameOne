#pragma once

namespace game {
    class CInput {
    public:
        bool up {false};
        bool left {false};
        bool right {false};
        bool down {false};
        bool shoot {false};
        CInput() {};
        ~CInput() {};
    };
}