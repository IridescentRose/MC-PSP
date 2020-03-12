#ifndef AABB_H_INCLUDED
#define AABB_H_INCLUDED

#include <glm/glm.hpp>

struct AABB {
    AABB(const glm::vec3 &dim)
        : dimensions(dim)
    {
    }

    inline void update(const glm::vec3 &location)
    {
        position = location;
    }

    inline glm::vec3 getVN(const glm::vec3 &normal) const
    {
        glm::vec3 res = position;

        if (normal.x < 0) {
            res.x += dimensions.x;
        }
        if (normal.y < 0) {
            res.y += dimensions.y;
        }
        if (normal.z < 0) {
            res.z += dimensions.z;
        }

        return res;
    }

    inline glm::vec3 getVP(const glm::vec3 &normal) const
    {
        glm::vec3 res = position;

        if (normal.x > 0) {
            res.x += dimensions.x;
        }
        if (normal.y > 0) {
            res.y += dimensions.y;
        }
        if (normal.z > 0) {
            res.z += dimensions.z;
        }

        return res;
    }

    inline bool isColliding(const glm::vec3 &v)
    {
		return (v.x > position.x&& v.x < (dimensions + position).x && v.y > position.y&& v.y < (dimensions + position).y && v.z > position.z&& v.z < (dimensions + position).z);
    }

    inline bool isColliding(const AABB &aabb)
    {
		return isColliding(aabb.position) && isColliding(aabb.position + dimensions);
    }

    glm::vec3 position;
    const glm::vec3 dimensions;
};

#endif // AABB_H_INCLUDED
