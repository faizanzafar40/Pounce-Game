#include <iostream>
#include "soil.h"
#include "glut.h"
int main() {
	GLuint BitmapLoader::Load(std::string path) {
		glEnable(GL_TEXTURE_2D);

		GLuint texture_id;
		glGenTextures(1, &texture_id);

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture_id);

		image = SOIL_load_image(path.c_str(), &width, &height, 0, SOIL_LOAD_RGBA);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);

		std::cout << "Width: " << width << ", Height: " << height << std::endl;
		std::cout << "Image ID: " << texture_id << std::endl;
		std::cout << "Image Data: " << image << std::endl;

		SOIL_free_image_data(image);

		if (texture_id == -1) {
			return -1;
		}

		return texture_id;
	}
}