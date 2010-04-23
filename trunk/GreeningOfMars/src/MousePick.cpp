#include "MousePick.h"

void MousePick::Pick(int p_mouseX, int p_mouseY)
{
	double x, y, z;

	double modelViewMatrix[16];
	double projectionMatrix[16];
	int viewport[4];

	glGetDoublev(GL_MODELVIEW_MATRIX, modelViewMatrix);
	glGetDoublev(GL_PROJECTION_MATRIX, projectionMatrix);
	glGetIntegerv(GL_VIEWPORT, viewport);

	gluUnProject(p_mouseX, p_mouseY, 0.0f,
		modelViewMatrix, projectionMatrix, viewport,
		&x, &y, &z);
	Vector3f mouseRay = Vector3f((float)x, (float)y, (float)z);
	gluUnProject(p_mouseX, p_mouseY, 1.0f,
		modelViewMatrix, projectionMatrix, viewport,
		&x, &y, &z);
	mouseRay = Vector3f((float)x, (float)y, (float)z) - mouseRay;
}