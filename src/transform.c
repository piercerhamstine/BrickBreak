#include "include/transform.h"

Transform initTransform()
{
    Transform t;
    glm_vec3_zero(t.position);
    glm_vec3_zero(t.rotation);
    glm_vec3_one(t.scale);

    return t;
};

void setPosition(Transform* targetTransform, vec3 targetPos)
{
    glm_vec3_copy(targetPos, targetTransform->position);
};

void translate(Transform* targetTransform, vec3 targetPos)
{
    glm_vec3_add(targetTransform->position, targetPos, targetTransform->position);
};

void scale(Transform* targetTransform, vec3 targetScale)
{
    glm_vec3_add(targetTransform->scale, targetScale, targetTransform->scale);
}