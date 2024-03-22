#pragma once

#include <string>
#include <memory>

#include "component/CCollision.h"
#include "component/CInput.h"
#include "component/CLifespan.h"
#include "component/CScore.h"
#include "component/CTransform.h"

namespace game {
    class Entity
    {
    private:
        std::string tag {"null_tag"};
        bool active {true};
        size_t id {0};

    public:
        // Public components
        std::shared_ptr<CCollision> cCollision;
        std::shared_ptr<CInput> cInput;
        std::shared_ptr<CLifespan> cLifespan;
        std::shared_ptr<CScore> cScore;
        std::shared_ptr<CTransform> cTransform;

        Entity() {};
        ~Entity() {};

        void destroy() {
            active = false;
        }

        bool isActive() {
            return active;
        }

        const std::string& getTag() {
            return tag;
        }

        size_t getId() {
            return id;
        }

        std::string printEntityInfo() {
            std::string r_string = "";
            r_string += "ID:     " + std::to_string(id) + "\n";
            r_string += "TAG:    " + tag + "\n";
            r_string += "ACTIVE: " + std::to_string(active) + "\n";
            r_string += (cCollision) ? "cCollision: TRUE\n" : "cCollision: FALSE\n"; 
            r_string += (cInput)     ? "cInput:     TRUE\n" : "cInput:     FALSE\n";
            r_string += (cLifespan)  ? "cLifespan:  TRUE\n" : "cLifespan:  FALSE\n";
            r_string += (cScore)     ? "cScore:     TRUE\n" : "cScore:     FALSE\n";
            r_string += (cTransform) ? "cTransform: TRUE"   : "cTransform: FALSE";
            return r_string;
        }
    };
}