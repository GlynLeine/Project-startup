#include <Helpers/AABB_AABB.h>

Args::Collision* Args::AABB_AABB::CollisionDetect(Collider* _collider1, Transform* _transform1, Collider* _collider2, Transform* _transform2)
{
	Vec3 origin1 = _transform1->position;
	Vec3 origin2 = _transform2->position;

	// Vector from A to B
	Vector3 lengthBetweenObjects = origin2 - origin1;

	bool xRadius = origin1.x + _collider1->size.x * 0.5f >= origin2.x - _collider1->size.x * 0.5f &&
		origin1.x - _collider1->size.x*0.5f <= origin2.x + _collider1->size.x * 0.5f ? true : false;

	bool yRadius = origin1.y + _collider1->size.y * 0.5f >= origin2.y - _collider1->size.y * 0.5f &&
		origin1.y - _collider1->size.y * 0.5f <= origin2.y + _collider1->size.y * 0.5f ? true : false;

	bool zRadius = origin1.z + _collider1->size.z * 0.5f >= origin2.z - _collider1->size.z * 0.5f &&
		origin1.z - _collider1->size.z * 0.5f <= origin2.z + _collider1->size.z * 0.5f ? true : false;

	/*float xDifference = _collider2->size.x - _collider1->size.x;
	float yDifference = _collider2->size.y - _collider1->size.y;
	float zDifference = _collider2->size.z - _collider1->size.z;
	
	float xTotalCollider = _collider1->size.x * 0.5f + _collider2->size.x * 0.5f;
	float yTotalCollider = _collider1->size.y * 0.5f + _collider2->size.y * 0.5f;
	float zTotalCollider = _collider1->size.z * 0.5f + _collider2->size.z * 0.5f;*/

	//normal calculation
	Vector3 normal;
	if (Args::abs(lengthBetweenObjects.x) > Args::abs(lengthBetweenObjects.y))
	{
		normal = Vector3(lengthBetweenObjects.x, 0, 0);
	}
	else
	{
		normal = Vector3(0, lengthBetweenObjects.y, 0);
	}

	if (Args::length(normal) < Args::abs(lengthBetweenObjects.z))
	{
		normal = Vector3(0, 0, lengthBetweenObjects.z);
	}
	normal = Args::normalize(normal);
	
	Args::Collision collision;
	if(xRadius && yRadius && zRadius)
	{
		Vector3 normal = origin1 - origin2;
		collision.normal = normal;
		collision.other = _collider2;
		return &collision;
	}
	return &collision;
}
