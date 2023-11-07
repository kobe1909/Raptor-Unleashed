#pragma once

#include <vector>
#include "../Renderer.h"

struct VertexBufferElement {
	unsigned int type;
	unsigned int count;
	unsigned int normalized;

	static unsigned int GetSizeOfType(unsigned int type) {
		switch (type) {
			case GL_FLOAT: return 4;
			case GL_UNSIGNED_INT: return 4;
			case GL_UNSIGNED_BYTE: return 1;
		}
		// Stop program running if type isn't in the list
		ASSERT(false);
		return 0;
	}
};

