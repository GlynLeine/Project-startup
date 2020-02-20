#pragma once
#include<ECS/Component.h>
#include <array>
#include <Args-Math.h>
#include <Utils\Common.h>
#include <vector>


namespace Args
{
	struct Transform : public Component<Transform>
	{
		Transform(uint32 entityId) : Component<Transform>(entityId) 
		{

		}

		union
		{
			struct
			{
				Args::Mat4 Matrix;
			};

			struct
			{
				Vector3 rotationX;
				float wX;
				Vector3 rotationY;
				float wY;
				Vector3 rotationZ;
				float wZ;
				Vector3 translation;
				float one;
			};
		};

		Args::Vec3 scale;
		std::vector<Args::Transform*> children;

		Args::Vec3 forward;
		Args::Vec3 right;
		Args::Vec3 up;


		// Inherited via Component
        std::string ObjectType() override
        {
            return GetTypeName<Transform>();
        }

        bool SetData(const std::string& name, const std::string& value) override
        {
            if (name.find("Matrix") != std::string::npos)
            {
                size_t divider = 0;
                for (int i = 0; i < 4; i++)
                {
                    Matrix[i].x = std::stof(value.substr(divider), &divider);
                    Matrix[i].y = std::stof(value.substr(divider), &divider);
                    Matrix[i].z = std::stof(value.substr(divider), &divider);
                    Matrix[i].w = std::stof(value.substr(divider), &divider);
                }
                return true;
            }
            if (name.find("rotationX") != std::string::npos)
            {
                size_t divider;
                rotationX.x = std::stof(value, &divider);
                rotationX.y = std::stof(value.substr(divider), &divider);
                rotationX.z = std::stof(value.substr(divider), &divider);
                return true;
            }
            if (name.find("rotationY") != std::string::npos)
            {
                size_t divider;
                rotationY.x = std::stof(value, &divider);
                rotationY.y = std::stof(value.substr(divider), &divider);
                rotationY.z = std::stof(value.substr(divider));
                return true;
            }
            if (name.find("rotationZ") != std::string::npos)
            {
                size_t divider;
                rotationZ.x = std::stof(value, &divider);
                rotationZ.y = std::stof(value.substr(divider), &divider);
                rotationZ.z = std::stof(value.substr(divider));
                return true;
            }
            if (name.find("wX") != std::string::npos)
            {
                wX = std::stof(value);
                return true;
            }
            if (name.find("wY") != std::string::npos)
            {
                wY = std::stof(value);
                return true;
            }
            if (name.find("wZ") != std::string::npos)
            {
                wZ = std::stof(value);
                return true;
            }
            if (name.find("one") != std::string::npos)
            {
                one = std::stof(value);
                return true;
            }
            if (name.find("translation") != std::string::npos)
            {
                size_t divider;
                translation.x = std::stof(value, &divider);
                translation.y = std::stof(value.substr(divider));
                translation.z = std::stof(value.substr(divider));
                return true;
            }
            return false;
        }

        bool GetData(const std::string& name, std::string& value) override
        {
            //TODO
            /*if (name.find("name") != std::string::npos)
            {
                value = std::to_string();
                return true;
            }*/
            return false;
        }
	};
}