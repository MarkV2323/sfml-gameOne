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

            void init() {
                entities.clear();
                entityMap.clear();
                toAddEntities.clear();
            }

        public:
            EntityManager() {
                this->init();
            }

            ~EntityManager() {}

            void update() {
                // Add
                // - simply push new shared-ptr onto entities
                // - use e.tag to get map vector, then pushback
                for(auto& e : toAddEntities) {
                    entities.push_back(e);
                    entityMap[e.get()->getTag()].push_back(e);
                }
                toAddEntities.clear();
                
                // Remove
                // See https://en.wikipedia.org/wiki/Erase%E2%80%93remove_idiom#Example
                // and https://stackoverflow.com/questions/7627098/what-is-a-lambda-expression-and-when-should-i-use-one
                entities.erase(std::remove_if(entities.begin(), entities.end(),
                [](std::shared_ptr<Entity> entity) {
                    return !entity.get()->isActive();
                }), entities.end());

                for(auto& em: entityMap) {
                    em.second.erase(std::remove_if(em.second.begin(), em.second.end(),
                    [](std::shared_ptr<Entity> entity) {
                        return !entity.get()->isActive();
                    }), em.second.end());
                }
            }

            std::shared_ptr<Entity> addEntity() {
                // Have to use a special case of make_shared, should be exception safe.
                // Has to do with our private Entity constructor, and 
                // not being able to use std::make_shared.

                // toAddEntities.push_back(std::shared_ptr<Entity>(new Entity(tag, m_totalEntities++, length, width)));
                toAddEntities.push_back(std::shared_ptr<Entity>(new Entity()));
                return toAddEntities.back();
            }

            std::shared_ptr<Entity> addEntity(std::string eTag) {
                toAddEntities.push_back(std::shared_ptr<Entity>(new Entity(eTag)));
                return toAddEntities.back();
            }

            const std::vector<std::shared_ptr<Entity>>& getEntities() {
                return entities;
            }

            const std::vector<std::shared_ptr<Entity>>& getEntities(std::string& s) {
                return entityMap[s];
            }

            std::string getEntitiesStats() {
                std::string r_string = "";
                r_string += "Entity Manager Report:\n";
                r_string += "Entities total : " + std::to_string(entities.size()) + "\n";
                r_string += "Entities to add: " + std::to_string(toAddEntities.size());
                return r_string;
            }
    };
}