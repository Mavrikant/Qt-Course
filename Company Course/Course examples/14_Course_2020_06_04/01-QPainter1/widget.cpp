#include "widget.h"
#include <QPainter>
#include <QPainterPath>
#include <QApplication>
#include <QKeyEvent>
#include <math.h>


Widget::Widget(DrawingOption drawOption, QWidget *parent): QWidget(parent)
{
    m_drawOption = drawOption;
}

void Widget::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Escape)
        qApp->exit();
}

void Widget::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);//I will not use parameter e, please dont give warning
    QPainter qp(this);

    switch (m_drawOption)
    {
    case DrawingOption::Colours:
        setWindowTitle(tr("Colours"));
        drawColours(&qp);
        break;
    case DrawingOption::Donut:
        setWindowTitle(tr("Donut"));
        drawDonut(&qp);
        break;
    case DrawingOption::Gradients:
        setWindowTitle(tr("Gradients"));
        drawGradients(&qp);
        break;
    case DrawingOption::Lines:
        setWindowTitle(tr("Lines"));
        drawLines(&qp);
        break;
    case  DrawingOption::Patterns:
        setWindowTitle(tr("Patterns"));
        drawPatterns(&qp);
        break;
    case  DrawingOption::RadialGradient:
        setWindowTitle(tr("RadialGradient"));
        drawRadialGradient(&qp);
        break;
    case DrawingOption::Shapes:
        setWindowTitle(tr("Shapes"));
        drawShapes(&qp);
        break;
    case DrawingOption::Sinus:
        setWindowTitle(tr("Sinus"));
        drawSinus(&qp);
        break;
    case DrawingOption::Transparent:
        setWindowTitle(tr("Transparent"));
        drawTransparent(&qp);
        break;
    case DrawingOption::SimpleOps:
        setWindowTitle(tr("Simple Operations"));
        drawSimpleOperations(&qp);
        break;
    case DrawingOption::RotatedText:
        setWindowTitle(tr("Rotated text"));
        drawRotatedText(&qp);
        break;
    case DrawingOption::Pixmap:
        setWindowTitle(tr("Draw Pixmap"));
        drawPixmap(&qp);
        break;
    default:
        break;
    }
}

void Widget::drawLines(QPainter *qp)
{
    QPen pen(Qt::black, 2, Qt::SolidLine);
    qp->setPen(pen);
    qp->drawLine(20, 40, 250, 40);

    pen.setStyle(Qt::DashLine);
    qp->setPen(pen);
    qp->drawLine(20, 80, 250, 80);

    pen.setStyle(Qt::DashDotLine);
    qp->setPen(pen);
    qp->drawLine(20, 120, 250, 120);

    pen.setStyle(Qt::DotLine);
    qp->setPen(pen);
    qp->drawLine(20, 160, 250, 160);

    pen.setStyle(Qt::DashDotDotLine);
    qp->setPen(pen);
    qp->drawLine(20, 200, 250, 200);

    QVector<qreal> dashes;
    qreal space = 4;

    dashes << 1 << space << 5 << space;//1,3,5 dashes, 2,4,6 spaces

    pen.setStyle(Qt::CustomDashLine);
    pen.setDashPattern(dashes);

    qp->setPen(pen);
    qp->drawLine(20, 240, 250, 240);
}

void Widget::drawColours(QPainter *qp)
{
    Q_UNUSED(qp);
    QPainter painter(this);
    painter.setPen(QColor("#d4d4d4"));

    painter.setBrush(QBrush("#c56c00"));
    painter.drawRect(10, 15, 90, 60);

    painter.setBrush(QBrush("#1ac500"));
    painter.drawRect(130, 15, 90, 60);

    painter.setBrush(QBrush("#539e47"));
    painter.drawRect(250, 15, 90, 60);

    painter.setBrush(QBrush("#004fc5"));
    painter.drawRect(10, 105, 90, 60);

    painter.setBrush(QBrush("#c50024"));
    painter.drawRect(130, 105, 90, 60);

    painter.setBrush(QBrush("#9e4757"));
    painter.drawRect(250, 105, 90, 60);

    painter.setBrush(QBrush("#5f3b00"));
    painter.drawRect(10, 195, 90, 60);

    painter.setBrush(QBrush("#4c4c4c"));
    painter.drawRect(130, 195, 90, 60);

    painter.setBrush(QBrush("#785f36"));
    painter.drawRect(250, 195, 90, 60);
}

void Widget::drawPatterns(QPainter *qp)
{
    Q_UNUSED(qp);
    QPainter painter(this);
    painter.setPen(Qt::NoPen);

    painter.setBrush(Qt::HorPattern);
    painter.drawRect(10, 15, 90, 60);

    painter.setBrush(Qt::VerPattern);
    painter.drawRect(130, 15, 90, 60);

    painter.setBrush(Qt::CrossPattern);
    painter.drawRect(250, 15, 90, 60);

    painter.setBrush(Qt::Dense7Pattern);
    painter.drawRect(10, 105, 90, 60);

    painter.setBrush(Qt::Dense6Pattern);
    painter.drawRect(130, 105, 90, 60);

    painter.setBrush(Qt::Dense5Pattern);
    painter.drawRect(250, 105, 90, 60);

    painter.setBrush(Qt::BDiagPattern);
    painter.drawRect(10, 195, 90, 60);

    painter.setBrush(Qt::FDiagPattern);
    painter.drawRect(130, 195, 90, 60);

    painter.setBrush(Qt::DiagCrossPattern);
    painter.drawRect(250, 195, 90, 60);
}

void Widget::drawSinus(QPainter *qp)
{
    QPen pen;
    pen.setColor(Qt::blue);
    pen.setWidth(3);
    qp->setPen(pen);

    double x, y;
    QVector<QPoint> points;
    int xOrg = width() / 2, yOrg = height() / 2, xUnit = 50, yUnit = 100;
    qp->translate(xOrg, yOrg); //orijin noktası olarak çalışma alanının ortası seçiliyor
    qp->scale(1, -1); //y koordinatının aşağıdan yukarı artması için
    qp->drawLine(0, - 200, 0,  + 200);
    qp->drawLine( - 350, 0,  + 350, 0);

    pen.setColor(Qt::red);
    qp->setPen(pen);
    for (x = -3.14 * 2; x < +3.14 * 2; x += 0.01)
    {
        y = sin(x);
        points.append(QPoint( x * xUnit, y * yUnit));
    }
    qp->drawPolyline(QPolygon(points));

}
/*
void Widget::drawSinus(QPainter *qp)
{
  QPen pen;
  pen.setColor(Qt::blue);
  pen.setWidth(3);
  qp->setPen(pen);

  double x, y;
  QVector<QPoint> points;
  int xOrg = 400, yOrg = 300, xUnit = 50, yUnit = 100;

  qp->drawLine(xOrg, yOrg - 200, xOrg, yOrg + 200);
  qp->drawLine(xOrg - 350, yOrg, xOrg + 350, yOrg);

  pen.setColor(Qt::red);
  qp->setPen(pen);
  for (x = -3.14 * 2; x < +3.14 * 2; x += 0.01) {
      y = sin(x);
      points.append(QPoint(xOrg + x * xUnit, yOrg - y * yUnit));
  }
  qp->drawPolyline(QPolygon(points));

}
*/
void Widget::drawTransparent(QPainter *qp)
{
    Q_UNUSED(qp);
    QPainter painter(this);

    for (int i = 1; i <= 10; i++)
    {
        painter.setOpacity(i * 0.1);
        painter.fillRect(50 * i, 20, 40, 40, Qt::darkGray);
    }
}

void Widget::drawDonut(QPainter *qp)
{
    Q_UNUSED(qp);
    QPainter painter(this);

    painter.setPen(QPen(QBrush("#535353"), 0.5));
    painter.setRenderHint(QPainter::Antialiasing);

    int h = height();
    int w = width();

    painter.translate(QPoint(w / 2, h / 2)); //koordinat sistemini öteler

    for (qreal rot = 0; rot < 360.0; rot += 5.0 )
    {
//    for (qreal rot=0; rot < 10.0; rot+=5.0 ) {
        painter.drawEllipse(-125, -40, 250, 80);
        painter.rotate(5.0);//koordinat sistemini döndürür
    }
}

void Widget::drawShapes(QPainter *qp)
{

    Q_UNUSED(qp);
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QPen(QBrush("#888"), 1));
    painter.setBrush(QBrush(QColor("#888")));

    QPainterPath path1;

    path1.moveTo(5, 5);//currentPoint(5, 5)
    path1.cubicTo(40, 5,  50, 50,  99, 99);//c1(40, 5,),c2(50, 50), endPoint(99, 99)
    path1.cubicTo(5, 99,  50, 50,  5, 5);
    painter.drawPath(path1);

    painter.drawPie(130, 20, 90, 60, 30 * 16, 120 * 16); //start angle 30, span angle 120
    painter.drawChord(240, 30, 90, 60, 0, 16 * 180);
    painter.drawRoundRect(20, 120, 80, 50);

    QPolygon polygon({QPoint(130, 140), QPoint(180, 170), QPoint(180, 140),
                      QPoint(220, 110), QPoint(140, 100)});

    painter.drawPolygon(polygon);

    painter.drawRect(250, 110, 60, 60);

    QPointF baseline(20, 250);
    QFont font("Georgia", 55);
    QPainterPath path2;
    path2.addText(baseline, font, "Qt");
    painter.drawPath(path2);

    painter.drawEllipse(140, 200, 60, 60);
    painter.drawEllipse(240, 200, 90, 60);
}

void Widget::drawGradients(QPainter *qp)
{
    QLinearGradient grad1(0, 20, 0, 110);

    grad1.setColorAt(0.1, Qt::black);
    grad1.setColorAt(0.5, Qt::yellow);
    grad1.setColorAt(0.9, Qt::black);

    qp->fillRect(20, 20, 300, 90, grad1);

    QLinearGradient grad2(0, 55, 250, 0);

    grad2.setColorAt(0.2, Qt::black);
    grad2.setColorAt(0.5, Qt::red);
    grad2.setColorAt(0.8, Qt::black);

    qp->fillRect(20, 140, 300, 100, grad2);
}

void Widget::drawRadialGradient(QPainter *qp)
{
    int h = height();
    int w = width();

    QRadialGradient grad1(w / 2, h / 2, 80);

    grad1.setColorAt(0, QColor("#032E91"));
    grad1.setColorAt(0.3, Qt::white);
    grad1.setColorAt(1, QColor("#032E91"));

    qp->fillRect(0, 0, w, h, grad1);
}

void Widget::drawSimpleOperations(QPainter *qp)
{
    int h = height();
    int w = width();
    qp->translate(w / 2, h / 2);
    qp->scale(1.0, -1.0);
    QLine x_line(-50, 0, 50, 0);
    QLine y_line(0, -50, 0, 50);
    QLine y_line2(0, 0, 50 / sqrt(2), 50 / sqrt(2));
    QRect rect(0, 0, 20, 20);
    QPen pen;
    pen.setColor(Qt::blue);
    pen.setWidth(1);
    qp->setPen(pen);
    qp->drawLine(x_line);
    qp->drawLine(y_line);
    qp->drawLine(y_line2);
    qp->drawRect(rect);
    pen.setColor(Qt::red);
    qp->setPen(pen);
    qp->rotate(30);
    qp->scale(2, 2);
    qp->drawLine(x_line);
    qp->drawLine(y_line);
    qp->drawLine(y_line2);
    qp->drawRect(rect);
}

void Widget::drawRotatedText(QPainter *qp)
{
    Q_UNUSED(qp);
    QPainter painter(this);
    int w = 200;
    int h = 200;
    //use qpainter

    painter.setPen(QPen(Qt::blue, 1, Qt::DashLine));
    painter.drawRect(0, 0, w, h);
    painter.save();
    painter.translate(w / 2, h / 2);
    painter.rotate(45);
    painter.scale(0.5, -1.0);
    painter.setFont(QFont("Helvetica", 24));
    painter.setPen(QPen(Qt::black, 1));
    painter.drawText(20, 10, "Painter1");
    painter.restore();

    painter.save();
    painter.translate(20, h / 2);
    painter.rotate(90);
    painter.scale(0.5, -1.0);
    painter.setFont(QFont("Helvetica", 24));
    painter.setPen(QPen(Qt::black, 1));
    painter.drawText(20, 10, "Painter2");
    painter.restore();

    //Using QMatrix

    QTransform matrix;
    matrix.translate(w / 2, h / 2);
    matrix.rotate(-45);
    matrix.scale(0.5, 1.0);
    painter.setTransform(matrix);

    painter.setFont(QFont("Helvetica", 24));
    painter.setPen(QPen(Qt::black, 1));
    painter.drawText(20, 10, "Matrix1");

    matrix.reset();
    matrix.translate(20, h / 2);
    matrix.rotate(-90);
    matrix.scale(0.5, 1.0);
    painter.setTransform(matrix);
    painter.setFont(QFont("Helvetica", 24));
    painter.setPen(QPen(Qt::black, 1));
    painter.drawText(20, 10, "Matrix2");
}

void Widget::drawPixmap(QPainter *qp)
{
    QPixmap px(":/images/qtlogo.png");
    int w = width() / 2;
    int h = height() / 2;
    int pxw = px.size().width();
    int pxh = px.size().height();
    QRect rSrc(0, 0, pxw, pxh);
    QRect rDest(w, h, pxw, pxh);
    qp->setOpacity(0.7);
    qp->drawPixmap(rDest, px, rSrc);
}

