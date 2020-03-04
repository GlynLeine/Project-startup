//DIFFUSE TEXTURE VERTEX SHADER
#version 450 // for glsl version (12 is for older versions , say opengl 2.1
#define near 0.001
#define far 1000.0

in mat4 modelMatrix;
uniform	mat4 viewProjectionMatrix;

in vec3 vertex;
in vec3 normal;
in vec2 uv;
in vec3 tangent;

out vec2 texCoord; //make sure the texture coord is interpolated
out vec3 surfacePosition;
out vec3 surfaceNormal;
out mat3 tbnMatrix;
//out float flogz;

void main( void )
{
    gl_Position = viewProjectionMatrix * modelMatrix * vec4(vertex, 1.0);
	// float Fcoef = 2.0 / log2(far + 1.0);
	// gl_Position.z = log2(max(1e-6, 1.0 + gl_Position.w)) * Fcoef - 1.0;
    // flogz = 1.0 + gl_Position.w;

	texCoord = uv;
	surfacePosition = (modelMatrix * vec4(vertex, 1.0)).xyz;
	surfaceNormal = normalize((modelMatrix * vec4(normal, 0.0)).xyz);
	vec3 worldTangent = normalize((modelMatrix * vec4(tangent,   0.0)).xyz);

	worldTangent = normalize(worldTangent - dot(worldTangent, surfaceNormal) * surfaceNormal);
	vec3 worldBitangent = normalize(cross(surfaceNormal, worldTangent));
	tbnMatrix = mat3(worldTangent, worldBitangent, surfaceNormal);
}
