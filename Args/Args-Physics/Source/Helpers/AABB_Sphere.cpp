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
	float z_extent = ((origin1.z - _collider1->size.z * 0.5f) - (origin1.z + _collider1->size.z * 0.5f)) * 0.5f;

	// Clamp point to edges of the AABB
	closest.x = Args::clamp(-x_extent, x_extent, closest.x);
	closest.y = Args::clamp(-y_extent, y_extent, closest.y);
	closest.z = Args::clamp(-z_extent, z_extent, closest.z);

	//normal calculation
	Vector3 normal;
	if(Args::abs(lengthBetweenObjects.x) > Args::abs(lengthBetweenObjects.y))
	{
		normal = Vector3(lengthBetweenObjects.x,0,0);
	}
	else
	{
		normal = Vector3(0, lengthBetweenObjects.y, 0);
	}

	if(Args::length(normal) < Args::abs(lengthBetweenObjects.z))
	{
		normal = Vector3(0, 0, lengthBetweenObjects.z);
	}
	normal = Args::normalize(normal);

	
	Vector3 lengthClosestToSphere = origin2 - closest;
	Args::Collision collision;
	
	if(lengthClosestToSphere.length() <= _collider2->size.x)
	{
		collision.normal = normal;
		collision.other = _collider2;
		return &collision;
	}
	return &collision;
}
