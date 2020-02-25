#include <Helpers/Sphere_Sphere.h>
#include <Args-Math.h>

Args::Collision Args::Sphere_Sphere::CollisionDetect(Collider _collider1, Transform _transform1, Collider _collider2, Transform _transform2)
{
	Vector3 origin1 = _transform1.translation;
	Vector3 origin2 = _transform2.translation;

	float distance = sqrt(pow2(origin2.x - origin1.x) + pow2(origin2.y - origin1.y));

	Args::Collision* collision = new Args::Collision();
	if(distance < _collider1.size.x+_collider2.size.x)
	{
		collision = new Args::Collision();
		collision->other = &_collider2;
		return *collision;
	}
	return *collision;
}
