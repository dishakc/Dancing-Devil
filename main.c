#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#include <GL/glut.h>

#ifndef __MAC__
#define __MAC__ 1
#endif

#ifdef __MAC__
# include <GLUT/glut.h>
#else
# include <GL/glut.h>
#endif

static GLfloat theta[]={0.0,0.0,0.0};
float zoom=1;
static GLint axis=2;
double m=0;


void display()
{
    double i,a=0;
    GLfloat mat_ambient[]={.7f,0.7f,0.7f,1.0f};
    GLfloat mat_diffuse[]={1.5f,1.5f,1.5f,2.0f};
    GLfloat mat_specular[]={1.0f,1.0f,1.0f,1.0f};
    GLfloat mat_shininess[]={100.0f};
    
    glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
    glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
    glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
    glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
    
    GLfloat lightIntensity[]={1.0f,0.0f,0.0f,3.0f};
    GLfloat lightIntensity1[]={1.0f,1.0f,0.0f,3.0f};
    GLfloat lightIntensity2[]={0.0f,0.0f,0.0f,3.0f};
    GLfloat lightIntensity3[]={1.0f,1.0f,1.0f,3.0f};
    GLfloat lightIntensity4[]={0.0f,0.0f,0.0f,3.0f};
    
    GLfloat light_position[]={1.55f,1.5f,-1.5f,0.0f};
    GLfloat light_position1[]={7.5f,3.5f,-5.5f,1.0f};
    
    glLightfv(GL_LIGHT0,GL_POSITION,light_position);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,lightIntensity3);
    
    
    glClearColor(1.0,1.0,1.0,1.0);
    
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    
    glLoadIdentity();
    glRotatef(theta[0],1.0,0.0,0.0);
    glRotatef(theta[1],0.0,0.0,0.0);
    glRotatef(theta[2],0.0,1.0,0.0);
    glColor3f(0.0,1.0,0.0);
    glScalef(zoom,zoom,zoom);
    
    /*to create the head*/
    
    glutSolidSphere(0.6,100,10);
    
    /*to create the body*/
    glTranslated(0.0,-0.8,0.0);
    glutSolidSphere(0.5,100,10);
    
    /*to create the hands*/
    glLightfv(GL_LIGHT0,GL_DIFFUSE,lightIntensity2);
    glTranslated(0.63,0.0,0.0);
    glutSolidSphere(0.2,100,10);
    
    glTranslated(-1.27,0.0,0.0);
    glutSolidSphere(0.2,100,10);
    
    /*to create the eyes*/
    glLightfv(GL_LIGHT0,GL_DIFFUSE,lightIntensity2);
    
    glTranslated(.49,0.8,0.45);
    glutSolidSphere(.2,100,10);
    
    
    
    glTranslated(0.31,0.0,-0.01);
    glutSolidSphere(.2,100,10);
    
    /*to create the horns*/
    
    glLightfv(GL_LIGHT0,GL_DIFFUSE,lightIntensity);
    
    glTranslated(0.1,0.3,-0.3);
    glRotated(120,0.0,1.0,1.0);
    glutSolidCone(0.3,0.9,5.0,100.0);
    
    
    glTranslated(0.3,0.3,-0.3);
    glRotated(120,0.0,1.0,1.0);
    glutSolidCone(0.3,0.9,5.0,100.0);
    
    /*to create the stick*/
    
    glLightfv(GL_LIGHT0,GL_SPECULAR,lightIntensity);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,lightIntensity4);
    glLightfv(GL_LIGHT0,GL_SPECULAR,lightIntensity3);
    
    
    glTranslatef(-0.7,-1.6,-1.3);
    glTranslatef(1,1.2,1.5);
    glTranslatef(0,0,0);
    glRotatef(110,0,0,1);
    glRotatef(60,1,0,0);
    glRotatef(50,0,1,0);
    glRotatef(70,0,0,1);
    glRotatef(10,0,1,0);
    glRotatef(350,1,0,0);
    glRotatef(-30,0,1,0);
    
    /*upper portion of the stick*/
    
    for(i=0;i<17;i++)
    {
        glColor3f(1.0,0.0,0.0);
        glutSolidCube(.1);
        glTranslated(-0.1,0,0);
        
    }
    
    /*lower portion of the stick*/
    
    for(i=0;i<30;i++)
    {
        glColor3f(1.0,0.0,0.0);
        glutSolidCube(.1);
        //glutSolidSphere(.3,10,10);
        glTranslated(0.1,0,0);
        glRotatef(25,1,0,0);
        
        
    }
    
    
    /*to create the sphere on the top of stick*/
    
    for(a=0;a<46;a=a+1)
    {
        glLightfv(GL_LIGHT0,GL_DIFFUSE,lightIntensity4);
        
        
        glTranslatef(0,0,0);
        glRotatef(10,1,0,0);
        glutSolidSphere(.3,10,10);
        
    }
    
    /*to create the sharp spikes for the spinning doll  weapon*/
    
    for(a=0;a<46;a=a+1)
    {
        glLightfv(GL_LIGHT0,GL_DIFFUSE,lightIntensity);
        
        glTranslatef(0,0,0);
        glRotatef(10,1,0,0);
        glutSolidCone(0.02,1.5,10,10);
        if(m>2)
        {
            m=0;
            
        }
        else
            
            glutSolidCone(0.02,.1+m,10,10);
        
        m+=0.08;
        
        
    }
    
    /*to create a cube inside the sphere for the spinning doll  weapon*/
    
    for(a=0;a<46;a=a+1)
    {
        glLightfv(GL_LIGHT0,GL_DIFFUSE,lightIntensity);
        
        glRotatef(10,1,0,0);
        glutSolidCube(.42);
        glRotatef(20,1,0,0);
        
    }
    
    /* creating the leg of the spinning doll*/
    
    glTranslatef(-2.7,0.5,0);
    glRotatef(5,0,0,1);
    for(i=0;i<2;i++)
    {
        glLightfv(GL_LIGHT0,GL_DIFFUSE,lightIntensity2);
        glutSolidCube(.3);
        glTranslatef(0,0,0);
        
        
    }
    glTranslatef(0,.38,0);
    //glutSolidCube(.3);
    
    
    
    /*creating the plate on which the spinning doll  stands*/
    
    glLightfv(GL_LIGHT0,GL_DIFFUSE,lightIntensity2);
    glLightfv(GL_LIGHT0,GL_POSITION,light_position1);
    
    
    glTranslatef(-.16,-0.15,0);
    glRotatef(90,0,1,0);
    glutSolidCone(0.8,0.0,100,100);
    
    /*creating the ring on spinning doll head*/
    
    glTranslated(0,-0.1,2.5);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,lightIntensity2);
    
    glutSolidTorus(0.02,0.4,10,100);
    
    /*creating the legs*/
    
    glLightfv(GL_LIGHT0,GL_DIFFUSE,lightIntensity2);
    
    
    glTranslated(0.1,-.15,-2.4);
    glRotated(10,0,1,0);
    glutSolidTorus(.1,.18,10,5);
    
    glTranslated(0,0.4,0);
    glRotatef(-8,0,1,0);
    glutSolidTorus(.1,.17,10,5);
    
    /*making of the spinning doll  tail*/
    
    glTranslated(-1.5,-1.1,0.2);
    for(i=0;i<3.9;i=i+0.1)
    {
        
        glutSolidCube(0.05);
        glTranslated(0.05,0,0);
        glRotatef(10,1,1,0);
        
    }
    
    
    glTranslated(-1.02,-0.9,-0.03);
    glRotated(230,0,1,0);
    glutSolidCone(0.1,.2,10,10);
    glutSolidCone(0.1,0,10,10);
    
    
    
    glFlush();
    glutSwapBuffers();
    
}

void spin()
{
    theta[axis]+=1.0;
    if(theta[axis]>360.0) theta[axis]-=360.0;
    if(axis==1)
    {
        theta[axis]=0;
    }
    display();
}
void antispin()
{
    theta[axis]+=-1.0;
    if(theta[axis]>360.0) theta[axis]-=360.0;
    if(axis==1)
    {
        theta[axis]=0;
    }
    display();
}

void keyboard(unsigned char key,int x,int y)
{
    switch(key)
    {
        case 'z':
            zoom /= .9;
            glutPostRedisplay();
            break;
        case 'Z':
            zoom *= .9;
            glutPostRedisplay();
            break;
        case 27:             /* ESC */
            exit(0);
            break;
        case 'A':
            glutIdleFunc(antispin);
            break;
        case 'a':
            glutIdleFunc(antispin);
            break;
        case 's':
            glutIdleFunc(display);
            break;
        case 'S':
            glutIdleFunc(display);
            break;
        case 'D':
            glutIdleFunc(spin);
            break;
        case 'd':
            glutIdleFunc(spin);
            break;
    }
}

void mouse(int btn,int state,int x,int y)
{
    if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN) axis=0;
    if(btn==GLUT_MIDDLE_BUTTON && state==GLUT_DOWN) axis=1;
    if(btn==GLUT_RIGHT_BUTTON && state==GLUT_DOWN) axis=2;
}

void myReshape(int w,int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(w<=h)
        glOrtho(-2.0,2.0,-2.0 * (GLfloat) h/ (GLfloat) w,2.0 * (GLfloat) h/ (GLfloat) w, -10.0,10.0);
    else
        glOrtho(-2.0 * (GLfloat) w / (GLfloat) h,2.0 * (GLfloat) w / (GLfloat) h,-2.0,2.0,-10.0,10.0);
    glMatrixMode(GL_MODELVIEW);
}

void main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("DEVIL");
    glutReshapeFunc(myReshape);
    glutDisplayFunc(display);
    //glutIdleFunc(display);
    glutIdleFunc(spin);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    glViewport(0,0,500,500);
    
    glutMainLoop();
}

