#include <gl/glut.h> 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define XFORM_NONE    0 
#define XFORM_ROTATE  1
#define XFORM_SCALE	2 

struct tm *newtime;
time_t ltime;
float x_angle = 0.0, y_angle = 0.0, scale_size = 1;
int xform_mode = 0, ani = 0, timer = 75, release_x, release_y, press_x, press_y;

void initLighting() {
	GLfloat lightColor0[] = { 0.6f, 0.6f, 0.6f, 1.0f };
	GLfloat lightPos0[] = { -0.5f, 0.8f, 1.0f, 0.0f };
	GLfloat ambientColor[] = { 0.4f, 0.4f, 0.4f, 1.0f };

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glShadeModel(GL_SMOOTH);

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);

}
//Tower
void Tower()
{
	// TOP
	glPushMatrix();
	glRotatef(45, 0, 1, 0);
	glTranslatef(0, 22.7, 0);
	glScalef(4.5, 4, 4.5);
	glColor3f(0.82, 0, 0.05);
	glutSolidOctahedron();
	glPopMatrix();

	//Tower
	glPushMatrix();
	glTranslatef(0, 11, 0);
	glScalef(5, 25, 5);
	glColor3f(0.65, 0.32, 0.05);
	glutSolidCube(1.0);
	glPopMatrix();

	//Cuts
	glPushMatrix();
	glColor3f(0.27, 0.13, 0);
	glTranslatef(0, 15, 0);
	glScaled(5.5, 0.5, 5.5);
	glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
	glColor3f(0.27, 0.13, 0);
	glTranslatef(0, 20, 0);
	glScaled(5.5, 0.5, 5.5);
	glutSolidCube(1);
	glPopMatrix();
	//Door
	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(-0., 1.0, 2.5);
	glScalef(20, 24, 0.1);
	glutSolidCube(0.1);
	glPopMatrix();
	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(-0., 1.8, 2.5);
	glScalef(10.1, 24, 0.01);
	glutSolidSphere(0.1, 222, 22);
	glPopMatrix();
}
//Stairs
void Stairs() {
	glPushMatrix();
		glColor3f(0.5, 0.5, 0.5);
	glPushMatrix();
		glTranslatef(0, -0.4, 0);
		glScaled(10, 0.5, 10);
		glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0, -0.9, 0);
		glScaled(15, 0.5, 15);
		glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0, -1.3, 0);
		glScaled(20, 0.5, 20);
		glutSolidCube(1);
	glPopMatrix();
	glPopMatrix();
}
//Land
void Land() {

	glPushMatrix();
	glTranslatef(0, -1.5, 0);
	glScalef(500, 0.1, 500);
	glColor3f(0, 0.56, 0);
	glutSolidCube(1.0);
	glPopMatrix();
}
//Clock
void Clock()
{
	glPushMatrix();
	glScaled(0.2, 0.2, 0.2);
	glTranslatef(0, 88, 13.55);
	glRotatef(180, 1.0, 0.0, 0.0);

	//Clock Frame
	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(0.0, 0.0, 0.0);
	glScaled(1, 1, 0.01);
	glutSolidTorus(0.5, 7.5, 22, 55);
	glPopMatrix();

	//Clock Background
	glPushMatrix();
	glTranslatef(0, 0, 1.0);
	glColor3f(1.0, 1.0, 1.0);
	glScaled(7, 7, 0.01);
	glutSolidSphere(1, 22, 22);
	glPopMatrix();

	glPushMatrix();// Draw hour hand
	glColor3f(1.0, 0.5, 0.5);
	glRotatef((360 / 12) * newtime->tm_hour + (360 / 60) * (60 / (newtime->tm_min + 1)), 0.0, 0.0, 1.0);
	glScaled(0.6, 4, 0.2);
	glTranslated(0, -0.45, 0);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();// Draw minute hand
	glColor3f(1.0, 0.5, 1.0);
	glRotatef((360 / 60) * newtime->tm_min, 0.0, 0.0, 1.0);
	glScaled(0.4, 5, 0.2);
	glTranslated(0, -0.45, 0);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();// Draw second hand
	glColor3f(1.0, 0.0, 0.5);
	glRotatef((360 / 60) *newtime->tm_sec, 0.0, 0.0, 1.0);
	glScaled(6, 0.2, 0.2);
	glTranslated(-0.45, 0, 0);
	glutSolidCube(1);
	glPopMatrix();


	for (int hour_ticks = 0; hour_ticks < 12; hour_ticks++)
	{
		glPushMatrix();// Draw next arm axis.
		glColor3f(0.0, 0, 0); // give it a color
		glTranslatef(0.0, 0.0, 0.0);
		glRotatef((360 / 12) * hour_ticks, 0.0, 0.0, 1.0);
		glTranslatef(6.0, 0.0, 0.0);
		glutSolidCube(1.0);

		glPopMatrix();
	}
	for (int sec_ticks = 0; sec_ticks < 60; sec_ticks++)
	{
		glPushMatrix();
		glTranslatef(0.0, 0.0, 0.0);
		glRotatef((360 / 60) * sec_ticks, 0.0, 0.0, 1.0);
		glTranslatef(6.0, 0.0, 0.0);
		glutSolidCube(0.25);
		glPopMatrix();
	}


	glPopMatrix();

}



void display()
{
	time(&ltime); // Get time
	newtime = localtime(&ltime); // Convert to local time
	glClearColor(0.4, 0.61, 0.97, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1, 1, 900);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 15.0, 32.0, 0.0, 10.0, 0.0, 0.0, 30.0, 0.0);
	glRotatef(x_angle, 0, 1, 0);
	glRotatef(y_angle, 1, 0, 0);
	glScalef(scale_size, scale_size, scale_size);

	Tower();
	Clock();
	Stairs();
	Land();
	glutSwapBuffers();
}


void mymouse(int button, int state, int x, int y)
{
	if (state == GLUT_DOWN) {
		press_x = x; press_y = y;
		if (button == GLUT_LEFT_BUTTON)
			xform_mode = XFORM_ROTATE;
		else if (button == GLUT_RIGHT_BUTTON)
			xform_mode = XFORM_SCALE;
	}
	else if (state == GLUT_UP) {
		xform_mode = XFORM_NONE;
	}
}

void myidle(int val) {
	int angle = 1;
	if (ani == 0) glutTimerFunc(timer, myidle, 0);

	angle = (angle + 10) % 360;
	glutPostRedisplay();

}

void mymotion(int x, int y)
{
	if (xform_mode == XFORM_ROTATE) {
		x_angle += (x - press_x) / 10.0;
		if (x_angle > 180) x_angle -= 360;
		else if (x_angle < -180) x_angle += 360;
		press_x = x;

		y_angle += (y - press_y) / 10.0;
		if (y_angle > 180) y_angle -= 360;
		else if (y_angle < -180) y_angle += 360;
		press_y = y;
	}
	else if (xform_mode == XFORM_SCALE) {
		float old_size = scale_size;
		scale_size *= (1 + (y - press_y) / 600.0);
		if (scale_size < 0) scale_size = old_size;
		press_y = y;
	}
	glutPostRedisplay();
}

void mykey(unsigned char key, int x, int y)
{
	if (key == '-') {
		scale_size--;
	}
	if (key == '+') {
		scale_size++;
	}
	if (key == 'd') {
		x_angle--;
	}
	if (key == 'a') {
		x_angle++;
	}
	if (key == 's') {
		y_angle--;
	}
	if (key == 'w') {
		y_angle++;
	}
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Clock Tower");
	glutDisplayFunc(display);
	glutMouseFunc(mymouse);
	glutMotionFunc(mymotion);
	initLighting();
	glutKeyboardFunc(mykey);
	glutTimerFunc(timer, myidle, 0);
	glutMainLoop();
}


