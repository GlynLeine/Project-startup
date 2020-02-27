#include <Helpers/AABB_Sphere.h>

Args::Collision* Args::AABB_Sphere::CollisionDetect(Collider* _collider1, Transform* _transform1, Collider* _collider2, Transform* _transform2)
{
	Vector3 origin1 = _transform1->position;
	Vector3 origin2 = _transform2->position;

	// Vector from A to B
	Vector3 lengthBetweenObjects = origin2 - origin1;

	// Closest point on A to center of B
	Vector3 closest = lengthBetweenObjects;

	// Calculate half extents along each axis
	float x_extent = ((origin1.x - _collider1->size.x*0.5f) - (origin1.x + _collider1->size.x * 0.5f)) * 0.5f;
	float y_extent = ((origin1.y - _collider1->size.y * 0.5f) - (origin1.y + _collider1->size.y * 0.5f)) * 0.5f;

	// Clamp point to edges of the AABB
	closest.x = Args::clamp(-x_extent, x_extent, closest.x);
	closest.y = Args::clamp(-y_extent, y_extent, closest.y);

	Vector3 lengthClosestToSphere = origin2 - closest;
	Args::Collision collision;
	if(lengthClosestToSphere.length() <= _collider2->size.x)
	{
		collision.other = _collider2;
		return &collision;
	}
	return &collision;
}
