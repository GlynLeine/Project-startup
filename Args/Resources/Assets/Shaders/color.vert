//DIFFUSE COLOR VERTEX SHADER
#version 330 // for glsl version (12 is for older versions , say opengl 2.1
#define near 0.001
#define far 1000.0

in mat4 modelMatrix;
uniform	mat4 viewProjectionMatrix;

in vec3 vertex;
in vec3 normal;
in vec2 uv;
in vec3 tangent;

void main( void ){
	gl_Position = viewProjectionMatrix * modelMatrix * vec4(vertex, 1.f);
	gl_Position.z = 2.0*log(gl_Position.w*near + 1.0)/log(far*near + 1.0) - 1.0;
	gl_Position.z *= gl_Position.w;
}
