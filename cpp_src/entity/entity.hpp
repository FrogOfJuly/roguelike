//
// Created by Kirill Golubev on 17.04.2021.
//

#include "../common.h"
#include "components.h"

#ifndef ROGUE_LIKE_ENTITY_HPP
#define ROGUE_LIKE_ENTITY_HPP
namespace roguelike {

    struct interaction_info {
        // actor is who interacting
        // subject is the one who is interacted
        bool actor_killed = false;
        bool subject_killed = false;
        bool subject_picked = false;
        std::optional<int> should_drop;
    };

    struct entity {
        entity() = delete;
        explicit entity(int id) : id{id} {}

        entity_id id{-1};
        int level = -1;
    };

    template <typename interacted, typename interacting>
    struct interacter {  // C++ does not permit partial function template specialization
      public:
        static inline void interact(interacted &inted, interacting &inting) {}
    };
}  // namespace roguelike

#endif  // ROGUE_LIKE_ENTITY_HPP
