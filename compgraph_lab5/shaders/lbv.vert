attribute highp vec4 vertexAttr;
attribute highp vec2 textureAttr;
varying highp vec2 textureCoord;

void main()
{
    gl_Position = vertexAttr; //задать координаты примитива
    textureCoord = textureAttr; //задать координаты текстуры
}

