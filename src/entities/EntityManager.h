#pragma once

#include <vector>
#include <map>
#include <memory>

#include "Entity.h"

namespace game {
    class EntityManager {
        private:
            std::vector<std::shared_ptr<Entity>> entities;
            std::map<std::string, std::vector<std::shared_ptr<Entity>>> entityMap;
            std::vector<std::shared_ptr<Entity>> toAddEntities;

            void init() {}
        public:
            EntityManager() {}
            ~EntityManager() {}

            void update() {}

            std::shared_ptr<Entity> addEntity() {}

            const std::vector<std::shared_ptr<Entity>>& getEntities() {}

            const std::vector<std::shared_ptr<Entity>>& getEntities(std::string& s) {}
    };
}