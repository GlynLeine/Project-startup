#pragma once

#include <vector>
#include <glad/glad.h>
#include <Args-Core.h>
#include <unordered_map>

class World;

namespace Args
{
	class Mesh
	{
		friend class Renderer;
	public:
		/**
		 * Loads a mesh from an .obj file. The file has to have:
		 * vertexes, uvs, normals and face indexes. See load source
		 * for more format information.
		 */
		static Mesh* Load(std::string pFilename);

		void Bind(GLint pVerticesAttrib, GLint pNormalsAttrib = -1, GLint pUVsAttrib = -1, GLint pTangentsAttrib = -1) const;
		void Draw(unsigned count) const;
		static void Unbind(GLint pVerticesAttrib, GLint pNormalsAttrib = -1, GLint pUVsAttrib = -1, GLint pTangentsAttrib = -1);

		/**
		 * Draws debug info (normals) for the mesh using the given matrices)
		 */
		void DrawDebugInfo(const Matrix4& pModelMatrix, const Matrix4& pViewMatrix, const Matrix4& pProjectionMatrix);

		static std::unordered_map<std::string, Mesh*> meshes;
	protected:
		Mesh();
		virtual ~Mesh();

		//OpenGL id's for the different buffers created for this mesh
		GLuint _indexBufferId;
		GLuint _vertexBufferId;
		GLuint _normalBufferId;
		GLuint _uvBufferId;
		GLuint _tangentBufferId;

		//the actual data
		std::vector<Vector3> _vertices;       //vec3 with 3d coords for all vertices
		std::vector<Vector3> _normals;        //vec3 with 3d normal data
		std::vector<Vector2> _uvs;            //vec2 for uv
		std::vector<Vector3> _tangents;

		//references to the vertices/normals & uvs in previous vectors
		std::vector<unsigned> _indices;

		//buffer vertices, normals, and uv's
		virtual void _buffer();

		virtual void _calculateTangents();

		//Please read the "load" function documentation on the .obj file format first.
		//FaceVertexTriplet  is a helper class for loading and converting to obj file to
		//indexed arrays.
		//If we list all the unique v/uv/vn triplets under the faces
		//section in an object file sequentially and assign them a number
		//it would be a map of FaceVertexTriplet. Each FaceVertexTriplet refers
		//to an index with the originally loaded vertex list, normal list and uv list
		//and is only used during conversion (unpacking) of the facevertextriplet list
		//to a format that OpenGL can handle.
		//So for a vertex index a FaceVertexTriplet contains the index for uv and n as well.
		class FaceIndexTriplet {
		public:
			unsigned v; //vertex
			unsigned uv;//uv
			unsigned n; //normal
			FaceIndexTriplet(unsigned pV, unsigned pUV, unsigned pN)
				: v(pV), uv(pUV), n(pN) {
			}
			//needed for use as key in map
			bool operator<(const FaceIndexTriplet other) const {
				return memcmp((void*)this, (void*)&other, sizeof(FaceIndexTriplet)) > 0;
			}
		};

	};
}