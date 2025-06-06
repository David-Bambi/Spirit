#ifndef GID_HPP
#define GID_HPP

#include <cstdint>
#include <string>
#include <queue>
#include <tsl/robin_map.h>

using GID_t = std::uint32_t;

/**
 * Class GID
 * @brief Sequential graphic object identifier. It allow to recycle identifier. If a name is 
 * associate to the number it will cache it. 
 */
class UGID 
{
    public : 
        /** @brief Get new number. */
        static GID_t Get();

        /** @brief Get id from name. */
        static GID_t Get(std::string name);

        /** @brief Free an id. This id will be recycle. */
        static void Free(GID_t id);

        /** @brief Free an id from a name. This id will be recycle. */
        static void Free(std::string name);

        /** @brief Clear the identifier recycle queue, names map and the set the next id to 0.*/
        static void Clear();

    private :
        static GID_t NextId;
        static std::queue<GID_t> RecycleId;
        static tsl::robin_map <std::string, GID_t> Names;
};


#endif