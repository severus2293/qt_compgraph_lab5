varying highp vec2 textureCoord;
uniform sampler2D textureUniform;
varying vec4 v_color;
uniform float radius; //радиус размытия
float blurSize = 1.0f/1024.0f;
float pii = 3.14159265;
float numBlurPixelsPerSide = 10.0; //количество пикселей для обхода
vec2 blurMultiplyVec = vec2(1.0, 0.0);
void main()
{

vec3 incrementalGaussian;
incrementalGaussian.x = 1.0 / (sqrt(2.0 * pii) * radius); //x составляющяя функции гаусса
incrementalGaussian.y = exp(-0.5 / (radius * radius));  // y составляющаяя функции гаусса
incrementalGaussian.z = incrementalGaussian.y * incrementalGaussian.y; //z составляющаяя функции гаусса
vec4 avgValue = vec4(0.0, 0.0, 0.0, 0.0); //итоговый результат
float coefficientSum = 0.0;
avgValue += texture2D(textureUniform, textureCoord.xy) * incrementalGaussian.x; //домножаем на функцию гаусса
coefficientSum += incrementalGaussian.x;
incrementalGaussian.xy *= incrementalGaussian.yz;
for (float i = 1.0; i <= numBlurPixelsPerSide; i++)
{
avgValue += texture2D(textureUniform, textureCoord.xy - i * blurSize * blurMultiplyVec) * incrementalGaussian.x;
avgValue += texture2D(textureUniform, textureCoord.xy + i * blurSize * blurMultiplyVec) * incrementalGaussian.x; //рассчитываем
                                                                                           //среднее значение исходя из соседних весов
coefficientSum += 2.0 * incrementalGaussian.x;
incrementalGaussian.xy *= incrementalGaussian.yz;
}
gl_FragColor = avgValue / coefficientSum;
}


























