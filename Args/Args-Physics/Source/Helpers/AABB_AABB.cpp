#include <Helpers/AABB_AABB.h>

Args::Collision Args::AABB_AABB::CollisionDetect(Collider _collider1, Transform _transform1, Collider _collider2, Transform _transform2)
{
	Vec3 origin1 = _transform1.translation;
	Vec3 origin2 = _transform2.translation;

	bool xRadius = origin1.x + _collider1.size.x * 0.5f >= origin2.x - _collider1.size.x * 0.5f &&
		origin1.x - _collider1.size.x*0.5f <= origin2.x + _collider1.size.x * 0.5f ? true : false;

	bool yRadius = origin1.y + _collider1.size.y * 0.5f >= origin2.y - _collider1.size.y * 0.5f &&
		origin1.y - _collider1.size.y * 0.5f <= origin2.y + _collider1.size.y * 0.5f ? true : false;

	bool zRadius = origin1.z + _collider1.size.z * 0.5f >= origin2.z - _collider1.size.z * 0.5f &&
		origin1.z - _collider1.size.z * 0.5f <= origin2.z + _collider1.size.z * 0.5f ? true : false;

	Args::Collision* collision = new Args::Collision();
	if(xRadius && yRadius && zRadius)
	{
		collision = new Args::Collision();
		collision->other = &_collider2;
		return *collision;
	}
	return *collision;
}
