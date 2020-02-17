// PlantillaGraficos.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <stdio.h> 
#include <stdlib.h> 
#define GLEW_STATIC 
 
#include"GL/glew.h"
#include "GLFW/glfw3.h"

#include <iostream> 

using namespace std;

GLFWwindow* window;

float posXTriangulo = 0.0f, posYTriangulo = 0.0f;


float posXCuadrado = 0.15f, posYCuadrado = 0.15f;
float posXCuadrado2 = -0.15f, posYCuadrado2 = -0.15f;
float posXCuadrado3 = 0.15f, posYCuadrado3 = -0.15f;
float posXCuadrado4 = -0.15f, posYCuadrado4 = 0.15f;

float posXrec = 0.15f, posYrec = 0.3f;
float posXrec2 =-0.15f, posYrec2 = 0.3f;
float posXrec3 = 0.15f, posYrec3 = -0.3f;
float posXrec4 = -0.15f, posYrec4 = -0.3f;

float posXrec9 = 0.35f, posYrec9 = -0.3f;
float posXrec10 = -0.35f, posYrec10 = -0.3f;
float posXrec11 = -0.35f, posYrec11 = 0.3f;
float posXrec12 = 0.35f, posYrec12 = 0.3f;

float posXrec13 = -0.5f, posYrec13 = 0.5f;
float posXrec14 = 0.5f, posYrec14 = 0.1f;

float posXrec15 = -0.15f, posYrec15 = 0.5f;
float posXrec16 = -0.5f, posYrec16= 0.1f;

float posXrec17 = -0.5f, posYrec17 = 0.8f;
float posXrec18 = -0.15f, posYrec18 = 0.8f;

float posXrec19 = 0.1f, posYrec19 = 0.8f;
float posXrec20 = 0.4f, posYrec20 = 0.6f;

float posXrec21 = 0.6f, posYrec21 = 0.5f;
float posXrec22 = -0.1f, posYrec22 = -0.6f;

float posXrec23 = 0.75f, posYrec23 = 0.2f;
float posXrec24 = 0.2f, posYrec24 = -0.6f;

float posXrec25 = -0.5f, posYrec25 = -0.2f;
float posXrec26 = -0.5f, posYrec26 = -0.5f;

float posXrec27 = 0.75f, posYrec27 = -0.2f;

float posXrec28 = 0.75f, posYrec28 = -0.5f;
float posXrec29 = 0.5f, posYrec29 = -0.6f;

double tiempoActual, tiempoAnterior;

double velTriangulo = 0.5;
float angulo = 0.0f;
float componenteX;
float componenteY;
float velAngular = 92.0f;

void actualizar() {
	
	
	tiempoActual = glfwGetTime();
	double tiempoDiferencial = tiempoActual - tiempoAnterior;

	int estadoDerecha = glfwGetKey(window, GLFW_KEY_RIGHT);
	if (estadoDerecha == GLFW_PRESS) {
		
		angulo -= velAngular * tiempoDiferencial;		
	}
	int estadoArriba = glfwGetKey(window, GLFW_KEY_UP);
	if (estadoArriba == GLFW_PRESS) {
		//posYTriangulo += velTriangulo * tiempoDiferencial;

		componenteX = (cos((angulo + 90.0) * 3.141592 / 180.0)) * (velTriangulo * tiempoDiferencial);
		componenteY = (sin((angulo + 90.0) * 3.141592 / 180.0)) * (velTriangulo * tiempoDiferencial);

		posXTriangulo += componenteX;
		posYTriangulo += componenteY;

		if (posXTriangulo <= -1.00) {
			exit(1);
		}
		else if (posXTriangulo >= 1.00) {
			exit(1);
		}

		if (posYTriangulo <= -1.08) {
			exit(1);
		}
		else if (posYTriangulo >= 1.00) {
			exit(1);
		}
	}

	int estadoIzquierda = glfwGetKey(window, GLFW_KEY_LEFT);
	if (estadoIzquierda == GLFW_PRESS) {
		
		angulo += 90.00f * tiempoDiferencial;		
	}
	int estadoAbajo = glfwGetKey(window, GLFW_KEY_DOWN);
	if (estadoAbajo == GLFW_PRESS) {

		posYTriangulo -= velTriangulo * tiempoDiferencial;

		if (posXTriangulo <= -1.08) {
			exit(1);
		}
		else if (posXTriangulo >= 1.08) {
			exit(1);
		}

		if (posYTriangulo <= -1.08) {
			exit(1);
		}
		else if (posYTriangulo >= 1.08) {
			exit(1);
			
		}
	}
	tiempoAnterior = tiempoActual;

}


void dibujarTriangulo() {
	glPushMatrix();

	glTranslatef(posXTriangulo,posYTriangulo,0.0f);	
	glRotatef(angulo, 0.0f, 0.0f, 1.0);
	glScalef(0.3f, 0.3f, 0.0f);

	glBegin(GL_TRIANGLES);
    glColor3f(1.0f,1.0f,1.0f);

	glVertex3f(0.0f,0.15f,0.0f);
	glVertex3f(-0.15f, -0.15f, 0.0f); 
	glVertex3f(0.15f, -0.15f, 0.0f);

	glEnd();
	glPopMatrix();

}

void laberinto() {
	//CUADRADROS
	//Uno
	glPushMatrix();
	glTranslatef(posXCuadrado, posYCuadrado, 0.0f);
	glRotatef(0.0f, 0.0f, 0.0f, 1.0);
	glScalef(0.3f, 0.3f, 0.0f);

	glBegin(GL_QUADS);
	glColor3f(0.95f, 0.88f, 0.22f);

	glVertex3f(-0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, -0.15f, 0.0f);
	glVertex3f(-0.15f, -0.15f, 0.0f);
	glEnd();
	glPopMatrix();
	//Dos
	glPushMatrix();
	glTranslatef(posXCuadrado2, posYCuadrado2, 0.0f);
	glRotatef(0.0f, 0.0f, 0.0f, 1.0);
	glScalef(0.3f, 0.3f, 0.0f);

	glBegin(GL_QUADS);
	glColor3f(0.95f, 0.88f, 0.22f);

	glVertex3f(-0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, -0.15f, 0.0f);
	glVertex3f(-0.15f, -0.15f, 0.0f);
	glEnd();
	glPopMatrix();
	//Tres
	glPushMatrix();
	glTranslatef(posXCuadrado3, posYCuadrado3, 0.0f);
	glRotatef(0.0f, 0.0f, 0.0f, 1.0);
	glScalef(0.3f, 0.3f, 0.0f);

	glBegin(GL_QUADS);
	glColor3f(0.95f, 0.88f, 0.22f);

	glVertex3f(-0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, -0.15f, 0.0f);
	glVertex3f(-0.15f, -0.15f, 0.0f);
	glEnd();
	glPopMatrix();
	//Cuatro
	glPushMatrix();
	glTranslatef(posXCuadrado4, posYCuadrado4, 0.0f);
	glRotatef(0.0f, 0.0f, 0.0f, 1.0);
	glScalef(0.3f, 0.3f, 0.0f);

	glBegin(GL_QUADS);
	glColor3f(0.95f, 0.88f, 0.22f);

	glVertex3f(-0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, -0.15f, 0.0f);
	glVertex3f(-0.15f, -0.15f, 0.0f);
	glEnd();
	glPopMatrix();
	//RECTANGULOS 
	//Uno
	glPushMatrix();
	glTranslatef(posXrec, posYrec, 0.0f);
	glRotatef(0.0f, 0.0f, 0.0f, 1.0);
	glScalef(0.3f, 0.5f, 0.0f);

	glBegin(GL_QUADS);
	glColor3f(0.39f, 0.1f, 0.1f);

	glVertex3f(-0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, -0.15f, 0.0f);
	glVertex3f(-0.15f, -0.15f, 0.0f);
	glEnd();
	glPopMatrix();
	//Dos
	glPushMatrix();
	glTranslatef(posXrec2, posYrec2, 0.0f);
	glRotatef(0.0f, 0.0f, 0.0f, 1.0);
	glScalef(0.3f, 0.5f, 0.0f);

	glBegin(GL_QUADS);
	glColor3f(0.39f, 0.1f, 0.1f);

	glVertex3f(-0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, -0.15f, 0.0f);
	glVertex3f(-0.15f, -0.15f, 0.0f);
	glEnd();
	glPopMatrix();
	//Tres
	glPushMatrix();
	glTranslatef(posXrec3, posYrec3, 0.0f);
	glRotatef(0.0f, 0.0f, 0.0f, 1.0);
	glScalef(0.3f, 0.5f, 0.0f);

	glBegin(GL_QUADS);
	glColor3f(0.39f, 0.1f, 0.1f);

	glVertex3f(-0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, -0.15f, 0.0f);
	glVertex3f(-0.15f, -0.15f, 0.0f);
	glEnd();
	glPopMatrix();
	//Cuatro
	glPushMatrix();
	glTranslatef(posXrec4, posYrec4, 0.0f);
	glRotatef(0.0f, 0.0f, 0.0f, 1.0);
	glScalef(0.3f, 0.5f, 0.0f);

	glBegin(GL_QUADS);
	glColor3f(0.39f, 0.1f, 0.1f);

	glVertex3f(-0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, -0.15f, 0.0f);
	glVertex3f(-0.15f, -0.15f, 0.0f);
	glEnd();
	glPopMatrix();
	//Cinco
	glPushMatrix();
	glTranslatef(posXrec, posYrec, 0.0f);
	glRotatef(0.0f, 0.0f, 0.0f, 1.0);
	glScalef(0.5f, 0.3f, 0.0f);

	glBegin(GL_QUADS);
	glColor3f(0.39f, 0.1f, 0.1f);

	glVertex3f(-0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, -0.15f, 0.0f);
	glVertex3f(-0.15f, -0.15f, 0.0f);
	glEnd();
	glPopMatrix();
	//Seis
	glPushMatrix();
	glTranslatef(posXrec2, posYrec2, 0.0f);
	glRotatef(0.0f, 0.0f, 0.0f, 1.0);
	glScalef(0.8f, 0.3f, 0.0f);

	glBegin(GL_QUADS);
	glColor3f(0.39f, 0.1f, 0.1f);

	glVertex3f(-0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, -0.15f, 0.0f);
	glVertex3f(-0.15f, -0.15f, 0.0f);
	glEnd();
	glPopMatrix();
	//Siete
	glPushMatrix();
	glTranslatef(posXrec3, posYrec3, 0.0f);
	glRotatef(0.0f, 0.0f, 0.0f, 1.0);
	glScalef(0.8f, 0.3f, 0.0f);

	glBegin(GL_QUADS);
	glColor3f(0.39f, 0.1f, 0.1f);

	glVertex3f(-0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, -0.15f, 0.0f);
	glVertex3f(-0.15f, -0.15f, 0.0f);
	glEnd();
	glPopMatrix();
	//Ocho
	glPushMatrix();
	glTranslatef(posXrec4, posYrec4, 0.0f);
	glRotatef(0.0f, 0.0f, 0.0f, 1.0);
	glScalef(0.5f, 0.3f, 0.0f);

	glBegin(GL_QUADS);
	glColor3f(0.39f, 0.1f, 0.1f);

	glVertex3f(-0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, -0.15f, 0.0f);
	glVertex3f(-0.15f, -0.15f, 0.0f);
	glEnd();
	glPopMatrix();
	//Nueve
	glPushMatrix();
	glTranslatef(posXrec9, posYrec9, 0.0f);
	glRotatef(0.0f, 0.0f, 0.0f, 1.0);
	glScalef(0.5f, 0.3f, 0.0f);

	glBegin(GL_QUADS);
	glColor3f(0.39f, 0.1f, 0.1f);

	glVertex3f(-0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, -0.15f, 0.0f);
	glVertex3f(-0.15f, -0.15f, 0.0f);
	glEnd();
	glPopMatrix();
	//Diez
	glPushMatrix();
	glTranslatef(posXrec10, posYrec10, 0.0f);
	glRotatef(0.0f, 0.0f, 0.0f, 1.0);
	glScalef(0.5f, 0.3f, 0.0f);

	glBegin(GL_QUADS);
	glColor3f(0.39f, 0.1f, 0.1f);

	glVertex3f(-0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, -0.15f, 0.0f);
	glVertex3f(-0.15f, -0.15f, 0.0f);
	glEnd();
	glPopMatrix();

	//Once
	glPushMatrix();
	glTranslatef(posXrec11, posYrec11, 0.0f);
	glRotatef(0.0f, 0.0f, 0.0f, 1.0);
	glScalef(0.5f, 0.3f, 0.0f);

	glBegin(GL_QUADS);
	glColor3f(0.39f, 0.1f, 0.1f);

	glVertex3f(-0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, -0.15f, 0.0f);
	glVertex3f(-0.15f, -0.15f, 0.0f);
	glEnd();
	glPopMatrix();
	//Dose
	glPushMatrix();
	glTranslatef(posXrec12, posYrec12, 0.0f);
	glRotatef(0.0f, 0.0f, 0.0f, 1.0);
	glScalef(0.5f, 0.3f, 0.0f);

	glBegin(GL_QUADS);
	glColor3f(0.39f, 0.1f, 0.1f);

	glVertex3f(-0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, -0.15f, 0.0f);
	glVertex3f(-0.15f, -0.15f, 0.0f);
	glEnd();
	glPopMatrix();

	//13
	glPushMatrix();
	glTranslatef(posXrec13, posYrec13, 0.0f);
	glRotatef(0.0f, 0.0f, 0.0f, 1.0);
	glScalef(0.3f, 0.8f, 0.0f);

	glBegin(GL_QUADS);
	glColor3f(0.39f, 0.1f, 0.1f);

	glVertex3f(-0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, -0.15f, 0.0f);
	glVertex3f(-0.15f, -0.15f, 0.0f);
	glEnd();
	glPopMatrix();
	//14
	glPushMatrix();
	glTranslatef(posXrec14, posYrec14, 0.0f);
	glRotatef(0.0f, 0.0f, 0.0f, 1.0);
	glScalef(0.3f, 0.8f, 0.0f);

	glBegin(GL_QUADS);
	glColor3f(0.39f, 0.1f, 0.1f);

	glVertex3f(-0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, -0.15f, 0.0f);
	glVertex3f(-0.15f, -0.15f, 0.0f);
	glEnd();
	glPopMatrix();
	//15
	glPushMatrix();
	glTranslatef(posXrec15, posYrec15, 0.0f);
	glRotatef(0.0f, 0.0f, 0.0f, 1.0);
	glScalef(0.3f, 0.8f, 0.0f);

	glBegin(GL_QUADS);
	glColor3f(0.39f, 0.1f, 0.1f);

	glVertex3f(-0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, -0.15f, 0.0f);
	glVertex3f(-0.15f, -0.15f, 0.0f);
	glEnd();
	glPopMatrix();
	//16
	glPushMatrix();
	glTranslatef(posXrec16, posYrec16, 0.0f);
	glRotatef(0.0f, 0.0f, 0.0f, 1.0);
	glScalef(0.3f, 0.8f, 0.0f);

	glBegin(GL_QUADS);
	glColor3f(0.39f, 0.1f, 0.1f);

	glVertex3f(-0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, -0.15f, 0.0f);
	glVertex3f(-0.15f, -0.15f, 0.0f);
	glEnd();
	glPopMatrix();
	//17
	glPushMatrix();
	glTranslatef(posXrec17, posYrec17, 0.0f);
	glRotatef(0.0f, 0.0f, 0.0f, 1.0);
	glScalef(0.3f, 0.8f, 0.0f);

	glBegin(GL_QUADS);
	glColor3f(0.39f, 0.1f, 0.1f);

	glVertex3f(-0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, -0.15f, 0.0f);
	glVertex3f(-0.15f, -0.15f, 0.0f);
	glEnd();
	glPopMatrix();
	//18
	glPushMatrix();
	glTranslatef(posXrec18, posYrec18, 0.0f);
	glRotatef(0.0f, 0.0f, 0.0f, 1.0);
	glScalef(0.3f, 0.8f, 0.0f);

	glBegin(GL_QUADS);
	glColor3f(0.39f, 0.1f, 0.1f);

	glVertex3f(-0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, -0.15f, 0.0f);
	glVertex3f(-0.15f, -0.15f, 0.0f);
	glEnd();
	glPopMatrix();
	//19
	glPushMatrix();
	glTranslatef(posXrec19, posYrec19, 0.0f);
	glRotatef(0.0f, 0.0f, 0.0f, 1.0);
	glScalef(0.8f, 0.3f, 0.0f);

	glBegin(GL_QUADS);
	glColor3f(0.39f, 0.1f, 0.1f);

	glVertex3f(-0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, -0.15f, 0.0f);
	glVertex3f(-0.15f, -0.15f, 0.0f);
	glEnd();
	glPopMatrix();
	//20
	glPushMatrix();
	glTranslatef(posXrec20, posYrec20, 0.0f);
	glRotatef(0.0f, 0.0f, 0.0f, 1.0);
	glScalef(0.3f, 0.8f, 0.0f);

	glBegin(GL_QUADS);
	glColor3f(0.39f, 0.1f, 0.1f);

	glVertex3f(-0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, -0.15f, 0.0f);
	glVertex3f(-0.15f, -0.15f, 0.0f);
	glEnd();
	glPopMatrix();
	//21
	glPushMatrix();
	glTranslatef(posXrec21, posYrec21, 0.0f);
	glRotatef(0.0f, 0.0f, 0.0f, 1.0);
	glScalef(0.8f, 0.3f, 0.0f);

	glBegin(GL_QUADS);
	glColor3f(0.39f, 0.1f, 0.1f);

	glVertex3f(-0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, -0.15f, 0.0f);
	glVertex3f(-0.15f, -0.15f, 0.0f);
	glEnd();
	glPopMatrix();
	//22
	glPushMatrix();
	glTranslatef(posXrec22, posYrec22, 0.0f);
	glRotatef(0.0f, 0.0f, 0.0f, 1.0);
	glScalef(0.8f, 0.3f, 0.0f);

	glBegin(GL_QUADS);
	glColor3f(0.39f, 0.1f, 0.1f);

	glVertex3f(-0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, -0.15f, 0.0f);
	glVertex3f(-0.15f, -0.15f, 0.0f);
	glEnd();
	glPopMatrix();
	//23
	glPushMatrix();
	glTranslatef(posXrec23, posYrec23, 0.0f);
	glRotatef(0.0f, 0.0f, 0.0f, 1.0);
	glScalef(0.3f, 0.8f, 0.0f);

	glBegin(GL_QUADS);
	glColor3f(0.39f, 0.1f, 0.1f);

	glVertex3f(-0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, -0.15f, 0.0f);
	glVertex3f(-0.15f, -0.15f, 0.0f);
	glEnd();
	glPopMatrix();
	//24
	glPushMatrix();
	glTranslatef(posXrec24, posYrec24, 0.0f);
	glRotatef(0.0f, 0.0f, 0.0f, 1.0);
	glScalef(0.8f, 0.3f, 0.0f);

	glBegin(GL_QUADS);
	glColor3f(0.39f, 0.1f, 0.1f);

	glVertex3f(-0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, -0.15f, 0.0f);
	glVertex3f(-0.15f, -0.15f, 0.0f);
	glEnd();
	glPopMatrix();
	//25
	glPushMatrix();
	glTranslatef(posXrec25, posYrec25, 0.0f);
	glRotatef(0.0f, 0.0f, 0.0f, 1.0);
	glScalef(0.3f, 0.8f, 0.0f);

	glBegin(GL_QUADS);
	glColor3f(0.39f, 0.1f, 0.1f);

	glVertex3f(-0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, -0.15f, 0.0f);
	glVertex3f(-0.15f, -0.15f, 0.0f);
	glEnd();
	glPopMatrix();
	//26
	glPushMatrix();
	glTranslatef(posXrec26, posYrec26, 0.0f);
	glRotatef(0.0f, 0.0f, 0.0f, 1.0);
	glScalef(0.3f, 0.8f, 0.0f);

	glBegin(GL_QUADS);
	glColor3f(0.39f, 0.1f, 0.1f);

	glVertex3f(-0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, -0.15f, 0.0f);
	glVertex3f(-0.15f, -0.15f, 0.0f);
	glEnd();
	glPopMatrix();

	//Casi
		//27
	glPushMatrix();
	glTranslatef(posXrec27, posYrec27, 0.0f);
	glRotatef(0.0f, 0.0f, 0.0f, 1.0);
	glScalef(0.3f, 0.8f, 0.0f);

	glBegin(GL_QUADS);
	glColor3f(0.39f, 0.1f, 0.1f);

	glVertex3f(-0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, -0.15f, 0.0f);
	glVertex3f(-0.15f, -0.15f, 0.0f);
	glEnd();
	glPopMatrix();
	//28
	glPushMatrix();
	glTranslatef(posXrec28, posYrec28, 0.0f);
	glRotatef(0.0f, 0.0f, 0.0f, 1.0);
	glScalef(0.3f, 0.8f, 0.0f);

	glBegin(GL_QUADS);
	glColor3f(0.39f, 0.1f, 0.1f);

	glVertex3f(-0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, -0.15f, 0.0f);
	glVertex3f(-0.15f, -0.15f, 0.0f);
	glEnd();
	glPopMatrix();
	//29
	glPushMatrix();
	glTranslatef(posXrec29, posYrec29, 0.0f);
	glRotatef(0.0f, 0.0f, 0.0f, 1.0);
	glScalef(0.8f, 0.3f, 0.0f);

	glBegin(GL_QUADS);
	glColor3f(0.39f, 0.1f, 0.1f);

	glVertex3f(-0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, -0.15f, 0.0f);
	glVertex3f(-0.15f, -0.15f, 0.0f);
	glEnd();
	glPopMatrix();
}

void dibujar() {
	laberinto();
	dibujarTriangulo();
}

int main()
{
	//Declarar una ventana 
	


	//Si no se pudo inicializar GLFW  //Terminamos Ejecución 
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}
	window = glfwCreateWindow(600, 600, "Ventana Cookie", NULL, NULL);
	
	//Si no se pudo crear la ventana
	//Terminamos ejecución
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	//Si se pudo inicializar GLFW
	//Inicializams la ventana


	//Establecemos la ventana como contexto
	glfwMakeContextCurrent(window);
	//UsarFuncionesdeOpengl
	//Una vez establecido el contexto. Se activan las funciones "modernas" (gpu)
	glewExperimental = true;
	
	GLenum errores = glewInit();
	if (errores != GLEW_OK) {
		glewGetErrorString(errores);
	}

	const GLubyte  *versionGL = glGetString(GL_VERSION);

	cout << "Version OpenGl: " << versionGL;
	//Ventana y funcion
	//Establecemos que con cada evento del teclado se llama a la funcion teclado_callbak
	//glfwSetKeyCallback(window, teclado_callback);

	tiempoActual = glfwGetTime();
	tiempoAnterior = tiempoActual;

	//Clilo de dibujo (Draw loop)
	while (!glfwWindowShouldClose(window)) {

		//Establecer región de dibujo 
		glViewport(0, 0, 600, 650);
		//Establecemos el color de borrado
		glClearColor(0, 0, 0, 1);
		//Borrar
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		actualizar();
		dibujar();
		//Se comunica con los dispositivos de entrada
		glfwPollEvents();
		// Actualizar los valores y dibujar 
		glfwSwapBuffers(window);
	}
	//Despues del ciclo de dibujo Eliminamos ventana y procesos de glfw
	glfwDestroyWindow(window);
	glfwTerminate();
}