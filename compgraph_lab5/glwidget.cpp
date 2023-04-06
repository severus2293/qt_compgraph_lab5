#include "glwidget.h"
#include <QTextStream>
#include <QMouseEvent>
#include <cmath>
#include <QLabel>
GLWidget::GLWidget(QWidget * parent):QGLWidget(parent) // инициализируем базовые параметры
{
   img = QImage(":./assets/an.jpg");
   radius = 0.1f;
    theta = 0.0f;
    this->type = GL_POINTS;
connect(&timer,SIGNAL(timeout()),this,SLOT(updateGL()));
timer.start(100);
}


void GLWidget::clear() //очистить холст
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    this->paintGL();
}

GLWidget::~GLWidget()
{
    delete texture;
}

void GLWidget::initializeGL() //задать базовый цвет для холста
{

    //img.load(":./assets/fish.jpg");
    glClearColor(0.2,0.2,0.2,1);
    shd_prog.addShaderFromSourceFile(QOpenGLShader::Vertex, ":./shaders/lbv.vert");
    shd_prog.addShaderFromSourceFile(QOpenGLShader::Fragment, ":./shaders/lbf.frag");
    shd_prog.link();
    shd_prog.bind();
    m_vertexAttr = shd_prog.attributeLocation( "vertexAttr" );
    m_textureAttr = shd_prog.attributeLocation( "textureAttr" );
    m_matrixUniform = shd_prog.uniformLocation( "matrix" );
    m_textureUniform = shd_prog.uniformLocation( "textureUniform" );
    m_radiusUniform = shd_prog.uniformLocation( "radius" ); //
    m_blurSizeUniform = shd_prog.uniformLocation( "blurSize" );
    texture = new QOpenGLTexture( img );
    //texture->setData()

}












void GLWidget::mousePressEvent(QMouseEvent * event) //событие нажатия на холст для отрисовки точки
{

        // границы окна OpenGL
        double x0 = -1.3;
        double y0 =  1.0;
        double x1 =  1.3;
        double y1 = -1.0;

        // переводим координаты окна в координаты окна OpenGL
        double xAtPress = double(event->x()) / this->geometry().size().width() * (x1 - x0) + x0;
        double yAtPress = double(event->y()) / this->geometry().size().height() * (y1 - y0) + y0;
        QTextStream out(stdout);

    out << xAtPress << endl;
    out << yAtPress  << endl;

}


void GLWidget::paintGL()
{
    shd_prog.bind();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // очистка буфера
    glClear(GL_COLOR_BUFFER_BIT);
    texture->bind();
    shd_prog.setAttributeArray(m_vertexAttr, m_vertices.data(), 3 );
    shd_prog.setAttributeArray( m_textureAttr, m_textures.data(), 2 );
    shd_prog.setUniformValue( m_textureUniform, 0 );
    shd_prog.setUniformValue( m_radiusUniform,radius);
    shd_prog.enableAttributeArray( m_vertexAttr );
    shd_prog.enableAttributeArray( m_textureAttr );

    glDrawArrays( GL_QUADS, 0, m_vertices.size() / 3);

    shd_prog.disableAttributeArray( m_vertexAttr );
    shd_prog.disableAttributeArray( m_textureAttr );
    shd_prog.release();




}

void GLWidget::resizeGL(int w, int h)
{
   glViewport(0,0,w,h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   updateGL();
}
