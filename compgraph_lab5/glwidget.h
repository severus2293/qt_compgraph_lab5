#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>
#include <QTimer>
#include <QGLWidget>
#include <vector>
#include <QOpenGLShaderProgram>
#include <QTime>
#include <QOpenGLTexture>
using namespace std;
class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    QOpenGLTexture * texture;
    QImage img;
   // QImage GL_formatted_image;
    int m_vertexAttr;
    int m_textureAttr;
    int m_matrixUniform;
    int m_textureUniform;
    int m_radiusUniform;
    float radius;
    int m_blurSizeUniform;
    vector <float> m_vertices = {-1.0,-1.0,0.0,-1.0,1.0,0.0,1.0,1.0,0.0,1.0,-1.0,0.0};
    vector <float> m_textures = {1.0,1.0,1.0,0.0,0.0,0.0,0.0,1.0,};
    unsigned int type; // тип примитива
    explicit GLWidget(QWidget* parent = 0);
    ~GLWidget();
    double N(int q,int k,double u);
    void clear(); //очистка холста
    void initializeGL() override;
    void paintGL() override; // отрисовка примитивов
    void resizeGL(int w, int h) override;
private:
    QOpenGLShaderProgram shd_prog;
    QTimer timer;
    QTime time;
    HDC hDC;
    float theta;
protected:
    void mousePressEvent(QMouseEvent * event) override; // эвент нажатия мыши по холсту
};

#endif // GLWIDGET_H
