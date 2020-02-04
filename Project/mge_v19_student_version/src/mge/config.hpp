#pragma once

#include <string>
namespace config {
    const std::string MGE_MODEL_PATH ("mge/models/");
    const std::string MGE_TEXTURE_PATH ("mge/textures/");
    const std::string MGE_SHADER_PATH ("mge/shaders/");
    const std::string MGE_FONT_PATH ("mge/fonts/");
	const unsigned MAX_LIGHT_COUNT = 100;
	const bool VSYNC_ENABLED = false;
	const bool CURSOR_ENABLED = false;
	const size_t MAX_VBO_SIZE = 1048576; // 1MB
}
