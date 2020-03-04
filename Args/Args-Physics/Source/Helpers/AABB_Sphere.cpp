#include <Helpers/AABB_Sphere.h>

Args::Collision Args::AABB_Sphere::CollisionDetect(Collider* boxCollider, Transform* boxTransform, Collider* sphereCollider, Transform* sphereTransform)
{
	Vector3 boxOrigin = boxTransform->WorldTransformPoint(boxCollider->origin);
	Vector3 sphereOrigin = sphereTransform->WorldTransformPoint(sphereCollider->origin);

	// Vector from A to B
	Vector3 lengthBetweenObjects = sphereOrigin - boxOrigin;

	// Closest point on A to center of B
	Vector3 closest = boxOrigin + lengthBetweenObjects * 1000.f;

	Vector3 boxScale = boxTransform->GetWorldScale();

	// Calculate half extents along each axis
	Vector3 maxExtents = boxOrigin + boxCollider->size * 0.5f * boxScale;
	Vector3 minExtents = boxOrigin - boxCollider->size * 0.5f * boxScale;

	// Clamp point to edges of the AABB
	closest = Args::clamp(closest, minExtents, maxExtents);

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

	
	Vector3 lengthClosestToSphere = sphereOrigin - closest;
	Args::Collision collision;
	
	Vector3 sphereScale = sphereTransform->GetWorldScale();

	if(length(lengthClosestToSphere) <= sphereCollider->size.x * sphereScale.x * 0.5f)
	{
		collision.normal = normal;
		collision.other = sphereCollider;
		collision.penetration = length((normalize(-lengthBetweenObjects) * sphereCollider->size.x * sphereScale.x + sphereOrigin) - closest);
		return collision;
	}
	collision.other = nullptr;
	return collision;
}
