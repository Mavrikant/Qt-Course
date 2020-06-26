#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
enum class DrawingOption{Lines,Colours,Patterns,Sinus,Transparent,Donut,
                         Shapes,Gradients,SimpleOps,RotatedText,Pixmap,RadialGradient};
class Widget : public QWidget
{
  Q_OBJECT
public:
  Widget(DrawingOption drawOption = DrawingOption::Lines, QWidget *parent = nullptr);
protected:
  void keyPressEvent(QKeyEvent *e) override;
  void paintEvent(QPaintEvent *e) override;
private:
  DrawingOption m_drawOption;
  void drawLines(QPainter *qp);
  void drawColours(QPainter *qp);
  void drawPatterns(QPainter *qp);
  void drawSinus(QPainter *qp);
  void drawTransparent(QPainter *qp);
  void drawDonut(QPainter *qp);
  void drawShapes(QPainter *qp);
  void drawGradients(QPainter *qp);
  void drawRadialGradient(QPainter *qp);
  void drawSimpleOperations(QPainter *qp);
  void drawRotatedText(QPainter *qp);
  void drawPixmap(QPainter *qp);
};

#endif // WIDGET_H
