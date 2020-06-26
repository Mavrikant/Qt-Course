/*Scratchpadwidget.h*/
#ifndef SCRATCHPADWIDGET_H
#define SCRATCHPADWIDGET_H

#include <QtGui>
#include <QVector>
#include <QWidget>

class ScratchpadWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ScratchpadWidget(QWidget *parent = nullptr);
protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
private:
    bool m_drawFlag;
    QPolygon m_polyline;
    QVector<QPolygon> m_polylines;
};

#endif // SCRATCHPADWIDGET_H
